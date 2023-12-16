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
    int firstDigit = -1;
    int lastDigit = -1; 

    // Finding the first digit
    for(int i = 0; line[i] != '\0'; i++) { 
        if(isdigit(line[i])) {
            firstDigit = line[i] - '0';
            break;
        }
    }

    // Finding the last digit
    for(int i = 0; line[i] != '\0'; i++) { 
        if(isdigit(line[i])) { 
            lastDigit = line[i] - '0';
        }
    }

    // Combinig the first and last digit
    int calibrationValue = firstDigit * 10 + lastDigit;
    return calibrationValue;
}

int main() {
    char line[1000];
    int totalCalibrationValue = 0;
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("answers.txt", "w");

    if(in_file == NULL || out_file == NULL) { 
        printf("ERROR! Could not open file!\n");
        exit(-1);
    }

    while(fgets(line, sizeof(line), in_file) != NULL) {
        totalCalibrationValue += extractValue(line);    
    }

    printf("Total Calibration Value: %d\n", totalCalibrationValue); 
    printf("Your results have been save to answers.txt\n\n");
    fprintf(out_file, "Part 1 Answer\n"); 
    fprintf(out_file, "-------------\n");
    fprintf(out_file, "Total Calibration Value: %d\n", totalCalibrationValue);
    fprintf(out_file, "-------------\n\n");      

    fclose(in_file);
    fclose(out_file);

    return 0;
}
