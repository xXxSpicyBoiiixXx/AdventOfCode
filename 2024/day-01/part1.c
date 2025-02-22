#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Adding test comment
int comp(const void* a, const void* b) 
{ 
    return (*(int*)a - *(int*)b);
}

int main() {

    int col1 = 0;
    int col2 = 0;

    int arr1[1000];
    int arr2[1000]; 
    
    int i = 0;
    int totalDistance = 0;

    int bufferLength = 1024;
    char buffer[bufferLength];

    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("answers-1.txt", "w");

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Could not open file!\n");
        exit(-1);
    }
    
    while(fgets(buffer, bufferLength, in_file)) { 
        if(2==sscanf(buffer, "%i %i", &col1, &col2)) { 
            //printf("a: %i   b: %i\b", col1, col2);
            arr1[i] = col1;
            arr2[i] = col2;
            i++;        
        }
    }

    qsort(arr1, 1000, sizeof(int), comp);
    qsort(arr2, 1000, sizeof(int), comp);

    for(int i = 0; i < 1000; i++) { 
        totalDistance += abs(arr1[i] - arr2[i]);
    }
    
    printf("Total distance %i: ", totalDistance);
    fprintf(out_file, "Total distance %i: ", totalDistance);

    fclose(in_file);
    fclose(out_file);

    return 0;
}
