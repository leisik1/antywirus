#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hasher.h"
#include "database_operator.h"
#include "file_operator.h"


#define COLS 33
#define PATHS 4096


int main()
{
    
    char *baza[COLS];
    int baza_size;
	char hash[32];
    printf("weeee");
    get_from_base(baza, &baza_size);
    printf("weeee");
    //char *filename="/home/dan/Desktop/antywirus/.git/hooks/pre-merge-commit.sample";
    char *filename="/home/dan/Desktop/virus.txt";

    printf("weeee");
    scan_files("/home/dan/Desktop");
    // count_hash(filename,hash);
    // printf("%s", hash);

    // printoutarray(baza);

    // printf("%d", baza_size);

    

    // for(int i=0; i < baza_size; i++){
    //     //puts(hash);
    //     printf("%s", baza[i]);
    //     // printf("%zu",strlen(baza[i]));
    //     if(!strncmp(hash, baza[i],32)){
    //         printf("WIRUS!!!\n");
    //     }
    // }
    

    
    // printf("Hashes: %s %s %s %s", baza[0], baza[1], baza[2], baza[3]);
	return 0;
}