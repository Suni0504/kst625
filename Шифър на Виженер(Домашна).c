#include <stdio.h>
#include <string.h>
#include <ctype.h>


void vigenereCipher(char *text, char *key) {
    int i, j = 0;
    int textLength = strlen(text);
    int keyLength = strlen(key);

    
    for (i = 0; i < textLength; i++) {
        // Проверка дали е буква (за да игнорираме други символи)
        if (isalpha(text[i])) {
            char offset = islower(text[i]) ? 'a' : 'A';
            char keyOffset = islower(key[j]) ? 'a' : 'A';

            
            text[i] = (text[i] - offset + (key[j] - keyOffset)) % 26 + offset;

            
            j = (j + 1) % keyLength;
        }
    }
}

int main() {
    char text[100], key[100];


    printf("Въведете съобщение за шифриране: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; 

    printf("Въведете ключова дума: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; //

    
    vigenereCipher(text, key);

   
    printf("Шифрираното съобщение: %s\n", text);

    return 0;
}