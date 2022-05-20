#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() { 
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part2.txt", "w"); 

    if(in_file == NULL) {
        printf("ERROR! COULD NOT OPEN INPUT FILE!\n"); 
        exit(1);
    }

    if(out_file == NULL) { 
        printf("ERROR! COULD NOT OPEN OUTPUT FILE\n"); 
        exit(1); 
    }

    fclose(in_file);
    fclose(out_file);

}
