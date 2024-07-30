#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));
  int secNum = rand() % 100 + 1;
  int guess;
  int attempts = 0; // initialise it with 0

  cout << "Welcome, I have select a number between 1 and 100." << endl;

  do {
    cout << "Enter any number: ";
    cin >> guess;
    attempts++;

    if (guess < secNum) {
      cout << "Too low, try again." << endl;
    } else if (guess > secNum) {
      cout << "Too high, try again." << endl;
    }
  } while (guess != secNum);
  cout << "Congratulations, you guessed the correct number " << secNum << " in "
       << attempts << " attempts." << endl;

  return 0;
}