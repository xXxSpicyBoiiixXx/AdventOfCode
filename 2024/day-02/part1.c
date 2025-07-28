#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    int arr1_data[1000];
    
    int i = 0;

    int bufferLength = 1024;
    char buffer[bufferLength];

    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("answers-1.txt", "w");

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Could not open file!\n");
        exit(-1);
    }
    
    while((ch != '\n') && (ch != EOF)) { 
                
    }
    
    printf("Total distance %i: ", totalDistance);
    fprintf(out_file, "Total distance %i: ", totalDistance);

    fclose(in_file);
    fclose(out_file);

    return 0;
}
