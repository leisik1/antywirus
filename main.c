#include <stdio.h>
#include "hasher.h"

void skip(char *msg){
	puts(msg + 6);
}



int main()
{
	char hash[32];
    char *filename="/home/dan/Desktop/antywirus/.git/hooks/pre-merge-commit.sample";
    count_hash(filename,hash);
    puts(hash);
	return 0;
}