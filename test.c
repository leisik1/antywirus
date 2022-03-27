#include <stdio.h>
#include "hasher.h"

void skip(char *msg){
	puts(msg + 6);
}



int main()
{
	char hash[32];
    char *filename="virus.txt";
    count_hash(filename,hash);
    puts(hash);
	return 0;
}