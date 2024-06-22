#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[256];
    int i;
    int vowel_count;
    int double_letter;
    int num_nice_strings = 0;

    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r");
    // error checking for files
    if (in_file == NULL) {
        printf("Error! Could not open file!\n");
        exit(-1);
    }

    while (fgets(line, sizeof(line), in_file)) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        vowel_count = 0;
        double_letter = 0;
        int is_naughty = 0;

        for (i = 0; i < strlen(line); i++) {
            char ch = line[i];

            // Check for disallowed substrings
            if ((ch == 'a' && line[i+1] == 'b') ||
                (ch == 'c' && line[i+1] == 'd') ||
                (ch == 'p' && line[i+1] == 'q') ||
                (ch == 'x' && line[i+1] == 'y')) {
                is_naughty = 1;
                break;
            }

            // Count vowels
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel_count++;
            }

            // Check for double letters
            if (i > 0 && ch == line[i-1]) {
                double_letter = 1;
            }
        }

        // Check if the string is nice
        if (!is_naughty && vowel_count >= 3 && double_letter) {
            num_nice_strings++;
        }
    }

    printf("Number of nice strings: %d\n", num_nice_strings);
    // closing files
    fclose(in_file);

    return 0;
}

