#include <stdio.h>
#include <stdlib.h>

int main() { 
         
        char char_input; 
        unsigned long floor_level = 0;

        // declaring file input/output
        FILE *in_file = fopen("input.txt", "r"); 
        FILE *out_file = fopen("answer-part1.txt", "w"); 
        
        // error checking for files
        if(in_file == NULL || out_file == NULL) { 
            printf("Error! Count not open file!\n"); 
            exit(-1);             
        }
        
        // reading from input.txt
        do { 
            char_input = fgetc(in_file);
            if(char_input == '(') { 
                floor_level++;    
            }
            if(char_input == ')') { 
                floor_level--;
            }
            //printf("%c", char_input);
            
        } while(char_input != EOF);
        
        printf("Santa is on level: %lu", floor_level);
        fprintf(out_file, "Santa is on level: %lu", floor_level); 

        // closing files
        fclose(in_file);
        fclose(out_file); 
}

