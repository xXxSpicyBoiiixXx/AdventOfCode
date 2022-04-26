#include <stdio.h> 
#include <stdlib.h>

int main() { 
	
    uint64_t power_consumption = 0;
    uint64_t gamma_rate = 0;
    uint64_t epislon_rate = 0;

    const unsigned MAX_LENGTH = 256; 

    char buffer_inline[MAX_LENGTH]; 

    FILE *in_file = fopen("input.txt", r); 
    FILE *out_file = fopen("answer.txt", w); 

    if(in_file == NULL) {
        printf("ERROR! COULD NOT OPEN INPUT FILE!\n"); 
        exit(1);
    }

    if(out_file == NULL) { 
        printf("ERROR! COULD NOT OPEN OUTPUT FILE\n"); 
        exit(1); 
    }

    while((fscanf(in_file, "%llu", buffer_inline, &i)) != EOF) {
        
    }


}
