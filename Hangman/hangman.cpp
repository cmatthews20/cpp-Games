
#include <iostream>
using namespace std;

// Returns true if character passed through is an uppercase letter.
bool isUpperCase(char myHangmanChar){
    return !((myHangmanChar < 'A') || (myHangmanChar > 'Z'));
}

// Returns true if string passed through is valid (contains all uppercase letters and has at least 1 character).
bool isValidWord(string myHangmanWord){

    // Ensures the user did not make a blank entry.
    if(myHangmanWord.length() < 1){
        return false;
    }

    // The following loop iterates through the word and ensures every character is uppercase using 'isUpperCase' function.
    for(int i=0 ; i < myHangmanWord.length(); i++){

        char letter = myHangmanWord[i];

        if(!isUpperCase(letter)){
            return false;
        }
    }
    return true;
}

int main() {

	char guessChar;
    string hangmanWord;
    cin >> hangmanWord;

    // Ends the session if the hangmanWord entered is not valid.
    if (!isValidWord(hangmanWord)) {
        cout << "This word is not valid; session is over. " << endl;
        return 0;
    }

    // Initializes a counter to track correct guesses. Duplicate letters multiply appropriately.
    int totalOccurrences = 0;

    /* The following loop will run until a character is entered which is not an uppercase English letter, or until
     * the hangmanWord has been guessed. */
    while (true) {

        cin >> guessChar;

        //Checks the guess made by the user to see if it is an uppercase letter.
        if(!isUpperCase(guessChar)){
            break;
        }

        //Initializes a variable each loop to count the number of times an individual guess appears in the hangmanWord.
        int guessCharacterOccurrences = 0;

        /* Iterates through the hangman word to check if the guess matches any characters.
         * Increments guessCharacterOccurrences by one if a match is found. */
        for (int i = 0; i < hangmanWord.length(); i++) {

            char wordCharacter = hangmanWord[i];

            if (guessChar == wordCharacter) {
                guessCharacterOccurrences++;
                hangmanWord[i] = 0;
            }
        }

        totalOccurrences += guessCharacterOccurrences;

        // Total occurrences of guessed characters must equal the hangman word length for session to end.
        if (totalOccurrences == hangmanWord.length()) {
            cout << "HANGMAN!\n";
            break;
        }
    }
}