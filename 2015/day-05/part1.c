#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 

    char line[256];
    int i;
    int vowel_count;
    int num_nice_string = 0;

    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    // error checking for files
    if(in_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }
    
    while(fgets(line, sizeof(line), in_file)) { 
        //        Test print
        //        printf("%s", line); 
        //
        vowel_count = 0;

        for(i = 0; i < strlen(line); i++) { 
            char ch = line[i];
            
            if((ch == 'a' && line[i+1] == 'b') ||
               (ch == 'c' && line[i+1] == 'd') ||
               (ch == 'p' && line[i+1] == 'q') || 
               (ch == 'x' && line[i+1] == 'y')) 
            {
                break;
            }
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') { 
            vowel_count++; 
            }

            if(vowel_count == 3) {
                num_nice_string++;
                break;
            }

            if(ch == line[i+1]) { 
                num_nice_string++;
                break;
               }
        }

    }    
        printf("Number of nice strings: %i\n", num_nice_string);    
    // closing files
    fclose(in_file);
}

