#include <stdio.h>
#include <stdlib.h>

int main() { 
        
        int data[2000];  
        int counter = 0; 

        FILE *in_file = fopen("input.txt", "r"); 

        FILE *out_file = fopen("answer-part1.txt", "w"); 

        if(in_file == NULL || out_file == NULL) { 
            printf("Error! Count not open file!\n"); 
            exit(-1);             
        }
        
        for(int i = 0; i < 2000; i++)   { 
            fscanf(in_file, "%i", &data[i]); 
        }

        for(int i = 0; i < 2000; i++) { 
            if(data[i] < data[i+1]) { 
                counter++; 
            } 
        }
        
        // We need to subtract the first measurement since we count it as the intital point.    

        fprintf(out_file, "The number of increases are in the inputted data are: %i", counter--); 

        printf("Your answer is the file answer-part1.txt"); 

        fclose(in_file);
        fclose(out_file); 
        
}

