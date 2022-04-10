#include <stdio.h>
#include <openssl/md5.h>
#include <string.h>

int count_hash(char *filename, char hash_text[]){
	
	unsigned char c[MD5_DIGEST_LENGTH];
    //char *filename="virus.txt";
    FILE *inFile = fopen(filename, "rb");
    MD5_CTX mdContext;
    unsigned char data[1024];

    if (inFile == NULL) {
        printf ("%s Doesn't exist.\n", filename);
        return 0;
    }

	int bytes;
    MD5_Init (&mdContext);
    while ((bytes = fread(data, 1, 1024, inFile)) != 0){
        MD5_Update(&mdContext, data, bytes);
	}

    MD5_Final(c,&mdContext);

	int j;
	for(j = 0; j < 16; ++j){
		sprintf(&hash_text[j*2], "%02x", (unsigned char) c[j]);
	}
    hash_text[strlen(hash_text)] = '\0';

	// int i;
    // for(i = 0; i < MD5_DIGEST_LENGTH; i++){
	// 	printf("%02x", c[i]);
	// } 

    // printf (" %s\n", filename);
    fclose (inFile);
    return 0;
}
