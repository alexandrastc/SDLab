#include "caesar.h"
#include <stdio.h> 
#include <string.h>
#include <stdbool.h>

char* remove_whitespace(char* input)
{
    char *output = input;
    int lengthSource = strlen(input);
    int i=0; 
    int j=0; 

    for (i=0, j=0; i<lengthSource; i++, j++){
        if(input[i] != ' '){
            output[j] = input[i];
        } else {
            j--;
        }
    }
    output[j] = '\0';
    return output;
}

void caesar_decrypt(int key, char* text)
{
    printf("Encrypted message: %s\n", text);

    if(key <= 0 || key > 26){
        printf("Key is not valid, please try again\n");
        return;
    }

    for (int i=0; text[i] != '\0'; i++){
        char letter = text[i];

        if(letter >= 'a' && letter <= 'z'){
            letter = letter - key;

            if (letter < 'a'){
                letter = letter + 'z' - 'a' + 1;
            }

            text[i] = letter;
        } else if (letter >= 'A' && letter <= 'Z'){
            letter = letter - key;

            if (letter < 'A'){
                letter = letter + 'Z' - 'A' + 1;
            }

            text[i] = letter;
        }

    }

    printf("Plaintext: %s\n", text);
}

void caesar_encrypt(int key, char* text)
{
    printf("Plaintext: %s\n", text);
 
    if(key <= 0 || key > 26 ){
        printf("Key is not valid, please try again\n");
        return ;
    }

    for (int i=0; text[i] != '\0'; i++){
        char letter = text[i];

        if(letter >= 'a' && letter <= 'z'){
            letter = letter + key;

            if (letter > 'z'){
                letter = letter - 'z' + 'a' - 1;
            }

            text[i] = letter;
        
        } else if (letter >= 'A' && letter <= 'Z'){
            letter = letter + key;

            if (letter > 'Z'){
                letter = letter - 'Z' + 'A' - 1;
            }
            
            text[i] = letter;
        } 
    }

    printf("Encrypted message: %s\n", remove_whitespace(text));
}