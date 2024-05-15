#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1000

int isVowel(char ch) {
    ch = tolower(ch); // Convert to lowercase to simplify comparison
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void translateWord(char original[100], char translatedWord[100]) {
    // Check for capitalization
    int isCapitalized = isupper(original[0]);
    strcpy(translatedWord, original);
    
    // Handle punctuation
    char punctuation[3] = {0}; // Assuming the word won't have more than 2 punctuation marks
    size_t len = strlen(translatedWord);
    int punctuationIndex = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (!isalpha(translatedWord[i])) {
            punctuation[++punctuationIndex] = translatedWord[i];
            translatedWord[i] = '\0'; // Null-terminate the word at the punctuation
        } else {
            break;
        }
    }
    
    // Perform translation
    if (isVowel(translatedWord[0])) {
        strcat(translatedWord, "way");
    } else {
        // Move consonant cluster to end
        int clusterLength = 0;
        while (!isVowel(translatedWord[clusterLength])) {
            clusterLength++;
        }
        char firstConsonants[clusterLength + 1];
        strncpy(firstConsonants, translatedWord, clusterLength);
        firstConsonants[clusterLength] = '\0';
        memmove(translatedWord, translatedWord + clusterLength, strlen(translatedWord) - clusterLength + 1); // Move rest of the word
        strcat(translatedWord, firstConsonants);
        strcat(translatedWord, "ay");
    }
    
    // Capitalize the first letter if original word was capitalized
    if (isCapitalized) {
        translatedWord[0] = toupper(translatedWord[0]);
    }
    
    // Restore punctuation
    strcat(translatedWord, punctuation);
}

void translateSentence(char sentence[], char translatedSentence[]) {
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        char translatedWord[100];
        translateWord(token, translatedWord);
        strcat(translatedSentence, translatedWord);
        strcat(translatedSentence, " ");
        token = strtok(NULL, " ");
    }
}

void getInput(char **str) {
    size_t len = 0;
    *str = NULL;
    printf("Enter a sentence: ");
    ssize_t read = getline(str, &len, stdin);
    if (read == -1) {
        printf("Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    // Remove newline character if present
    if ((*str)[strlen(*str) - 1] == '\n') {
        (*str)[strlen(*str) - 1] = '\0';
    }
}

int main() {
    char *input;
    getInput(&input);

    char translatedOutput[strlen(input) * 2]; // Adjust size for translated sentence
    translatedOutput[0] = '\0'; // Initialize to empty string
    
    translateSentence(input, translatedOutput);
    printf("Translated sentence: %s\n", translatedOutput);

    free(input); // Free dynamically allocated memory
    return 0;
}
