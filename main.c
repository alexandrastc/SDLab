#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "caesar.h"
#include "vigenere.h"
#include "letterFreq.h"
#define TEXT_SIZE 1000

void common_choices();

int main()
{
    char text[TEXT_SIZE];
    int choice = 0;
    int method = 0;
    int key = 0;
    char charKey[100];
    bool hasChosen = false;
    bool isValid = false;
    FILE *f;
    
    f = fopen("input.txt", "r");
    
    if (f == NULL){
        printf("Error opening file");
        exit(1);
    }

    /**
     * Reads only the first line,
     * replace \n with EOF to read
     * the whole file.
     **/
    fscanf(f,"%[^\n]", text);

    while(!hasChosen){
        printf("Choose a cypher. Your options are: \n");
        printf("1. Caesar cypher\n");
        printf("2. Check letter frequency\n");
        printf("3. Vigenere\n");
        printf("4. Playfair\n");

        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                hasChosen = true;
                while(!isValid){
                    common_choices();
                    printf("3. Brute force\n");
                    printf("Your choice: ");
                    scanf("%d", &method);
                    printf("\n");

                    switch(method){
                        case 1:
                            printf("Key: ");
                            scanf("%d", &key);        
                            caesar_encrypt(key, text);
                            isValid = true;
                            break;
                        case 2:
                            printf("Key: ");
                            scanf("%d", &key);        
                            caesar_decrypt(key, text);
                            isValid = true;
                            break;
                        case 3: 
                            caesar_brute_force(text);
                            isValid = true;
                            break;
                        default:
                            isValid = false;
                            printf("Wrong value. \n\n");
                    }
                    
                }
                break;

            case 2:
                hasChosen = true;
                letter_frequency(text);
                break;

            case 3:
                hasChosen = true;
                do {
                    common_choices();
                    printf("Your choice: ");
                    scanf("%d", &method);
                    printf("\n");

                    switch(method){
                        case 1:
                            printf("Key: ");
                            scanf("%s", charKey);        
                            vigenere_encrypt(charKey, text);
                            isValid = true;
                            break;
                        case 2:
                            printf("Key: ");
                            scanf("%s", charKey);        
                            vigenere_decrypt(charKey, text);
                            isValid = true;
                            break;
                        default:
                            printf("Wrong value. \n\n");
                    }

                } while(!isValid);
                break;
            
            default:
                printf("Wrong value. \n\n");
        }
    }


}

void common_choices()
{
    printf("The options are: \n");
    printf("1. Encrypt\n");
    printf("2. Decrypt with key\n");
}