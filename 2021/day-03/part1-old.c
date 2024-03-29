#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h> 

int main() { 
	
    uint64_t power_consumption = 0;
    uint64_t gamma_rate[11]; // Most common bit
    uint64_t epsilon_rate[11]; // Least common bit, the inverse of gamma_rate 
    uint64_t bit_placement = 0;
    uint64_t *binary_counter_ones; 
    uint64_t *binary_counter_zeros;

    uint64_t gamma_rate_dec = 0; 
    uint64_t epsilon_rate_dec = 0; 
     
    int binary_code; 
    
    binary_counter_ones = (uint64_t *) calloc(11, sizeof(uint64_t)); 
    binary_counter_zeros = (uint64_t *) calloc(11, sizeof(uint64_t)); 
    
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    if(in_file == NULL) {
        printf("ERROR! COULD NOT OPEN INPUT FILE!\n"); 
        exit(1);
    }

    if(out_file == NULL) { 
        printf("ERROR! COULD NOT OPEN OUTPUT FILE\n"); 
        exit(1); 
    }

    while((binary_code = fgetc(in_file)) != EOF) {

            if(binary_code == '1') { 
                binary_counter_ones[bit_placement] += 1;
            }

            if(binary_code == '0') { 
                binary_counter_zeros[bit_placement] += 1; 
            }
        bit_placement++; 

        if(bit_placement == 13) {
            bit_placement = 0;   
        }
    }

    bit_placement = 11;

    printf("GAMMA BINARY RATE: ");    
    fprintf(out_file, "GAMMA BINARY RATE: "); 
    
     
    for(int j = 0; j < 12; j++) { 
       if(binary_counter_ones[j] > binary_counter_zeros[j]) {
            gamma_rate[j] = 1;
            epsilon_rate[j] = 0; 
            gamma_rate_dec = gamma_rate_dec + pow(2, bit_placement);
       
        } 
       
       else { 
            gamma_rate[j] = 0;
            epsilon_rate[j] = 1;
            epsilon_rate_dec = epsilon_rate_dec + pow(2, bit_placement);  
       }


       
     /*  if(gamma_rate[j] == 1) { 
            gamma_rate_dec = gamma_rate_dec + pow(2, bit_placement); 
       }

       if(epsilon_rate[j] == 1) { 
            epsilon_rate_dec  = epsilon_rate_dec + pow(2, bit_placement); 
       } */
/*
       if(j == 1) { 
            printf("GAMMA BINARY RATE: "); 
            fprintf(out_file, "GAMMA BINARY RATE: "); 
       } 
*/
            if(j == 11) {

            printf("%lu", gamma_rate[j]); 
            fprintf(out_file, "%lu", gamma_rate[j]); 


            printf("\n");
            fprintf(out_file, "\n");
            printf("EPSILON BINARY RATE: "); 
            fprintf(out_file, "EPSILON BINARY RATE: "); 

            for(int k = 0; k < 12; k++) { 
                printf("%lu", epsilon_rate[k]); 
                fprintf(out_file, "%lu", epsilon_rate[k]);
            }
       }

       bit_placement--; 
    }

    power_consumption = gamma_rate_dec * epsilon_rate_dec; 
    
   /*
    int j = 0; 
    int k = 0;

    while(j < 12) { 
        
        if(j == 1) {
             printf("GAMMA BINARY RATE: ");    
             fprintf(out_file, "GAMMA BINARY RATE: "); 
        }

        printf("%lu", gamma_rate[j]); 
        fprintf(out_file, "%lu", gamma_rate[j]);

        if(j == 11) { 
             printf("\n");
             fprintf(out_file, "\n");
             printf("EPSILON BINARY RATE: ");
             fprintf(out_file, "EPSILON BINARY RATE: "); 
             
             while(k < 12) { 
                printf("%lu", epsilon_rate[k]); 
                fprintf(out_file, "%lu", epsilon_rate[k]);
                k++;
             }

        }

        j++;

    } */
    /*for(int j = 0; j < 12; j++) { 
        printf("%lu", gamma_rate[j]); 
        fprintf(out_file, "%lu", gamma_rate[j]);    
    }
   
    printf("\n"); 
    fprintf(out_file, "\n"); 
   
    printf("EPSILON BINARY RATE: "); 
    fprintf(out_file, "EPSILON BINARY RATE: ");

    for(int k = 0; k < 12; k++) { 
        printf("%lu", epsilon_rate[k]); 
        fprintf(out_file, "%lu", epsilon_rate[k]);
    }*/

    printf("\nGAMMA RATE: %lu", gamma_rate_dec); 
    printf("\n"); 
    printf("EPSILON RATE: %lu", epsilon_rate_dec);
    printf("\n");
    printf("POWER CONSUMPTION: %lu", power_consumption); 
    printf("\n");

    fprintf(out_file, "\nGAMMA RATE: %lu", gamma_rate_dec); 
    fprintf(out_file, "\n"); 
    fprintf(out_file, "EPSILON RATE: %lu", epsilon_rate_dec);
    fprintf(out_file, "\n"); 
    fprintf(out_file, "POWER CONSUMPTION: %lu", power_consumption); 
    fprintf(out_file, "\n"); 

    fclose(in_file);
    fclose(out_file);

    free(binary_counter_ones);
    free(binary_counter_zeros);

}
