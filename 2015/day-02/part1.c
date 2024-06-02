#include <stdio.h>
#include <stdlib.h>

int main() { 
        
        int length = 0; 
        int width = 0; 
        int height = 0;
        
        int surface_area = (2*length*width) + (2*width*height) + (2*height*length);  
        
        int numberArray[2]; 
        int i;

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

