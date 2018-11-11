#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "caesar.h"

void vigenere_encrypt(char* key, char* text)
{
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int shift;

    for(int i = 0, j = 0; i < textLen; i++, j++){

        if (j >= keyLen){
            j = 0;
        }

        char keyValue = key[j]; 
 
        if (!isalpha(text[i])){
            j = (j - 1);
        }  
 
        if ((keyValue >= 'A') && (keyValue <=  'Z')){
            keyValue = (keyValue -  'A');
        }
 
        if ((keyValue >= 'a') && (keyValue <= 'z')){
            keyValue = (keyValue - 'a');
        }
 
        shift = (text[i] + keyValue);
 
        if (isupper(text[i]) && (shift > 'Z')){
            shift = (shift - 26);
        }
 
        if (islower(text[i]) && (shift > 'z')){
            shift = (shift - 26);
        }
 
        if (isalpha(text[i])){
            printf("%c", shift);
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n");
}

void vigenere_decrypt(char* key, char* text)
{ 
    remove_whitespace(text);
    int textLen = strlen(text), keyLen = strlen(key), i = 0, j = 0;
    char newKey[textLen], decryptedMsg[textLen];
    
    for(i = 0, j = 0; i < textLen; ++i, ++j){
        if(j == keyLen){
            j = 0;
        }
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';

    for(i = 0; i < textLen; i++){
        decryptedMsg[i] = (((text[i] - newKey[i]) + 26) % 26) + 'A';
    }

    decryptedMsg[i] = '\0';
    
    printf("%s\n", decryptedMsg);
}