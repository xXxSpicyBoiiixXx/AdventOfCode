#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main() { 

    uint64_t i = 0; 

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part2.txt", "w"); 

    if(in_file == NULL) { 
        printf("ERROR! No input file detected!\n"); 
        exit(1); 
    }

    if(out_file == NULL) { 
        printf("ERROR! Could not create output file!\n");
        exit(1);
    }


   
    fclose(in_file); 
    fclose(out_file); 



}
