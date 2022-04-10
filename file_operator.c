#define _GNU_SOURCE
#include <dirent.h> 
#include <stdio.h>
#include <string.h>
#include "hasher.h"
#include "database_operator.h"


void list_files(char* dirname){
  DIR* dir = opendir(dirname);
  if (dir == NULL){
    return;
  }

  // && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0

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
      // snprintf(path, 4097, "%s/%s", dirname, entity->d_name);

      // printf("%s\n", path);
      strcat(path, dirname);
      strcat(path, "/");
      strcat(path, entity->d_name);
      list_files(path);
    }
    entity = readdir(dir);
  }
  closedir(dir);
}


void scan_files(char* dirname){
  DIR* dir = opendir(dirname);
  if (dir == NULL){
    return;
  }

  // && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0

  // printf("Reading files in: %s\n", dirname);

  struct dirent* entity;
  entity = readdir(dir);
  while (entity != NULL) {
    if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") && entity->d_type != DT_DIR){
      char path_to_scan[4097] = {0};
      char hash[33];

      strcat(path_to_scan, dirname);
      strcat(path_to_scan, "/");
      strcat(path_to_scan, entity->d_name);
      printf("%s\n", path_to_scan);

      count_hash(path_to_scan, hash);
      printf("%s\n\n", hash);

      // printf("%hhd %s/%s\n", entity->d_type, dirname, entity->d_name);
    }
        

    if(entity->d_type == DT_DIR && (strcmp(entity->d_name, ".") != 0) && (strcmp(entity->d_name, "..") != 0)){
      char path[4097] = {0};

      if (strcmp(entity->d_name, ".") == 0)
        continue;
      if (strcmp(entity->d_name, "..") == 0)
        continue;
      // snprintf(path, 4097, "%s/%s", dirname, entity->d_name);

      // printf("%s\n", path);
      strcat(path, dirname);
      strcat(path, "/");
      strcat(path, entity->d_name);
      scan_files(path);
    }
    entity = readdir(dir);
  }
  closedir(dir);
}

int main(){
  char dirname[] = "/home/dan/Desktop";
  scan_files(dirname);
  return 0;
}