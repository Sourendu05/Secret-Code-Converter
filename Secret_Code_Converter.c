#include <stdio.h>
#include <string.h>

void charToBinary(char c) {
    for (int i = 7; i >= 0; --i) {
        putchar((c & (1 << i)) ? '1' : '0');
    }
}

void convertToBinary(char *sentence) {
    int len = strlen(sentence);
    for (int i = 0; i < len; ++i) {
        if (sentence[i] == ' ') {
            putchar('#');
        }
        else {
            charToBinary(sentence[i]);
        }
    }
}

char binaryToChar(const char *binary) {
    int result = 0;
    for (int i = 0; i < 8; ++i) {
        result <<= 1;
        result |= (binary[i] == '1') ? 1 : 0;
    }
    return (char)result;
}

void decodeBinary(const char *binary) {
    int len = strlen(binary);
    int wordStarted = 0;
    char buffer[9];
    buffer[8] = '\0';
    for (int i = 0; i < len; ++i) {
        if (binary[i] == '#') {
            printf(" ");
            wordStarted = 0;
        } 
        else {
            buffer[wordStarted++] = binary[i];
            if (wordStarted == 8) {
                printf("%c", binaryToChar(buffer));
                wordStarted = 0;
            }
        }
    }
}

int main() {
    int option;
    printf("1. Encode\n");
    printf("2. Decode\n");
    printf("Choose an option: ");
    scanf("%d", &option);
    getchar();
    if (option == 1) {
        char paragraph[25000];
        printf("Enter paragraph:\n");
        fgets(paragraph, sizeof(paragraph), stdin);
        paragraph[strcspn(paragraph, "\n")] = 0;
        printf("Here is the Encoded Message:\n");
        convertToBinary(paragraph);
    }
    else if (option == 2) {
        char binaryString[200000];
        printf("Enter binary string:\n");
        fgets(binaryString, sizeof(binaryString), stdin);
        binaryString[strcspn(binaryString, "\n")] = 0;
        printf("Here is the Decoded Message:\n");
        decodeBinary(binaryString);
    }
    else {
        printf("Invalid Option\nTry Again!\n");
    }
    printf("\n");
    return 0;
}