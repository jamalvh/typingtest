//
//  main.cpp
//  type-test
//
//  Created by Jamal Hassunizadeh on 10/7/22.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


/*
TO SORT WORDS INTO ARRAY LIST FORM:
 
int count = 0;
string newWord;
string commonWords[1000];
while (cin >> newWord) {
    commonWords[count] = newWord;
    cout << "\"" << commonWords[count] << "\", ";
    count++;
}
*/

void printHeader();
char printMenu();
char playAgainPrompt();
bool punctuation();

int promptTestLength();

void play();

int main() {
    
    printHeader();

    if (printMenu() == 'q') {
        
        return 0;
        
    }
    
    
    play();
    
    while (playAgainPrompt() == 'p') {
        
        play();
        
    }
    
    return 0;
}

void printHeader() {
    
    cout << "------------------------------------------------" << endl;
    cout << "           TYPING ACCURACY ASSESSMENT" << endl;
    cout << "------------------------------------------------" << endl;
    
}

void play() {
           
    string answer;
    int accuracy;
                
    string commonWords[100] = {"the", "be", "and", "a", "of", "to", "in", "I", "you", "it", "have", "to", "that", "for", "do", "he", "with", "on", "this", "we", "that", "not", "but", "they", "say", "at", "what", "his", "from", "go", "or", "by", "get", "she", "my", "can", "as", "know", "if", "me", "your", "all", "who", "about", "their", "will", "so", "would", "make", "just", "up", "think", "time", "there", "see", "her", "as", "out", "one", "come", "people", "take", "year", "him", "them", "some", "want", "how", "when", "which", "now", "like", "other", "could", "your", "into", "here", "then", "than", "look", "way", "more", "these", "no", "thing", "well", "because", "also", "however", "point", "ask", "change", "course", "another", "write", "child", "need"};
    
    string wordsWithPunctuation[100] ={"the", "be", "and", "a", "of", "to", "in", "I", "you.", "it", "have", "to", "that's", "for", "do", "he", "with", "on", "this", "we", "that", "not", "but", "they", "say", "at", "what", "his", "from", "go", "or", "by,", "get", "she", "my", "can", "as", "know", "if", "me", "your", "all", "who's", "about", "their's", "will.", "so", "would,", "make,", "just", "up", "think", "time", "there", "see", "her's", "as", "out", "one", "come", "people!", "take", "year!", "him", "them", "some", "want", "how", "when", "which", "now", "like", "other.", "could", "your's", "into", "here", "then", "than", "look", "way", "more.", "these.", "no,", "thing", "well", "because.", "also", "however", "point", "ask", "change", "course", "another", "write", "child", "need"};
    
    int numCommonWords = 97;
                
    int numTestedWords = promptTestLength();
    string testedWords[numTestedWords];


    int mistakes = 0;
                
    srand((unsigned)time(NULL));
    
    bool punctuationChoice = punctuation();
    
    cout << endl;
    if (punctuationChoice == true) {
        for (int i = 0; i < numTestedWords; i++) {
                        
            testedWords[i] = wordsWithPunctuation[rand() % numCommonWords];
            cout << testedWords[i] << " ";
        }
    } else {
            for (int i = 0; i < numTestedWords; i++) {
                            
                testedWords[i] = commonWords[rand() % numCommonWords];
                cout << testedWords[i] << " ";
        }
    }
                
                
    cout << endl << endl;
    for (int i = 0; i < numTestedWords; i++) {
                        
    cin >> answer;
                        
        if (answer != testedWords[i]) {
                            
        cout << endl;
        cout << "# Expected: " << testedWords[i] << ", Actual: " << answer;
            mistakes++;
                            
        }
                                
    }
    
    if (mistakes > 0) {
        
        cout << endl;
        
    }
                
    cout << endl;
                
    accuracy = ceil(((numTestedWords - mistakes) / static_cast<double>(numTestedWords)) * 100);
    cout << "Accuracy: " << accuracy << "%" << endl;
               
                
}

        
int promptTestLength() {
    
    int testLength;
    cout << "> Enter test length (recommended: 10, 25, 50): ";
    cin >> testLength;
    
    return testLength;
}

char printMenu() {
    
    char menuInput;
    cout << "> Press 'p' to play or 'q' to quit: ";
    cin >> menuInput;
    
    while (menuInput != 'p' && menuInput != 'q') {
        
        cout << "> Invalid input, try again: ";
        cin >> menuInput;
        
    }
    
    return menuInput;
    
}

char playAgainPrompt() {
    
    char paInput;
    cout << "> Press 'p' to play again or 'q' to quit: ";
    cin >> paInput;
    
    while (paInput != 'p' && paInput != 'q') {
        
        cout << "> Invalid input, try again: ";
        cin >> paInput;
        
    }
    
    return paInput;
    
}
    
bool punctuation() {
    
    string puncInput;
    cout << "> Include punctuation? Enter 'yes' or 'no': ";
    cin >> puncInput;
    
    while (puncInput != "yes" && puncInput != "no") {
        
        cout << "> Invalid input, try again: ";
        cin >> puncInput;
        
    }
    
    if (puncInput == "yes") {
        
        return true;
    } else {
        
        return false;
    }
}
