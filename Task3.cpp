#include <iostream>
#include <cstdlib>
using namespace std;

void clearScreen(){
        #ifdef _WIN32
            system("cls"); 
        #else
            system("clear"); 
        #endif
    }

class Tic_Tac_Toe{
    public:
    char ch[3][3];

    void display() {
        cout << endl << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << ch[i][j] << " | ";
            }
            cout << endl;
        }
        cout << "-------------" << endl << endl;
    }


    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (ch[i][0] == ch[i][1] && ch[i][1] == ch[i][2]) {
                cout << "Player " << ch[i][0] << " Wins!!!" << endl << endl;
                return true;
            }
            if (ch[0][i] == ch[1][i] && ch[1][i] == ch[2][i]) {
                cout << "Player " << ch[0][i] << " Wins!!!" << endl << endl;
                return true;
            }
        }
        if (ch[0][0] == ch[1][1] && ch[1][1] == ch[2][2]) {
            cout << "Player " << ch[1][1] << " Wins!!!" << endl << endl;
            return true;
        }
        if (ch[0][2] == ch[1][1] && ch[1][1] == ch[2][0]) {
            cout << "Player " << ch[1][1] << " Wins!!!" << endl << endl;
            return true;
        }
        return false;
    }

    void resetBoard() {
        char num = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ch[i][j] = num++;
            }
        }
    }

    void playerTurn(char player) {

        char choice;
        while (true) {
            cout << "Player " << player << "'s turn: ";
            cin >> choice;
            bool valid = false;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (ch[i][j] == choice) {
                        ch[i][j] = player;
                        valid = true;
                        break;
                    }
                }
                if (valid)
                    break;
            }

            if (valid) {
                break;
            }
            else{
                cout << "Invalid choice, try again." << endl;
            }
        }
    }

    void playGame() {
        display();
        for (int turn = 1; turn <= 9; turn++) {
            char currentPlayer = (turn % 2 == 1) ? 'X' : 'O';
            playerTurn(currentPlayer);
            clearScreen();
            display();
            if (checkWin()){
                return;
            }
        }
        cout << "It's a draw!" << endl;
    }
};

int main() {
    clearScreen();
    Tic_Tac_Toe TTT;
    while(true){
        clearScreen();
        int choice;
        cout <<"--------- TIC-TAC-TOE GAME ---------" << endl << endl;
        cout << "TYPE '1' TO PLAY GAME!!!" << endl;
        cout << "TYPE '0' TO EXIT!!!" << endl;
        cout << "Choice:- ";
        cin>> choice;
        if(choice){
            TTT.resetBoard();
            TTT.playGame();
        }
        else{
            return 0;
        }
    }
}