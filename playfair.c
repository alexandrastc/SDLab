#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

int removeRepeatingChars(int size, int a[]);
int insertElementAtPosition(int position, int a[], int size);

int main() {
    int i, j, k, strNum[100], cipherNum[100], numkey[100], keyLen, tempLength, tempKey[100];
    int flag = -1;
    int size, cipherKey[5][5], lenStr;
    int row1, row2, col1, col2;
    char str[100], key[100];
    printf("Plaintext:\n");
    gets(str);
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            str[j] = toupper(str[i]);
            j++;
        }

    }
    str[j] = '\0';
    size = strlen(str);
    for (i = 0; i < size; i++) {
        if (str[i] != ' ')
            strNum[i] = str[i] - 'A';
    }
    lenStr = i;
    printf("Key:\n");
    gets(key);
    for (i = 0, j = 0; i < strlen(key); i++) {
        if (key[i] != ' ') {
            key[j] = toupper(key[i]);
            j++;
        }
    }
    key[j] = '\0';
    k = 0;
    for (i = 0; i < strlen(key) + 26; i++) {
        if (i < strlen(key)) {
            if (key[i] == 'J') {
                flag = 8;
                printf("%d", flag);
            }
            numkey[i] = key[i] - 'A';
        } else {
            if (k != 9 && k != flag) // i = j 
            {
                numkey[i] = k;
            }
            k++;

        }
    }
    tempLength = i;
    keyLen = removeRepeatingChars(tempLength, numkey);

    k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cipherKey[i][j] = numkey[k];
            k++;
        }
    }

    for (i = 0; i < lenStr; i += 2) {
        if (strNum[i] == strNum[i + 1]) {
            insertElementAtPosition(i + 1, strNum, lenStr);
            lenStr++;
        }
    }
    if (lenStr % 2 != 0) {
        insertElementAtPosition(lenStr, strNum, lenStr);
        lenStr++;
    }

    for (k = 0; k < lenStr; k += 2) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (strNum[k] == cipherKey[i][j]) {
                    row1 = i;
                    col1 = j;
                }
                if (strNum[k + 1] == cipherKey[i][j]) {
                    row2 = i;
                    col2 = j;
                }

            }
        }
        if (row1 == row2) {
            col1 = (col1 + 1) % 5;
            col2 = (col2 + 1) % 5;
            cipherNum[k] = cipherKey[row1][col1];
            cipherNum[k + 1] = cipherKey[row2][col2];
        }
        if (col1 == col2) {
            row1 = (row1 + 1) % 5;
            row2 = (row2 + 1) % 5;
            cipherNum[k] = cipherKey[row1][col1];
            cipherNum[k + 1] = cipherKey[row2][col2];
        }
        if (row1 != row2 && col1 != col2) {
            cipherNum[k] = cipherKey[row1][col2];
            cipherNum[k + 1] = cipherKey[row2][col1];
        }
    }
    printf("Cyphertext: \n");

    for (i = 0; i < lenStr; i++) {
        printf("%c", cipherNum[i] + 'A');
    }
    printf("\n");

}

int removeRepeatingChars(int size, int a[]) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size;) {
            if (a[i] == a[j]) {

                for (k = j; k < size; k++) {
                    a[k] = a[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }
    return (size);
}

int insertElementAtPosition(int position, int a[], int size) {
    int i, insitem = 23, temp[size + 1];
    for (i = 0; i <= size; i++) {
        if (i < position) {
            temp[i] = a[i];
        }
        if (i > position) {
            temp[i] = a[i - 1];
        }
        if (i == position) {
            temp[i] = insitem;
        }

    }

    for (i = 0; i <= size; i++) {
        a[i] = temp[i];
    }
}