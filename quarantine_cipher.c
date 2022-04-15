#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <string.h>
#include <time.h>
#include <assert.h>

unsigned char indata[AES_BLOCK_SIZE];
unsigned char outdata[AES_BLOCK_SIZE];
unsigned char decryptdata[AES_BLOCK_SIZE];
unsigned char userkey[] = "\x09\x8F\x6B\xCD\x46\x21\xD3\x73\xCA\xDE\x4E\x83\x26\x27\xB4\xF6";
unsigned char IV[] = "\x0A\x91\x72\x71\x6A\xE6\x42\x84\x09\x88\x5B\x8B\x82\x9C\xCB\x05";

AES_KEY key;

int get_random() {
    srand(time(0)); 
    return rand();
}

void encrypt(char *file_to_encrypt) {

    char desired_name[4096] = {0};

    strcat(desired_name, "/home/dan/Desktop/antywirus/quarantine/");

    // char * desired_name = "/home/dan/Desktop/antywirus/quarantine/";
    char * tld = strrchr(file_to_encrypt, '/');
    char * file_name = tld + 1;

	int n = get_random();
    char num_text[100] = {0};

    sprintf(num_text,"%d",n);

    strcat(desired_name,num_text);
    strcat(desired_name,file_name);
    printf("%s", desired_name);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    assert(strftime(s, sizeof(s), "%c", tm));

    FILE* database = fopen("/home/dan/Desktop/antywirus/quarantine_db.txt","a");
    fprintf(database, "File destination: %s, File name in quarantine: %s, Date: %s\n",file_to_encrypt,desired_name,s);

    AES_set_encrypt_key(userkey, 128, &key);
    FILE *ifp, *ofp;
    ifp = fopen(file_to_encrypt, "r+");
    ofp = fopen(desired_name, "w+");
    int postion = 0;
    int bytes_read, bytes_write;
    while (1) {
        unsigned char ivec[AES_BLOCK_SIZE];
        memcpy(ivec, IV, AES_BLOCK_SIZE);
        bytes_read = fread(indata, 1, AES_BLOCK_SIZE, ifp);
        AES_cfb128_encrypt(indata, outdata, bytes_read, &key, ivec, &postion, AES_ENCRYPT);
        bytes_write = fwrite(outdata, 1, bytes_read, ofp);
        if (bytes_read < AES_BLOCK_SIZE)
            break;
    }
    fclose(ifp);
    fclose(ofp);
    fclose(database);
}

void decrypt(char *file_to_decrypt, char *desired_name) {
    FILE *ifp, *ofp;
    ifp = fopen(file_to_decrypt, "r+");
    ofp = fopen(desired_name, "w+");
    int postion = 0;
    int bytes_read, bytes_write;
    while (1) {
        unsigned char ivec[AES_BLOCK_SIZE];
        memcpy(ivec, IV, AES_BLOCK_SIZE);
        bytes_read = fread(outdata, 1, AES_BLOCK_SIZE, ifp);
        AES_cfb128_encrypt(outdata, decryptdata, bytes_read, &key, ivec, &postion, AES_DECRYPT);
        bytes_write = fwrite(decryptdata, 1, bytes_read, ofp);
        if (bytes_read < AES_BLOCK_SIZE)
            break;
    }
    fclose(ifp);
    fclose(ofp);
}



// int main(void) {
    
//     encrypt("/home/dan/Desktop/virus.txt");
//     //decrypt();
// }