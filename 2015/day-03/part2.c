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
    
    int turn = 1; 

    char char_input; 

    DynamicArray coordinates; 
    initArray(&coordinates, 2); 
    Coordinate point_santa = {0, 0}; 
    Coordinate point_robo = {0, 0};

    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part2.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }

    insertArray(&coordinates, point_santa);

    do { 
        char_input = fgetc(in_file); 
        if(turn%2 == 1) { 
            turn++;
        if(char_input == '^') { 
            y_pos++;
            point_santa.y = y_pos; 
        } else if(char_input == '>') { 
            x_pos++;
            point_santa.x = x_pos; 
        } else if(char_input == '<') {
            x_pos--;
            point_santa.x = x_pos;
        } else if(char_input == 'v') { 
            y_pos--;
            point_santa.y = y_pos;
        } else {
            
        } 
        } else {
            turn++;
           if(char_input == '^') { 
            y_pos++;
            point_robo.y = y_pos; 
        } else if(char_input == '>') { 
            x_pos++;
            point_robo.x = x_pos; 
        } else if(char_input == '<') {
            x_pos--;
            point_robo.x = x_pos;
        } else if(char_input == 'v') { 
            y_pos--;
            point_robo.y = y_pos;
        } else { 

        }
        }

        if(isUnique(&coordinates, point_santa)) {
            insertArray(&coordinates, point_santa);
            uniqueHouses++;
        }
        
        if(isUnique(&coordinates, point_robo)) { 
            insertArray(&coordinates, point_robo);
            uniqueHouses++;
        }
    } while(char_input != EOF);

    // closing files
    printf("Unique Houses: %i\n", uniqueHouses); 

    freeArray(&coordinates);     
    fclose(in_file);
    fclose(out_file); 
}

