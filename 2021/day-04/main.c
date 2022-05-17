#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() { 

    char c[1000];
    uint64_t *drawing_numbers; 
    
    // drawing_numbers = (uint64_t *) calloc
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer.txt", "w"); 

    if(in_file == NULL) { 
        printf("ERROR! COULD NOT OPEN INPUT FILE!\n"); 
        exit(1);
    }

    if(out_file == NULL) { 
        printf("ERROR! COUNT NOT OPEN OUTPUT FILE!\n");
        exit(1);
    }

    fscanf(in_file, "%[^\n]", c);
    printf("Data from the file:\n%s", c);
    
    fclose(in_file); 
    fclose(out_file); 
}         
