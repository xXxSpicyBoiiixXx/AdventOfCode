#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main() { 
	
    uint64_t power_consumption = 0;
    uint64_t gamma_rate = 0; // Most common bit
    uint64_t epislon_rate = 0; // Least common bit, the inverse of gamma_rate 
    uint64_t bit_placement = 0;
    char binary_code; 

    //const unsigned MAX_LENGTH = 256; 

    //char buffer_inline[MAX_LENGTH]; 

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer.txt", "w"); 

    if(in_file == NULL) {
        printf("ERROR! COULD NOT OPEN INPUT FILE!\n"); 
        exit(1);
    }

    if(out_file == NULL) { 
        printf("ERROR! COULD NOT OPEN OUTPUT FILE\n"); 
        exit(1); 
    }

    while((binary_code = fgetc(in_file)) != EOF) {
        //printf("%c", binary_code);
        if(binary_code != "/n") { 
            
        }
    }

    fclose(in_file);
    fclose(out_file);


}
