#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hasher.h"
#include "database_operator.h"

#define ROWS 100
#define COLS 33


int main(int argc, char *argv[])
{
    char baza[ROWS][COLS];
	char hash[32];
    get_from_base(baza);
    //char *filename="/home/dan/Desktop/antywirus/.git/hooks/pre-merge-commit.sample";
    // char *filename="../super_grozny_wirus.txt";
    // count_hash(filename,hash);
    // puts(hash);

    // printoutarray(baza);

    
    printf("Hashes: %s %s %s %s", baza[0], baza[1], baza[2], baza[3]);
	return 0;
}