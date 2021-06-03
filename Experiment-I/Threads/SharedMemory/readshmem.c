#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "shared_memory.h"
// #include "shared_memory.c"

#define BLOCK_SIZE 4096

int main(int argc, char* argv[])
{
    if(argc!=1)
    {
        printf("Usage - %s //no args\n",argv[0]);
        return -1;
    }
    char *block=attach_memory_block(FILENAME,BLOCK_SIZE);
    if(block==NULL)
    {
        printf("Error: couldn't get block\n");
        return -1;
    }
    printf("Reading: \"%s\"\n",block);
    detach_memory_block(block);
    return 0;
}