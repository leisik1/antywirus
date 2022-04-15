#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hasher.h"
#include "database_operator.h"
#include "file_operator.h"
#include "quarantine_cipher.h"


#define COLS 33
#define PATHS 4096


int main()
{

    char *baza[COLS];
    int baza_size;
	char hash[32];
    get_from_base(baza, &baza_size);
    
    char *filename="/home/dan/Desktop/virus.txt";
    char file_path[4096];
    char dest_path[4096];
    int stat;

    int out = 1;
    int operation;
    while (out == 1)
    {
        printf("Hi! I'm your antivirus! What you want to do today?\n");
        printf("1. Scan a file\n");
        printf("2. Scan a directory\n");
        printf("3. Scan everything\n");
        printf("4. Decrypt a file from quarantine\n");
        printf("5. Quit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%s", file_path);
            count_hash(file_path,hash);
            printf("%s\n",hash);

            for(int i=0; i < baza_size; i++){
                if(!strncmp(hash, baza[i],32)){
                    printf("%s\n",baza[i]);
                    printf("\nWIRUS!!!\n");
                    encrypt(file_path);
                }
            }
            printf("Scann done.\n");
            break;

        case 2:
            scanf("%s", file_path);
            stat = scan_files(file_path);
            printf("Scann done. %d viruses found!\n", stat);
            stat = 0;
            break;

        case 3:
            printf("Scanning...");
            stat = scan_files("/");
            printf("Done. %d filviruses found!", stat);
            break;

        case 4:
            printf("Input a path to file from a quarantine DB");
            scanf("%s", file_path);
            printf("Input a path to destination from a quarantine DB");
            scanf("%s", dest_path);
            decrypt(file_path,dest_path);
            printf("Done.");
            break;
        
        case 5:
            out = 0;
            break;
        
        default:
            printf("You propably made a mistake, please try again!");
            break;
        }
    }
    
    
	return 0;
}