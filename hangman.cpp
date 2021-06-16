#include "hangman.h"
#include <iostream>

using namespace std;

void hangman::setUp(int wordLength){
    char_Array = new char[wordLength];
    
    indicator = new int[wordLength];
    
    for (int i = 0; i != wordLength; i++){
        indicator[i] = 0;
    };
    
    for (int i = 0; i != end(usedCharacters) - begin(usedCharacters); i++){
        usedCharacters[i] = '\0';
    };
}

void hangman::printBlanks(int wordNumber){
    cout << "Blanks: ";
    for(int i = 0; i < wordNumber; i++){
        cout << "_";
    }
    cout << endl;
}

int hangman::getWordChoice(){
    return wordChoice;
}

void hangman::setWordChoice(int wordNumber){
    wordChoice = wordNumber;
}

int hangman::getFail(){
    return fails;
}

void hangman::setFail(int number){
    fails = number;
}

int hangman::getCharacterCount(){
    return characterCount;
}

void hangman::setCharacterCount(int countNumber){
    characterCount = countNumber;
}

void hangman::draw(int failNumber){
    if (fails == 1){
        cout << "- - - - - - - - -" << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl;
        cout << "_______          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 2){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "                 " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 3){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 4){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |          |  " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 5){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |          |  " << endl;
        cout << "   |          O  " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 6){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |          |  " << endl;
        cout << "   |          O  " << endl;
        cout << "   |          |  " << endl;
        cout << "   |          |  " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 7){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |          |  " << endl;
        cout << "   |          O  " << endl;
        cout << "   |         -|  " << endl;
        cout << "   |          |  " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 8){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |          |  " << endl;
        cout << "   |          O  " << endl;
        cout << "   |         -|- " << endl;
        cout << "   |          |  " << endl;
        cout << "   |             " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 9){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |          |  " << endl;
        cout << "   |          O  " << endl;
        cout << "   |         -|- " << endl;
        cout << "   |          |  " << endl;
        cout << "   |         /   " << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
    }
    
    else if (fails == 10){
        cout << "- - - - - - - - -" << endl << endl;
        cout << "    ----------   " << endl;
        cout << "   |          |  " << endl;
        cout << "   |          O  " << endl;
        cout << "   |         -|- " << endl;
        cout << "   |          |  " << endl;
        cout << "   |         / \\" << endl;
        cout << "   |             " << endl;
        cout << "___|___          " << endl << endl;
        cout << "- - - - - - - - -" << endl;
        cout << "GAME OVER" << endl;
        cout << "YOU LOST!" << endl;
    }
    
    else {
        cout << "Invalid input" << endl;
    }
}

void hangman::printBlanks(string word){
    cout << "- - - - - - - - -" << endl << endl << "Blanks: ";
    for (int i = 0; i != word.size(); i++){
        cout << "_ ";
    }
    cout << endl << "- - - - - - - - -"<< endl << endl;
}

void hangman::printBlanksAndLetters(char array[], int indicator[]){
    cout << "- - - - - - - - -" << endl << endl;
    cout << "Blanks: ";
    for (int i = 0; i != strlen(array); i++){
        if (indicator[i] == 1){
            cout << array[i];
        }
        else {
            cout << "_";
        }
    }
    cout << endl << "- - - - - - - - -" << endl << endl;
}

void hangman::printUsedCharacters(char usedCharacters[], int count){
    cout << "Used Chracters: ";
    for (int i = 0; usedCharacters[i] != '\0'; i++){
        cout << usedCharacters[i] << " ";
    }
    cout << endl << "- - - - - - - - -" << endl;
}