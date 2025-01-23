#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

void waitForEnter() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cout << "Press Enter to Continue...";
    cin.get(); // Wait for Enter
}

void playGame(){
    clearScreen();
    srand(time(0));

    int random = rand() % 100 + 1;
    int user;

    cout << "Guess the number (between 1 and 100): " << endl;

    do {
        cout << "Enter your guess: ";
        cin >> user;
        if(user <= 100 && user >=0){
            if (user < random) {
                cout << endl << "Too low! Try again." << endl;
            } 
            else if (user > random) {
                cout << endl << "Too high! Try again." << endl;
            }
        }
        else{
            cout << "The Number is not Between 1 to 100" << endl;
        }
    } while (user != random);

    cout << endl<< "Correct! The Number is:- " << random << endl;
    cout << "You guessed the number." << endl << endl;
    waitForEnter();
}


int main() {
    while(true){
        int ch;
        clearScreen();
        cout << "--------- Guess The Number ---------" << endl << endl;
        cout << "1. Play Game" << endl;
        cout << "2. Exit" << endl;
        while(true){
            cout << "Select Option:- ";
            cin >> ch;
            if(ch == 1) {
                playGame();
                break;
            }
            else if(ch == 2)
                return 0;
            else{
                cout << endl<<"Wrong Option!! Choose Again..." << endl;
            }
        }
    }
}
