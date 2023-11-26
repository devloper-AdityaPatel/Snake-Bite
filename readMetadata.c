#include <stdio.h>
# include <stdlib.h>

#include "object.h"
#define BUFF_SIZE 25600

void readMetadata(char *filname)
{
    FILE *fptr; // file pointer init

    fptr = fopen(filname, "r"); // opening metadata file in read only mode
    if (fptr == NULL)
    {
        printf("file is not found\n");
        return;
    }
    else
    {
        char*buffer = (char*)malloc(2048*sizeof(char));
        if (setvbuf(fptr, buffer, _IOFBF, BUFF_SIZE) != 0)
        {
            printf("buffer allocation failed\n");
        }
        else
        {
            object metadata;
            fread(&metadata, sizeof(object), 1, fptr);

            // print(row_size,col_size,object_count)
            // file pointer will move to next block of structure
            printf("%d\t%d\t%d\n", metadata.row, metadata.col, metadata.objCode);

            int i = 1, obj_count = metadata.objCode; // i = iterator , obj_count : no of total objects in map

            object obj;
            while (i <= obj_count)
            {
                fread(&obj, sizeof(object), 1, fptr);
                printf("%d\t%d\t%d\n", obj.row, obj.col, obj.objCode);
                i++;
            }

            fclose(fptr); // closing file
        }
    }

    return;
}
int main(int agrc, char *argv[])
{

    readMetadata(argv[1]);

    return 0;
}