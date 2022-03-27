#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int get_from_base()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("vulnerability_db.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

    return 0;
}

int main(){
    // char[] line_taken
    get_from_base();
    return 0;
}