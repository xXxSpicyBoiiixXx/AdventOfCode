#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

int main() { 
    
    uint64_t power_consumption = 0;
    uint64_t gamma_rate[11];
    uint64_t epsilon_rate[11];
    
    uint64_t bit_placement = 0;
    uint64_t *binary_counter_ones;
    uint64_t *binary_counter_zeros;

    uint64_t gamma_rate_dec = 0;
    uint64_t epsilon_rate_dec = 0;

    int binary_code;

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! COULD NOT OPEN INPUT AND/OR OUTPUT FILE\n");
        exit(1);
    }

    while((binary_code = fgetc(in_file)) != EOF) { 
        
        if(binary_code == '1') {
                binary_counter_ones[bit_placement] += 1;
        } else {
                binary_counter_zeros[bit_placement] += 1;
        } bit_placement++;
        
        if(bit_placement == 13) {
            bit_placement = 0;
        }
        
    } 

    bit_placement = 11; 

    for(int j = 0; j < 12; j++) {
        if(binary_counter_ones[j] > binary_counter_zeros[j]) {
            gamma_rate[j] = 1;
            epsilon_rate[j] = 0;
            gamma_rate_dec = gamma_rate_dec + pow(2, bit_placement);
        } else {
            gamma_rate[j] = 0;
            epsilon_rate[j] = 1;
            epsilon_rate_dec = epsilon_rate_dec + pow(2, bit_placement);
        } 

       bit_placement--; 

    } 

    power_consumption = gamma_rate_dec * epsilon_rate_dec;


    fclose(in_file);
    fclose(out_file);


}
