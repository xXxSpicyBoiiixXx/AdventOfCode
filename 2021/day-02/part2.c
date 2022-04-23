#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main() { 

    uint64_t i = 0; 

    uint64_t counter_forward = 0; 
    uint64_t counter_depth = 0; 
    uint64_t aim = 0; 

    const unsigned MAX_LENGTH = 256; 

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part2.txt", "w"); 

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(1); 
    }
   
    char buffer_inline[MAX_LENGTH]; 
    
    while((fscanf(in_file, "%s%llu", buffer_inline, &i)) != EOF) {  
        //printf("amount: %llu\n", i);         
        // test correct input 
        // printf("movement: %s spacing: %d\n", buffer_inline, i); 
        
        if(strcmp(buffer_inline, "forward") == 0) { 
            counter_forward += i;
        }

        if(strcmp(buffer_inline, "up") == 0) { 
            counter_depth -= i;
        }

        if(strcmp(buffer_inline, "down") == 0) { 
            counter_depth += i;
        }
    }
    
    fprintf(out_file, "Below is the position of the horizontal and depth of the submarine\n"); 
    fprintf(out_file, "Horizontal: %llu\n", counter_forward); 
    fprintf(out_file, "Depth: %llu\n", counter_depth); 
    fprintf(out_file, "Multiplier: %llu\n", counter_forward * counter_depth); 

    printf("Below is the result of our submarine movements, in additon we have the same data in the file 'answer.txt'\n");
    printf("Horizontal: %llu\n", counter_forward);
    printf("Depth: %llu\n", counter_depth); 
    printf("Multiplier: %llu\n", counter_forward * counter_depth);  
    
    
    fclose(in_file); 
    fclose(out_file); 



}
