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
    
    uint64_t *binary_counter_O2; 
    uint64_t *binary_counter_CO2; 
    
    binary_counter_O2 = (uint64_t *) calloc(11, sizeof(uint64_t));
    binary_counter_CO2 = (uint64_t *) calloc(11, sizeof(uint64_t)); 

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

    uint64_t significant_bit = NULL; 

    for(int i = 0; i < 13; i++) { 
       bit_placement = 0;    
    while((binary_code = fgetc(in_file)) != EOF) { 
       
        if(binary_code == '1' && bit_placement == i) { 
           one_counter++; 
        }

        if(binary_code == '0' && bit_placement == i) { 
           zero_counter++;  
        }
    
        bit_placement++; 

        if(bit_placement == 13) { 
            bit_placement = 0;
        }
    }

    bit_placement = i;
// Comparison for one and zeros and then conditional to increase bit placement"? 
    if(one_counter >= zero_counter) { 
        significant_bit += '1'; 
        binary_counter_O2[bit_placement] = 1; 
        binary_counter_CO2[bit_placement] = 0;  
    } else { 
        significant_bit += '0'; 
        binary_counter_O2[bit_placement] = 0; 
        binary_counter_CO2[bit_placement] = 1; 
    }

    rewind(in_file);
    one_counter = 0;
    zero_counter = 0;
}
/*    printf("The number of ones in placement one: %llu", one_counter);      
    printf("\n");
    printf("The number of zeros in placement one: %llu", zero_counter);
    printf("\n");
  */

for(int j = 0; j < 12; j++) { 
    printf("%llu", binary_counter_O2[j]); 
}

printf("\n");

for(int j = 0; j < 12; j++) {
    printf("%llu", binary_counter_CO2[j]);
}

printf("\n");

for(int j = 0; j < 12; j++) { 
    printf("%llu", significant_bit); 
}
    fclose(in_file);
    fclose(out_file);

}
