/*
 * Name: Md Ali 
 * Description: Advent of Code day 1 part 2
 * Date: 12/15/2023
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to extract the calibration value from a line
int extractValue(const char *line) {
    
    char *digitWords[] = {"one", "two", "three", "four", "five",
                        "six", "seven", "eight", "nine"};
    char digits[10];
    //char firstDigit;
    //char lastDigit;
    int count = 0; 

    for(int i = 0; line[i] != '\0'; i++) { 
        if(isdigit(line[i]) || isalpha(line[i])) {
            digits[count++] = line[i];

            //Adding this here to handle buffer overflow errors
            if(count == sizeof(digits) - 1) { 
                digits[count] = '\0';
                break;
            }
        } else { 
            digits[count] = '\0';
            count = 0;

            for(int j = 0; j < 9; j++) { 
                if(strcmp(digits, digitWords[j]) == 0) {
                    digits[0] = '0' + (j + 1); 
                    count = 1; 
                    break;
                }
            }
        }
    }

    // Combination of the first and last digits
    // Returns that value in the return statement
    /*firstDigit = digits[0];
    lastDigit = digits[count - 1];
    */
    return (digits[0] - '0') * 10 + (digits[count - 1] - '0');
}

int correctedValue(FILE *inputFile) {
    
    int totalSum = 0;
    char line[1000];

    while(fgets(line, sizeof(line), inputFile) != NULL) { 
        totalSum += extractValue(line);
    }

    return totalSum;
}

int main() {
    
    int totalCalibrationValue;
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("answers.txt", "w");
    
    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Could not open file!\n");
        exit(-1);
    }

    totalCalibrationValue = correctedValue(in_file); 

    printf("Corrected Calibration Value: %d\n", totalCalibrationValue); 
    printf("Your results have been save to answers.txt\n\n");
    fprintf(out_file, "Part 2 Answer\n"); 
    fprintf(out_file, "-------------\n");
    fprintf(out_file, "Corrected Calibration Value: %d\n", totalCalibrationValue);
    fprintf(out_file, "-------------\n\n");      

    fclose(in_file);
    fclose(out_file);

    return 0;
}
