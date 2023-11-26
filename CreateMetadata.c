#include <stdio.h>
#include <stdlib.h>

#include "object.h" // importing object file

#define BUFF_SIZE 25600

object readobjectfromscreen(object ob);

object readobjectfromscreen(object ob)
{
    printf("Enter (row ,col , object code) : ");
    scanf(" %d %d %d", &ob.row, &ob.col, &ob.objCode);
    return ob;
}

void createMetadata(int row_size, int col_size, int hurdle_count)
{

    object metadata; // variable to write single object in file
    char filename[32];

    printf("Enter file name [extension : mapname.meta] : ");
    scanf("%s", filename); // filename from user

    FILE *fptr;
    fptr = fopen(filename, "w"); // opening file in write mode

    if (fptr == NULL)
    {
        printf("%s opening is failed", filename);
        return;
    }
    else
    {   char *buffer = (char*)malloc(512*sizeof(char));
        if (setvbuf(fptr, buffer, _IOFBF, BUFF_SIZE) != 0)
        {
            printf("buffer allocation failed\n");
        }
        else
        {
            // height of map in terms of index from 0 to (row_size-1)
            metadata.row = row_size;
            // width of  map in terms of index from 0 to (col_size-1)
            metadata.col = col_size;
            // total number of objects in map
            metadata.objCode = 2 * (row_size + col_size) + hurdle_count - 4 + 1;

            // writing (row_size,col_size,object_count) in file
            fwrite(&metadata, sizeof(object), 1, fptr);

            /* hurdle array contains the hurdles location, player location, snake location,Target location */
            object *hurdle_array;
            hurdle_array = (object *)malloc(hurdle_count * sizeof(object));

            int i = 0;  // iterator for while loop
            object obj; // object container to hold temporarily the objects

            /*  while loop to read hurdles location one by on from user from keyboard
             *  After reading the hurdle , pushed them into hurdle array*/
            while (i < hurdle_count)
            {

                // reading object location (<row> <col> <object code> , see <object.h> file for more info)
                obj = readobjectfromscreen(obj);

                // writing in file
                hurdle_array[i] = obj;

                i++; // incrementing the iterator
            }        // end of while loop

            // iterator k is declared and initialized to zero to access the hurdle array objects sequential inside for loop
            int k = 0;

            // outer for loop
            for (int i = 0; i < row_size; i++)
            {
                // inner forloop
                for (int j = 0; j < col_size; j++)
                {
                    // assigning row to temproary object
                    obj.row = i;
                    obj.col = j;

                    // condition to check corners of map
                    if ((i == 0 && j == 0) || (i == 0 && j == col_size - 1) || (i == row_size - 1 && j == 0) || (i == row_size - 1 && j == col_size - 1))
                    {
                        // object code : 4 (*)
                        obj.objCode = 4;
                        // writing in file
                        fwrite(&obj, sizeof(object), 1, fptr);
                    }
                    else if ((i == 0 || i == row_size - 1) && (j > 0 && j < col_size - 1))
                    {
                        obj.objCode = 3;
                        fwrite(&obj, sizeof(object), 1, fptr);
                    }
                    else if ((j == 0 || j == col_size - 1) && (i > 0 && i < row_size - 1))
                    {
                        obj.objCode = 2;
                        fwrite(&obj, sizeof(object), 1, fptr);
                    }
                    else if (hurdle_array[k].row == i && hurdle_array[k].col == j)
                    {
                        obj.objCode = hurdle_array[k].objCode;
                        k++; // incrementing iterator of hurddle array
                        fwrite(&obj, sizeof(object), 1, fptr);
                    }
                }
            }
            // closing file
            fclose(fptr);
            printf("%s is successfully created", filename);
            return;
        }
    }
}

int main()
{
    int row_size, col_size, hurdle_count;
    printf("enter row size : ");
    scanf(" %d", &row_size);
    printf("row size :%d\n", row_size);
    printf("enter col size : ");
    scanf(" %d", &col_size);
    printf("col size :%d\n", col_size);
    printf("enter total number of hurdles : ");
    scanf(" %d", &hurdle_count);
    createMetadata(row_size, col_size, hurdle_count);
    return 0;
}


