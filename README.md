This project is a simple C program that converts a sentence into Pig Latin. It handles English text, preserves punctuation, and maintains capitalization where necessary. The program reads user input, translates each word to Pig Latin, and prints the translated sentence.

Features
- Translates words to Pig Latin.
- Handles both vowel-starting and consonant-starting words.
- Retains capitalization for words that start with a capital letter.
- Preserves punctuation marks at the end of words (up to two punctuation marks).
- Accepts dynamic user input and supports sentences with multiple words.
Pig Latin Translation Rules
- Vowel-starting words: If a word starts with a vowel (a, e, i, o, u), append "way" to the end of the word.

Example: apple becomes appleway.
Consonant-starting words: If a word starts with one or more consonants, move all consonants at the beginning to the end and append "ay".

Example: hello becomes ellohay.
Capitalization: The program ensures that the first letter of the translated word is capitalized if the original word was capitalized.

Example: Hello becomes Ellohay.
Punctuation: Any punctuation marks at the end of the word are preserved in their original position.

Example: hello! becomes ellohay!.

File Structure
bash
Copy code
├── pig_latin_translator.c   # Main program file
└── README.md                # Documentation file (this file)

How to Compile and Run
- Open a terminal and navigate to the folder containing pig_latin_translator.c.
- Compile the program using the following command:
gcc -o piglatin pig_latin_translator.c
- Run the program:
bash ./piglatin

Example Usage
  Enter a sentence: Hello, world!
  Translated sentence: Ellohay, orldway!

Functions
- int isVowel(char ch)
    Checks if a given character is a vowel (both uppercase and lowercase).

Parameters: char ch – the character to check.
Returns: 1 if the character is a vowel, otherwise 0.

void translateWord(char original[100], char translatedWord[100])
Translates an individual word from English to Pig Latin while preserving capitalization and punctuation.

Parameters:
  original[100] – the original English word.
  translatedWord[100] – the output Pig Latin translation.
  void translateSentence(char sentence[], char translatedSentence[])
Translates a complete sentence by breaking it into individual words and applying the Pig Latin rules to each word.

Parameters:
  sentence[] – the input sentence in English.
  translatedSentence[] – the translated sentence in Pig Latin.
  void getInput(char **str)
Prompts the user to input a sentence and reads the input dynamically.

Parameters:
str – pointer to store the dynamically allocated string.

Notes
The program uses getline() for reading input, which allows dynamic memory allocation for user input.
Be sure to free the allocated memory after use to avoid memory leaks.

License
This project is open source and free to use. Feel free to modify it as per your needs!
