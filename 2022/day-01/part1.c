#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdint.h>

int main() { 
    
   // uint64_t counter = 0;     
   // uint64_t max_weight = 0;
   // uint64_t temp_weight = 0;
    uint64_t file_values = 0; 
    
    struct stat sb; 

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 
    
    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(-1);
    } 

    if(stat("input.txt", &sb) == -1) { 
        printf("ERROR! Stat");
        exit(-1);
    } else {
        char *buf = malloc(sb.st_size+1);

        if(buf == NULL) { 
            printf("NOT ENOUGH MEM"); 
            exit(-1);
        }
    
    }
    
    fclose(in_file); 
    fclose(out_file);

    return 0;
}
