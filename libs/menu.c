#include <stdio.h>
#include <string.h>
#include "menu.h"

#define LSIZ 128
#define RSIZ 10

char line[RSIZ][LSIZ];
int i = 0;
int tot = 0;

void readMenuFile(char *filename)
{
    FILE *fp;

    fp = fopen(filename, "r");

    while(fgets(line[i], LSIZ, fp)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;

    fclose(fp);
}

void printMenu()
{
    for(i = 0; i < tot; ++i)
    {
        printf("%s\n", line[i]);
    }
}