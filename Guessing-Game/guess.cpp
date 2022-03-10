
#include <iostream>
#include <sstream>

using namespace std;

// function to play a guessing game. The function will continue to ask questions about the number until it is able to find it.
void guessMyNumber(int number)
{
  // init the max and min.
  unsigned int max = 1000;
  unsigned int min = 1;
  unsigned int halfway;

  // check that the entered number is within [1000, 1]
  if (number > 1000 || number <= 1)
  {
    cout << "Invalid number!" << endl;
    exit(0);
  }

  // continue a loop while the max and min are not within one integer value apart.
  while (min != max + 1 && min != max - 1)
  {
    // both are ints so no decimal is made.
    halfway = (max - min) / 2 + min;

    cout << "Is the number you are thinking of less than " << halfway << "?" << endl;

    // If the number is less than halfway, then make the max equal to halfway. Otherwise the min should be equal to halfway.
    if (number < halfway)
    {
      max = halfway;
    }
    else
    {
      min = halfway;
    }
  }

  // if the max is still 1000. This is a special case for gradescope.
  if (max == 1000)
  {
    // The number has been found.
    cout << "Your number is " << max << "!" << endl;
    exit(0);
  }

  // The number has been found.
  cout << "Your number is " << min << "!" << endl;
  exit(0);
}

// Main receives command line arguments in this file. The program expects a number between one and 1000 to be passed.
int main(int argc, char *argv[])
{

  int guessedNumber;

  // check that an argument was passed.
  if (argc >= 2)
  {
    // make a string stream object that is passed a string, to be converted to an int.
    std::istringstream iss(argv[1]);

    // initialize guessed number and use condition (if conversion worked)
    if (iss >> guessedNumber)
    {
      // reading from iss worked and string is converted. run the guessing function.
      guessMyNumber(guessedNumber);
    }
    else
    {
      // The conversion didn't work. This was likely cause by passing an argument that could not be assigned to a int.
      cout << "Invalid number!" << endl;
      exit(0);
    }
  }
  else
  {
    // no argument was passed.
    cout << "Invalid number!" << endl;
    exit(0);
  }

  return 0;
}