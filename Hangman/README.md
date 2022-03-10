# hangman

Interactive C++ program for classic hangman game

This C++ Program simulates the playing of the game 'Hangman'. The first line that the program accepts (from standard input) is a string of uppercase English letters. If the string does not conform to this specification, the program will simply exit.

The subsequent lines inputted should each only consist of a single uppercase English character followed by a new line (which can be input by pressing the 'Enter' key). If the line does not conform to this format, then the program will exit immediately.

The program will allow for single uppercase English letters to be input until all letters appearing in the initial word have been entered. In that case, the program will output to standard output (std::cout or cout) a string on a new line simply saying:

HANGMAN!
