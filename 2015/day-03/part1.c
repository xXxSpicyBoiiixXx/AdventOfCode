#include <stdio.h>
#include <stdlib.h>

int main() { 

typedef struct {
    int x;
    int y;
} Coordinate; 

    int north;
    int east;
    int south;
    int west;

    unsigned int x_pos = 0;
    unsigned int y_pos = 0;
    
    bool counter = 1; // starts at 1 to set it to true
    
    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }

    do { 
        char_input = fgetc(in_file); 
        if(char_input == '^') { 
            y_pos++;
        } else if(char_input == '>') { 
            x_pos++;
        } else if(char_input == '<') {
            x_pos--;
        } else if(char_input == 'v') { 
            y_pos--;
        } else {
            printf("Error reading file input");
            exit(-1);
        }
    }
    // closing files
    fclose(in_file);
    fclose(out_file); 
}

