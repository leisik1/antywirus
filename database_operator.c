#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"


#define COLS 33

int get_from_base(char *baza[], int* baza_size)
{
    FILE * fp = fopen("vulnerability_db.txt", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL)
        exit(EXIT_FAILURE);

    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        baza[i]= (char*)malloc(strlen(line)*sizeof(char));
        strcpy(baza[i], line);
        i++;
    }
    *baza_size = i;
    // printf("Hashes: %s %s %s %s", baza[0], baza[1], baza[2], baza[3]);
    // printf("%p", &baza);

    fclose(fp);
    if (line)
        free(line);
    // exit(EXIT_SUCCESS);

    return 0;
}

// int get_and_compare()
// {
//     FILE * fp;
//     char * line = NULL;
//     size_t len = 0;
//     ssize_t read;

//     fp = fopen("vulnerability_db.txt", "r");
//     if (fp == NULL)
//         exit(EXIT_FAILURE);

//     while ((read = getline(&line, &len, fp)) != -1) {
        
//         if(stringcompare(hash, read)) // Tutaj trzeba bedzie dac hashe
//             printf("They are equal");
//         else 
//             printf("They are NOT equal");
//     }

//     fclose(fp);
//     if (line)
//         free(line);
//     exit(EXIT_SUCCESS);

//     return 0;

// }
