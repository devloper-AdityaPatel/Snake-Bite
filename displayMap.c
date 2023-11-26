#include <stdio.h>
#include "object.h" // importing object definition file

/* ----bacgroudn color macros---- */
#define red "\033[32m"
#define BUFF_SIZE 25600
void displayMap(char *filename)
{

    FILE *fptr; // file pointer init

    fptr = fopen(filename, "r"); // opening metadata file in read only mode
    if (fptr == NULL)
    {
        printf("file is not found\n");
        return;
    }
    else
    {
        if (setvbuf(fptr, NULL, _IOFBF, BUFF_SIZE) != 0)
        {
            printf("buffer allocation failed\n");
        }
        else
        {
            object metadata; // metadata : this contain (row_size, col_size , obj_count)

            // reading metadata from file
            // file pointer will move to next block
            fread(&metadata, sizeof(object), 1, fptr);

            // object variable declare to hold object
            object obj;

            // reading first object from file
            fread(&obj, sizeof(object), 1, fptr);
            for (int i = 0; i < metadata.row; i++)
            {
                for (int j = 0; j < metadata.col; j++)
                {

                    // condition to object(row,col) with position of (i,j)
                    if (obj.row == i && obj.col == j)
                    {

                        // switch to map objectcode with object
                        switch (obj.objCode)
                        {
                        case 0:
                            printf("%c", 'P');
                            // reading next object
                            fread(&obj, sizeof(object), 1, fptr);
                            break;
                        case 1:
                            printf("%c", '~');
                            // reading next object
                            fread(&obj, sizeof(object), 1, fptr);
                            break;
                        case 2:
                            printf("%c", '|');
                            // reading next object
                            fread(&obj, sizeof(object), 1, fptr);
                            break;
                        case 3:
                            printf("%c", '-');
                            // reading next object
                            fread(&obj, sizeof(object), 1, fptr);
                            break;
                        case 4:
                            printf("%c", '*');
                            // reading next object
                            fread(&obj, sizeof(object), 1, fptr);
                            break;
                        case 5:
                            printf("%c", '*');
                            // reading next object
                            fread(&obj, sizeof(object), 1, fptr);
                            break;
                        case 6:
                            printf("%c", 'X');
                            // reading next object
                            fread(&obj, sizeof(object), 1, fptr);
                            break;
                        }
                    }
                    else
                    {
                        // if (i,j) is empty, printing space there
                        printf("%c", ' ');
                    }
                }
                // inserting newline after end of row
                printf("\n");
            }
        }
    }
}

int main(int argc, char *argv[])
{
    displayMap(argv[1]);

    return 0;
}