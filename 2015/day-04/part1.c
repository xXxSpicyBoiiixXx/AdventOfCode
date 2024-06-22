#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void compute_md5(const char *str, unsigned char *result) { 
    MD5_CTX md5_ctx;
    MD5_Init(&md5_ctx);
    MD5_Update(&md5_ctx, str, strlen(str));
    MD5_Final(result, &md5_ctx);
}

int main() { 


    // declaring file input/output
    FILE *in_file = fopen("input.txt", "r"); 
    FILE *out_file = fopen("answer-part1.txt", "w"); 

    // error checking for files
    if(in_file == NULL || out_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }
    
    // secret key
    // ckczppom
    
    const char *secret_key = "ckczppom"; 
    unsigned char md5_result[MD5_DIGEST_LENGTH];
    char combined[256];
    int number = 1;
    
    while(1) { 
        sprintf(combined, "%s%d", secret_key, number); 
        compute_md5(combined, md5_result);

        if(md5_result[0] == 0 && md5_result[1] == 0 && (md5_result[2] & 0xF0) == 0) { 
            break;
        }

        number++;
    }

    printf("the lowest number for the secret key '%s', is: %d\n", secret_key, number); 

    // closing files
    fclose(in_file);
    fclose(out_file); 
}

