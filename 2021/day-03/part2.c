#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() { 
    
    uint64_t life_support = 0; 
    uint64_t O2_rating[11]; // Oxygen rating
    uint64_t CO2_rating[11]; // Carbon Dioxide rating
    
    uint64_t bit_placement = 0; 
    
    uint64_t one_counter = 0; 
    uint64_t zero_counter = 0;
    
    int binary_code;
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

    while((binary_code = fgetc(in_file)) != EOF) { 
        
        if(binary_code == '1' && bit_placement == 0) { 
           one_counter++; 
        }

        if(binary_code == '0' && bit_placement == 0) { 
           zero_counter++;  
        }
        bit_placement++; 

        if(bit_placement == 13) { 
            bit_placement = 0;
        }
    }

    printf("The number of ones in placement one: %llu", one_counter);      
    printf("\n");
    printf("The number of zeros in placement one: %llu", zero_counter);
    printf("\n");

    one_counter = 0; 
    zero_counter = 0; 
    rewind(FILE *in_file);

    while((binary_code = fgetc(in_file)) != EOF) { 
        
        if(binary_code == '1' && bit_placement == 1) { 
           one_counter++; 
        }

        if(binary_code == '0' && bit_placement == 1) { 
           zero_counter++;  
        }
        bit_placement++; 

        if(bit_placement == 13) { 
            bit_placement = 0;
        }
    }

    printf("The number of ones in placement two: %llu", one_counter);      
    printf("\n");
    printf("The number of zeros in placement twp: %llu", zero_counter);
    printf("\n");


    fclose(in_file);
    fclose(out_file);

}
