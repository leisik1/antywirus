#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hasher.h"
#include "database_operator.h"


#define COLS 33
#define PATHS 4096


int main()
{
    char *baza[COLS];
	char hash[32];
    // get_from_base(baza);
    //char *filename="/home/dan/Desktop/antywirus/.git/hooks/pre-merge-commit.sample";
    char *filename="/home/dan/Desktop/antywirus/.git/objects/7d/855c4ef81f89778d5c6578957510af55bb7914";
    count_hash(filename,hash);
    printf("%s", hash);

    // printoutarray(baza);

    
    // count_hash(filename, hash);
    // printf("%zu",strlen(hash));
    // for(int i=0; i < 4; i++){
    //     //puts(hash);
    //     printf("%s", baza[i]);
    //     printf("%zu",strlen(baza[i]));
    //     if(!strncmp(hash, baza[i],32)){
    //         printf("WIRUS!!!\n");
    //     }
    // }
    // printf("%p", &baza);

    
    // printf("Hashes: %s %s %s %s", baza[0], baza[1], baza[2], baza[3]);
	return 0;
}