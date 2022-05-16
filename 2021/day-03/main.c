#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main() { 
	
    uint64_t power_consumption = 0;
    uint64_t gamma_rate[12]; // Most common bit
    uint64_t epsilon_rate[12]; // Least common bit, the inverse of gamma_rate 
    uint64_t bit_placement = 0;
    uint64_t *binary_counter_ones; 
    uint64_t *binary_counter_zeros; 
    int binary_code; 
    
    binary_counter_ones = (uint64_t *) calloc(11, sizeof(uint64_t)); 
    binary_counter_zeros = (uint64_t *) calloc(11, sizeof(uint64_t)); 
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
//        printf("%c", binary_code); 
        
        //printf("%s", &binary_code);  
            

            if(binary_code == '1') { 
                binary_counter_ones[bit_placement] += 1;
            }

            if(binary_code == '0') { 
                /*if(binary_counter[bit_placement] > 0) {
                   binary_counter[bit_placement] =  binary_counter[bit_placement] - 1; 
                } else { 
                    binary_counter[bit_placement] = 0;
                } */ 
                binary_counter_zeros[bit_placement] += 1; 
            }
            /*    if(binary_counter[bit_placement] == 0) { 
                    binary_counter[bit_placement] = 0; 
                }*/
//          printf("%llu \n", binary_counter[bit_placement]);    
/*
            if(binary_code == 1) { 
                binary_counter[bit_placement] += 1; 
            }          

            if(binary_code == 0) { 
                if(binary_counter[bit_placement] > 0) { 
                    binary_counter[bit_placement] -= 1;
                } else { 
                    binary_counter[bit_placement] = 0; 
                }
            }

        //printf("%llu\n", binary_counter[bit_placement]);
        
        printf("%llu \n", binary_counter[bit_placement]);
        
        */
          
        bit_placement++; 

        if(bit_placement == 13) {
            bit_placement = 0;   
        }
    }
   
    /*
    gamma_rate = binary_counter[0]; 
    printf("%llu", gamma_rate); 
    */ 
    for(int j = 0; j < 11; j++) { 
       if(binary_counter_ones[j] > binary_counter_zeros[j]) {
       gamma_rate[j] = 1;
       epsilon_rate[j] = 0; } else { 
       gamma_rate[j] = 0;
       epsilon_rate[j] = 1;  
       }
       printf("%llu", gamma_rate[j]); 
      // printf("EPSILON BINARY RATE: %llu", epsilon_rate[j]); 
    }
    fclose(in_file);
    fclose(out_file);

    free(binary_counter_ones);
    free(binary_counter_zeros);

}
