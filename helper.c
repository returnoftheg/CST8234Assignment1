/*
  helper.c
  RegistrationSystem

  Created by Mohamed El-Halawani on 2019-09-19.
*/

#include "helper.h"

/* used to print any 1D integer array */
void printIntArray(int array[], size_t length) {
    int index ;
    printf("[");
    for (index = 0; index < length; index++) {
        printf("%d", array[index]);
        if (index < length - 1 ){
            printf(", ");
        }
    }
    printf("]\n");
}

/* used to print any 1D char array */
void printStringArray(char *array[], size_t length) {
    int index ;
    printf("[");
    for (index = 0; index < length; index++) {
        printf("%s", array[index]);
        if (index < length - 1 ){
            printf(", ");
        }
    }
    printf("]\n");
}

/*
 Used to initialize any integer 2d array.
 This is imporat so that the complier correctly reserve the needed space in memory.
 You won't be able to use these arrays otherwise.
 
 Usage:
 int array[rowSize][columnSize];
 initilaize2DArray((int *)array, rowSize, columnSize);
 */
void initilaize2DArray(int *array, size_t rowSize, size_t columnSize) {
    int row, column;
    for (row = 0; row < rowSize; row++) {
        for (column = 0; column < columnSize; column++) {
            *(array + row * columnSize + column) = 0;
        }
    }
}

/*
 Convience method to print integer 2D arrays
 
 Usage:
 int array[rowSize][columnSize];
 print2DArray((int *)array, rowSize, columnSize);
 */
void print2DArray(int *array, size_t rowSize, size_t columnSize) {
    int row, column;
    printf("[ ");
    for (row = 0; row < rowSize; row++) {
        printf("[ ");
        for (column = 0; column < columnSize; column++) {
            printf("%d", *(array + row * columnSize + column));
            if (column < columnSize - 1 ){
                printf(", ");
            }
        }
        printf(" ]");
        if (row < rowSize - 1 ){
            printf(", ");
        }
    }
    printf(" ]\n");
    
}
