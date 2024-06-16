#include <stdio.h>
#include <stdlib.h>

int main() { 


    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }


    // closing files
    fclose(in_file);
    fclose(out_file); 
}

