#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char EOL = '\n';

#define MWIDTH = 13;
#define MHEIGHT = 1000; 

int main() { 
    
    uint64_t width, height, ii, jj;
    float array[MWIDTH][MHEIGHT];
    
    uint64_t life_support = 0; 
    uint64_t O2_rating = 0; // Oxygen rating
    uint64_t CO2_rating = 0; // Carbon Dioxide rating
    
    uint64_t bit_placement = 0; 
    
    uint64_t one_counter = 0; 
    uint64_t zero_counter = 0;
    
    uint64_t *binary_counter_O2; 
    uint64_t *binary_counter_CO2; 
    
    binary_counter_O2 = (uint64_t *) calloc(11, sizeof(uint64_t));
    binary_counter_CO2 = (uint64_t *) calloc(11, sizeof(uint64_t)); 

    int binary_code;
    int comparison; 
    int bit_check_O2;
    int bit_check_CO2;

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


/*
    for(int i = 0; i < 13; i++) { 
       bit_placement = 0; 
       bit_check_O2 = 0; 
       bit_check_CO2 = 0;
       comparison = 0;     
    while((binary_code = fgetc(in_file)) != EOF) { 
        
        if(i != 0) { 
            
            for(comparison = 0; comparison < i; comparison++) { 
                if(binary_code == binary_counter_O2[comparison]) { 
                  bit_check_O2++;   
                } 
                if(binary_code == binary_counter_CO2[comparison]) { 
                  bit_check_CO2++;   
                }
                else { 
                    // skip the line here
                   //(fgetc(in_file) == "\n");  
                   break;
                }
            }

            if((bit_check_O2 + bit_check_CO2) != comparison) { 
                // skip the line here
                //fgets(in_file); 
                break;
            }
        } 

        if((bit_check_O2 + bit_check_CO2) == comparison) {
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
    }

    bit_placement = i;
// Comparison for one and zeros and then conditional to increase bit placement"? 
    if(one_counter >= zero_counter) { 
        binary_counter_O2[bit_placement] = 1; 
        binary_counter_CO2[bit_placement] = 0;  
    } if(zero_counter > one_counter) { 
        binary_counter_O2[bit_placement] = 0; 
        binary_counter_CO2[bit_placement] = 1; 
         }

    rewind(in_file);
    one_counter = 0;
    zero_counter = 0;
}
for(int j = 0; j < 12; j++) { 
    printf("%llu", binary_counter_O2[j]); 
}

printf("\n");

for(int j = 0; j < 12; j++) {
    printf("%llu", binary_counter_CO2[j]);
}

printf("\n");

for(int j = 11; j >= 0; j--) { 
    
    if(binary_counter_O2[j] == 1) { 
        O2_rating = O2_rating + pow(2, j); 
    } 

    if(binary_counter_CO2[j] == 1) { 
        CO2_rating = CO2_rating + pow(2, j);
    }
}

printf("O2 Rating: %llu", O2_rating); 
printf("\n");
printf("CO2 Rating: %llu", CO2_rating); 
printf("\n");

life_support = O2_rating * CO2_rating; 

printf("LIFE SUPPORT: %llu", life_support); 
printf("\n");
*/
    fclose(in_file);
    fclose(out_file);

    free(binary_counter_O2);
    free(binary_counter_CO2); 

}
