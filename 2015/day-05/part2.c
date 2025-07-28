#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 

    char line[256];
    int num_nice_string = 0;

    FILE = *in_file = fopen("input.txt", "r");

    if(in_file == NULL) {
        printf("Error! Could not open file!\n"); 
        exit(-1);
    }

    while(fgets(line, sizeof(line), in_file)) {
    int pairing_count = 0;
    int repearing_count = 0;

    size_t len = strlen(line); 
    
    if(line[len - 1] == '\n') { 
        line[len - 1] = '\0';
        len--;
    }

    for(int i = 0; i < len; i++) { 
        char ch = line[i];


    }

    }
}

