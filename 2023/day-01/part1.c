#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() { 
    
    char str[1000];
    int counter = 0; 

    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("answer-part1.txt", "w");

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Could not open file!\n");
        exit(-1);
    }
    
    while(fgets(str, 1000, in_file) != NULL) {
    
    for(int i = 0; str[i] != '\0'; i++) { 
        if(isdigit(str[i])) { 
            
            printf("%c", str[i]);
        }
    }

    printf("\n");

}
    fclose(in_file);
    fclose(out_file);

    return 0;
}
