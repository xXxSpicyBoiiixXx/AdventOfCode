#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdint.h>

int main() { 
    
    const unsigned MAX_LENGTH = 256; 

    char buffer_inline[MAX_LENGTH]; 
    int c[1000];

    uint64_t counter = 0;     
    uint64_t max_weight = 0;
    uint64_t temp_weight = 0;
    uint64_t file_values = 0; 
    uint64_t data[2000];

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 
    
    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(-1);
    } 
    
    fscanf(in_file, "%[^\n]", c);
    printf("Data from the file:\n%i", c); 
    
    fclose(in_file); 
    fclose(out_file);
    
    return 0;
   
}
