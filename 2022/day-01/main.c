#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main() { 
    
    int counter = 0; 
    
    int max_weight = 0;
    int temp_weight = 0; 
    
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 
    
    char ch;
    
    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(-1);
    }

    
    do { 
        ch = fgetc(in_file);
        //printf("%c", ch); 
        if(strcpy(&ch, NULL) == 0 && max_weight < temp_weight) { 
            max_weight = temp_weight; 
            counter = 0; 
            temp_weight = 0;
        }

        counter = atoi(&ch); 
        temp_weight = temp_weight + counter; 

    } while(ch != EOF); 
   
    fprintf(out_file, "The strongest boi can lift: %d", max_weight); 
    printf("The strongest boi can life: %d", max_weight); 
    printf("\nThis is written in answer-part1.txt"); 

    fclose(in_file); 
    fclose(out_file);

    return 0;
}
