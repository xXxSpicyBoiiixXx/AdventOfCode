#include <stdio.h>
#include <stdlib.h> 

int main() { 
    
    int file_counter_size = 0; 
    char c; // throw away value for now 

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer.txt", "w"); 

    if(in_file = NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(1); 
    }

    for(c = getc(in_file); c != EOF; c = getc(in_file)) { 
        if(c == '\n') { 
            file_counter_size++: 
        }
    }
    
    fclose(in_file); 
    fclose(out_file); 

    printf("The file has %d line", file_counter_size); 


}
