#include "letterFreq.h"
#include "caesar.h"
#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void letter_frequency (char *text)
{
    remove_whitespace(text);

    int letters[26];

    memset(letters, 0, sizeof(letters));

    int textLen = strlen(text);

    for (int i=0; i<textLen ; i++){
        if(isalpha(text[i])){
            int position = text[i] - 'a';
            letters[position]++;
        }
    }

    for (int i=0; i<26; i++){
        printf("%c appears %d time(s) in the text\n", (i + 'a'), letters[i]);
    }

}
