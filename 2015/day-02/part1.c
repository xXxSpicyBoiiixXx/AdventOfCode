#include <stdio.h>
#include <stdlib.h>

int main() { 

    int length = 0; 
    int width = 0; 
    int height = 0;

    int shortest_side = 0;
    int total_paper = 0;
    
    int a;
    int b;
    int c;

    char buffer[10000];

    //int surface_area = (2*length*width) + (2*width*height) + (2*height*length);  

    // int square_feet_total = surface_area + shortest_side; 

    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }

    while(fgets(buffer, sizeof(buffer), in_file) != NULL) {
        if(sscanf(buffer, "%dx%dx%d", &length, &width, &height) == 3) { 
            
            // Test Printing
            //printf("Read dimensions: %d, %d, %d\n", length, width, height); 
            a = length * width;
            b = width * height; 
            c = height * length; 
            
            if(a < b && a < c) { 
                shortest_side = a; 
            } else if(b < c && b < a) { 
                shortest_side = b;
            } else if(c < b && c < a) { 
                shortest_side = c; 
            } else if(a == b || b == c || a == c) { 
                if(a < b) { 
                    shortest_side = a;
                } else if(b < c) { 
                    shortest_side = b;
                } else {
                    shortest_side = c;
                }
            }

            } else {
                printf("Error has occured for comparisons between l, w, h at line %s\n", buffer);
            }

            int square_feet_total = 2 * (a + b + c) + shortest_side; 
            total_paper = square_feet_total + total_paper;
        } 

    printf("Total paper needed is %i square feet", total_paper); 
    fprintf(out_file, "Total paper needed is %i square feet", total_paper);

    // closing files
    fclose(in_file);
    fclose(out_file); 
}

