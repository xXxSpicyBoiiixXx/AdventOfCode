#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main() { 

    /* Unused variables */
    //int file_counter_size = 0; 
    //char c; // throw away value for now 
    char forward[] = "forward ";
    char up[] = "up ";
    char down[] = "down "; 

    uint64_t counter_forward = 0; 
    uint64_t counter_depth = 0; 

    const unsigned MAX_LENGTH = 256; 
    char buffer[MAX_LENGTH]; 

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer.txt", "w"); 

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(1); 
    }

   // fscanf(in_file, "%s%i", buffer, i); 

    /* Checking if fgets command works */ 
    while(fgets(buffer, MAX_LENGTH, in_file)) {  

        char buffer_inline[MAX_LENGTH]; 
        
       // fscanf(in_file, "%s%d", buffer, i); 
        for(int i = 0; i < 10; i++) {

         fscanf(in_file, "%s%d", buffer_inline, &i); 

         if(strcmp(buffer, strcat(forward, strcat(i, "\n"))) == 0) { 
                counter_forward++; 
            }
            if(strcmp(buffer, "down i") == 0) { 
                counter_depth++; 
            }
            if(strcmp(buffer, "up i") == 0) { 
                counter_depth--;
            }

        }
    }

    printf("Horizontal: %llu\n", counter_forward);
    printf("Depth: %llu\n", counter_depth);  

    fclose(in_file); 
    fclose(out_file); 



}
