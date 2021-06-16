#ifndef hangman_h
#define hangman_h

#include <iostream>
using namespace std;

class hangman{
private:
    int wordChoice = 0;
    int fails = 0;
    int characterCount = 0;

public:
    char *char_Array;
    int *indicator;
    char usedCharacters[26];
    
    void printBlanks(int wordNumber);
    void setUp(int wordLength);
    int getWordChoice();
    void setWordChoice(int wordNumber);
    int getFail();
    void setFail(int number);
    int getCharacterCount();
    void setCharacterCount(int countNumber);
    void draw(int failNumber);
    void printBlanks(string word);
    void printBlanksAndLetters(char array[], int indicator[]);
    void printUsedCharacters(char usedCharacters[], int count);
};

#endif /* hangman_h */