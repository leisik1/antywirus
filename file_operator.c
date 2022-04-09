#define _GNU_SOURCE
#include <dirent.h> 
#include <stdio.h>
#include <string.h>


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


int main(void) {
  list_files("/home/dan/Desktop");
  // list_files(".");
  return(0);
}