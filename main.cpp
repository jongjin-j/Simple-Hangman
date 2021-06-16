#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <array>
#include <string.h>
#include "hangman.h"
using namespace std;


bool checkAlphabet(char letter){
    if (97 <= (int)letter && (int)letter <= 122){
        return true;
    }
    else {
        return false;
    }
};

void stringToCharConverter(string word, char array[]){
    strcpy(array, word.c_str());
};

bool checkMatch(char array[], char input, int *indicator){
    int count = 0;
    for (int i = 0; i != strlen(array); i++){
        if (array[i] == input){
            count++;
            indicator[i] = 1;
        }
    };
    
    if (count > 0){
        return true;
    }
    else{
        return false;
    }
};

bool checkOverlap(char usedCharacters[], char input){
    int overlap = 0;
    for (int i = 0; i != strlen(usedCharacters); i++){
        if (usedCharacters[i] == input){
            overlap++;
        }
    };
    if (overlap > 0){
        return false;
    }
    else {
        return true;
    }
};

bool checkIndicatorIsFull(int *indicator, int arraySize){
    int indicatorCount = 0;

    for (int i = 0; i <= arraySize; i++){
            if (indicator[i] == 1){
                indicatorCount++;
            }
        }
    if (indicatorCount == arraySize){
        return true;
    }
    else {
        return false;
    }
};

void moveToNextStep(){
    string anyKey;
    cout << "Press any key to begin..." << endl;
    cin >> anyKey;
    cout << endl;
}

int main()
{
	//string words[20] = {"sketch", "sequence", "loose", "meet", "disgrace", "knowledge", "boat", "guest", "virgin", "tank", "rally", "justice", "improve", "gear", "opposition", "minor", "return", "promotion", "elephant", "match"};
    
    //srand(time(NULL));
    
    //creating hangman object
    hangman player1;
    
    //player1.setWordChoice(rand() % 20);

    cout << endl << endl << "Welcome to Hangman!" << endl << endl;
    cout << "Player 2 guesses the word player 1 entered :)" << endl << endl << endl;
    //cout << "Beginner(50%), Intermediate(30%), Advanced(0%)" << endl << endl;
    //cout << "Press 1 for Beginner, 2 for Intermediate, 3 for Advanced " << endl;
    //cin >> difficulty;
    
    moveToNextStep();
    
    string wordSelect;
    
    cout << "Player 1: Enter a word: ";
    cin >> wordSelect;
    system("clear");
    
    //player1.printBlanks(words[player1.getWordChoice()].size());
    player1.printBlanks(wordSelect.size());
    
    char input;
    
    //player1.setUp(words[player1.getWordChoice()].size());
    player1.setUp(wordSelect.size());
    
    //char char_Array[words[player1.getWordChoice()].size()];
    
    //stringToCharConverter(words[player1.getWordChoice()], player1.char_Array);
    stringToCharConverter(wordSelect, player1.char_Array);
    
    cout << endl;
        
    while(player1.getFail() != 10){
        //if: all int indicators are 1, else: three lines below
        cout << "Enter an alphabet: ";
        cin >> input;
        system("clear");
        
        if(checkAlphabet(input) == false){
            cout << "Invalid input" << endl;
        }
        
        if(checkOverlap(player1.usedCharacters, input) == false){
            cout << "Alphabet already used" << endl;
        }
        
        if(checkMatch(player1.char_Array, input, player1.indicator) == true){
            cout << "There is/are '" << input << "'s in the word." << endl;
                player1.usedCharacters[player1.getCharacterCount()] = input;
                player1.draw(player1.getFail());
                player1.printBlanksAndLetters(player1.char_Array, player1.indicator);
                player1.printUsedCharacters(player1.usedCharacters, player1.getCharacterCount());
        }
        else{
            cout << "There is/are not '" << input << "'s in the word." << endl;
                player1.usedCharacters[player1.getCharacterCount()] = input;
                player1.setFail(player1.getFail() + 1); // fails++
                player1.draw(player1.getFail());
                player1.printBlanksAndLetters(player1.char_Array, player1.indicator);
                player1.printUsedCharacters(player1.usedCharacters, player1.getCharacterCount());
                
        }
        
        //characterCount++
        player1.setCharacterCount(player1.getCharacterCount() + 1);  
        
        /*if (checkIndicatorIsFull(player1.indicator, words[player1.getWordChoice()].size()) == true){
            cout << "YOU WON!!" << endl;
            delete [] player1.char_Array;
            delete [] player1.indicator;
            return 0;
        }*/
        if (checkIndicatorIsFull(player1.indicator, wordSelect.size()) == true){
            cout << "YOU WON!!" << endl;
            delete [] player1.char_Array;
            delete [] player1.indicator;
            return 0;
        }
        
    };
    
    cout << endl;
    
	return 0;
};