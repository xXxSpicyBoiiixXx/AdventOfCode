#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() { 
    
    uint64_t life_support = 0; 
    uint64_t O2_rating[11]; // Oxygen rating
    uint64_t CO2_rating[11]; // Carbon Dioxide rating
    
    uint64_t bit_placement = 0; 

    uint64_t *binary_counter_holder; 

    binary_counter holder = (uint64_t *) calloc(, sizeof(uint64_t)); 

    

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part2.txt", "w"); 

    if(in_file == NULL) {
        printf("ERROR! COULD NOT OPEN INPUT FILE!\n"); 
        exit(1);
    }

    if(out_file == NULL) { 
        printf("ERROR! COULD NOT OPEN OUTPUT FILE\n"); 
        exit(1); 
    }

    fclose(in_file);
    fclose(out_file);

}
