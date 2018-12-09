#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"

#define TEXT_SIZE 1000
#define ALPHABET_SIZE 26

char* remove_whitespace(char* input);
int getPosition(char ch);
void printText(char* str);
char* beaufort_encrypt(char plainText[], char key[]);
char* beaufort_decrypt(char cipherText[], char key[]);
char* alphabet = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    char text[TEXT_SIZE];
    FILE *f;
    char charKey[100];
    
    f = fopen("input.txt", "r");
    
    if (f == NULL){
        printf("Error opening file");
        exit(1);
    }

    fscanf(f,"%[^\n]", text);
    remove_whitespace(text);

    printf("Original text: %s\n", text);

    printf("Key: ");
    scanf("%s", charKey);  

    char* cipherText = beaufort_encrypt(text, charKey);
    printf("Ciphertext: ");
    printText(cipherText);
    
    printf("\n");
    
    char* plainText = beaufort_decrypt(cipherText, charKey);
    printf("Decrypted plaintext: ");
    printText(plainText);

    printf("\n");

    return 0;
}


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

int getPosition(char ch)
{
    char* letter = strchr(alphabet, ch);
    return letter - alphabet;
}

void printText(char* str)
{
    int i = 0;
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }
}

char* beaufort_encrypt(char plainText[], char key[])
{
    int i = 0;
    int j = 0;
    char* cipherText  = (char *) malloc(sizeof(char) * strlen(plainText) -1);

    for(i = 0; i < strlen(plainText); i++)
    {
        int plainLetterIndex = getPosition(tolower(plainText[i]));
        int keyLetterIndex = getPosition(tolower(key[j]));

        int index = (keyLetterIndex - plainLetterIndex + ALPHABET_SIZE) % ALPHABET_SIZE;

        cipherText[i] = alphabet[index];
        j++;
        if(j == strlen(key))
        {
            j = 0;
        }

    }

    return cipherText;

}

char* beaufort_decrypt(char cipherText[], char key[])
{
    int i = 0;
    int j = 0;
    char* plainText  = (char *) malloc(sizeof(char) * strlen(cipherText) -1);

    for(i = 0; i < strlen(cipherText); i++)
    {
        int cipherLetterIndex = getPosition(tolower(cipherText[i]));
        int keyLetterIndex = getPosition(tolower(key[j]));

        int index = (keyLetterIndex - cipherLetterIndex + ALPHABET_SIZE) % ALPHABET_SIZE;

        plainText[i] = alphabet[index];
        j++;
        if(j == strlen(key))
        {
            j = 0;
        }
    }
    return plainText;
}

