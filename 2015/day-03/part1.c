#include <stdio.h>
#include <stdlib.h>

int main() { 

// Coordinate object    
typedef struct {
    int x;
    int y;
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

int isUnique(DynamicArray *arr, Coordinate element) { 
    for(size_t i = 0; i < arr->size; i++) {
        if(arr->data[i].x == element.x && arr->data[i].y == element.y) { 
            return 0; // not unique 
        }
    }

    return 1; // unique 
}

    int uniqueHouses = 1;
    
    int x_pos = 0;
    int y_pos = 0;
    
    char char_input; 

    DynamicArray coordinates; 
    initArray(&coordinates, 2); 
    Coordinate point = {0, 0}; 
//    bool counter = 1; // starts at 1 to set it to true
    
    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }
    
//    point.x = x_pos; 
//    point.y = y_pos; 
//    printf("x_pos: %u", point.x);
//    printf("y_post: %u", point.y);
    insertArray(&coordinates, point);

// TODO: fix logic with new array logic.
    do { 
        char_input = fgetc(in_file); 
//        printf("Current character: %c\n", char_input);
        if(char_input == '^') { 
            y_pos++;
            point.y = y_pos; 
//            printf("x_pos: %i, y_pos: %i\n", point.x, point.y);
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
            printf("End of File has been reached.");
        }
       
        if(isUnique(&coordinates, point)) {
            insertArray(&coordinates, point);
            uniqueHouses++;
        } 
    } while(char_input != EOF);
    // closing files
    printf("Unique Houses: %i", uniqueHouses); 

    freeArray(&coordinates);     
    fclose(in_file);
    fclose(out_file); 
}

