#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() { 

// Coordinate object    
typedef struct {
    unsigned int x;
    unsigned int y;
} Coordinate; 

// Coordinate dynamic structure
typedef struct { 
    Coordinate *data; 
    size_t size;
    size_t capacity; 
} DynamicArray;

// Initializing array
void initArray(DynamicArray *arr, size_t initialCapacity) { 
    arr->data = (Coordinate *)malloc(initialCapacity * sizeof(Coordinate));
    arr->size = 0;
    arr->capacity = initialCapacity; 
}

// Inserting objects 
void insertArray(DynamicArray *arr, Coordinate element) { 
    if(arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = (Coordinate *)realloc(arr->data, arr->capacity * sizeof(Coordinate));
    }
    arr->data[arr->size++] = element; 
}

// Memory management
void freeArray(DynamicArray *arr) { 
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}   

bool isUnique(DynamicArray *arr, Coordinate element) { 
    for(size_t i = 0; i < arr->size; i++) {
        if(arr->data[i].x == element.x && arr->data[i].y == element.y) { 
            return true; // not unique 
        }
    }

    return false; // unique 
}

    int north;
    int east;
    int south;
    int west;
    int uniqueHouses = 0;
    
    unsigned int x_pos = 0;
    unsigned int y_pos = 0;
    
    char char_input; 

    DynamicArray coordinates; 
    initArray(&coordinates, 2); 
    Coordinate point; 
//    bool counter = 1; // starts at 1 to set it to true
    
    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }
    
    point.x = x_pos; 
    point.y = y_pos; 
//    printf("x_pos: %u", point.x);
//    printf("y_post: %u", point.y);
    insertArray(&coordinates, point);

// TODO: fix logic with new array logic.
    do { 
        char_input = fgetc(in_file); 
        if(char_input == '^') { 
            y_pos++;
            point.y = y_pos; 
            insertArray(&coordinates, point);
        } else if(char_input == '>') { 
            x_pos++;
            point.x = x_pos; 
            insertArray(&coordinates, point);
        } else if(char_input == '<') {
            x_pos--;
            point.x = x_pos;
            insertArray(&coordinates, point);
        } else if(char_input == 'v') { 
            y_pos--;
            point.y = y_pos;
            insertArray(&coordinates, point);
        } else {
            printf("Error reading file input");
            exit(-1);
        }

        if(isUnique(&coordinates, point) == false) {
            uniqueHouses++;
        } 
    } while(char_input != EOF);
    // closing files
    printf("Unique Houses: %i", uniqueHouses); 
    fclose(in_file);
    fclose(out_file); 
}

