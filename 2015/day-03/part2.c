#include <stdio.h>
#include <stdlib.h>

int main() { 

    int length = 0; 
    int width = 0; 
    int height = 0;
    int volume = 0;

    int shortest_side = 0;
    int total_paper = 0;

    int a;
    int b;
    int c;

    char buffer[10000];

    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part2.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }

    while(fgets(buffer, sizeof(buffer), in_file) != NULL) {
        if(sscanf(buffer, "%dx%dx%d", &length, &width, &height) == 3) { 

            // Test Printing
            //printf("Read dimensions: %d, %d, %d\n", length, width, height); 
            volume = length * width * height;

            a = length * width;
            b = width * height; 
            c = height * length; 

            if(a <= b && a <= c) { 
             shortest_side = length + length + width + width;   
            } else if(b <= a && b <= c) { 
             shortest_side = width + width + height + height;
            } else {
             shortest_side = height + height + length + length;
            }
            
        }else {
                printf("Error has occured for comparisons between l, w, h at line %s\n", buffer);
            }

        //int square_feet_total = 2 * (a + b + c) + shortest_side; 
        //total_paper = square_feet_total + total_paper;
        total_paper = total_paper + volume + shortest_side;
        //printf("%d, %d, %d, shortest perm: %i, volume: %i, total paper: %i\n", length, width, height, shortest_side, volume, total_paper);
    } 

    printf("Total paper needed is %i square feet", total_paper); 
    fprintf(out_file, "Total paper needed is %i square feet", total_paper);

    // closing files
    fclose(in_file);
    fclose(out_file); 
}

