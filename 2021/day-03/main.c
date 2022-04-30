#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main() { 
	
    uint64_t power_consumption = 0;
    uint64_t gamma_rate[11]; // Most common bit
    uint64_t epislon_rate = 0; // Least common bit, the inverse of gamma_rate 
    uint64_t bit_placement = 0;
    uint64_t binary_counter[11] = {0}; 
    char binary_code = malloc(1000 * sizeof(char)); 

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
        //printf("%c", binary_code) 
        
        //printf("%s", &binary_code); 
        
       // if((strcmp(&binary_code, "1") == 0 || strcmp(&binary_code, "0") == 0)  && bit_placement < 12) { 
            
            if(strcmp(binary_code, "1") == 0) { 
                binary_counter[bit_placement] += 1;
            }

            if(strcmp(binary_code, "0") == 0) { 
                if(binary_counter[bit_placement] > 0) {
                    binary_counter[bit_placement] -= 1; 
                } 
               
                if(binary_counter[bit_placement] == 0) { 
                    binary_counter[bit_placement] = 0; 
                }
            } 
        

        //printf("%llu\n", binary_counter[bit_placement]);
        
        printf("%llu \n", binary_counter[bit_placement]);
        bit_placement++; 

        if(bit_placement == 12) { 
            bit_placement = 0; 
        }
    }
    for(int j = 0; j < 11; j++) { 
     //   gamma_rate[j] = binary_counter[j];
     //   printf("%llu \n", gamma_rate[j]); 
    }
    /*
    gamma_rate = binary_counter[0]; 
    printf("%llu", gamma_rate); */
    fclose(in_file);
    fclose(out_file);


}
