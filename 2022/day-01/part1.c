#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main() { 
    
    int counter = 0; 
    
    int max_weight = 0;
    int temp_weight = 0; 
    
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 
    
    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(-1);
    }

    
    
    fprintf(out_file, "The strongest boi can lift: %d", max_weight); 
    printf("The strongest boi can life: %d", max_weight); 
    printf("\nThis is written in answer-part1.txt"); 

    fclose(in_file); 
    fclose(out_file);

    return 0;
}
