#define _GNU_SOURCE
#include <dirent.h> 
#include <stdio.h>
#include <string.h>
#include "hasher.h"
#include "database_operator.h"
#include "quarantine_cipher.h"


struct Results
{
  int scan_count;
  int virus_count;
};

void list_files(char* dirname){
  DIR* dir = opendir(dirname);
  if (dir == NULL){
    return;
  }


  printf("Reading files in: %s\n", dirname);

  struct dirent* entity;
  entity = readdir(dir);
  while (entity != NULL) {
    if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") && entity->d_type != DT_DIR)
        printf("%hhd %s/%s\n", entity->d_type, dirname, entity->d_name);

    if(entity->d_type == DT_DIR && (strcmp(entity->d_name, ".") != 0) && (strcmp(entity->d_name, "..") != 0)){
      char path[4097] = {0};

      if (strcmp(entity->d_name, ".") == 0)
        continue;
      if (strcmp(entity->d_name, "..") == 0)
        continue;

      strcat(path, dirname);
      strcat(path, "/");
      strcat(path, entity->d_name);
      list_files(path);
    }
    entity = readdir(dir);
  }
  closedir(dir);
}


int scan_files(char* dirname){

  char *baza[COLS];
  int baza_size;
  get_from_base(baza, &baza_size);

  DIR* dir = opendir(dirname);
  if (dir == NULL){
    return 0;
  }

  int counter = 0;


  struct dirent* entity;
  entity = readdir(dir);
  while (entity != NULL) {

    if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") && entity->d_type != DT_CHR && entity->d_type != DT_BLK && entity->d_type != DT_LNK  && entity->d_type != DT_DIR){
      char path_to_scan[4097] = {0};
      char hash[33];

      strcat(path_to_scan, dirname);
      strcat(path_to_scan, "/");
      strcat(path_to_scan, entity->d_name);

      count_hash(path_to_scan, hash);

      for(int i=0; i < baza_size; i++){
        if(!strncmp(hash, baza[i],32)){
            printf("\nWIRUS!!!\n");
            printf("%s", path_to_scan);
            encrypt(path_to_scan);
        }
    }
    counter++;
    }

    if(entity->d_type == DT_DIR && (strcmp(entity->d_name, "per_cpu") != 0 && strcmp(entity->d_name, ".") != 0 && (strcmp(entity->d_name, "..") != 0))){
      char path[4097] = {0};

      strcat(path, dirname);
      strcat(path, "/");
      strcat(path, entity->d_name);
      scan_files(path);
    }
    entity = readdir(dir);
  }
  closedir(dir);
  return counter;
}


