#include <stdio.h>
#include <stdlib.h>

int main() { 

    char char_input; 
    unsigned int floor_level = 0;
    int position = 0; 

    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part2.txt", "w"); 

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
            position++;    
        }
        else if(char_input == ')') { 
            floor_level--;
            position++;
            
            if((int)floor_level < 0) { 
                printf("Entered basement at position: %i", position);
                fprintf(out_file, "Entered basement at position: %i", position);
                break; 
            }
        }
        else 
        {
            printf("Something is wrong here...");
        }

        //printf("%c", char_input);

    } while(char_input != EOF);

    // closing files
    fclose(in_file);
    fclose(out_file); 
}

