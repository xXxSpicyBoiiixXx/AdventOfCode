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

    insertArray(&coordinates, point);

    do { 
        char_input = fgetc(in_file); 
        if(char_input == '^') { 
            y_pos++;
            point.y = y_pos; 
        } else if(char_input == '>') { 
            x_pos++;
            point.x = x_pos; 
        } else if(char_input == '<') {
            x_pos--;
            point.x = x_pos;
        } else if(char_input == 'v') { 
            y_pos--;
            point.y = y_pos;
        } else {
            //printf("End of File has been reached.");
        }

        if(isUnique(&coordinates, point)) {
            insertArray(&coordinates, point);
            uniqueHouses++;
        }
    } while(char_input != EOF);

    // closing files
    printf("Unique Houses: %i\n", uniqueHouses); 

}

