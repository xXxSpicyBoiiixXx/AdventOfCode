#include <stdio.h>
#include <stdlib.h> 

int main() { 
    
    int counter = 0; 
    
    uint64_t max_weight = 0;
    uint64_t temp_weight = 0; 

    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 
    
    char ch; 

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Count not open file!\n"); 
        exit(-1);
    }
    /*
    do { 
        ch = fgetc(in_file);
        printf("%c", ch); 

    } while(ch != EOF); 
    */


    fclose(in_file); 
    fclose(out_file);

    return 0;
}
