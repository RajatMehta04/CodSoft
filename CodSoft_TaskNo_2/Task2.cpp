#include <iostream>
#include <string>
#include <cstdlib>
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

class calc
{
public:
    int num1, num2;

    void input(){
        
        cout << "Enter Number 1:- ";
        cin >> num1;
        cout << "Enter Number 2:- ";
        cin >> num2;
    }

    void addition()
    {  
        clearScreen();
        cout  << "Addition of "<<num1 <<" and " << num2 <<" Number is : " << num1 + num2 << endl;
        waitForEnter();
    }

    void subtraction()
    {  
        clearScreen();
        cout  <<"Subtraction of "<<num1 <<" and " << num2 <<" Number is : " << num1 - num2 << endl;
        waitForEnter();
    }

    void multiplication()
    {  
        clearScreen();
        cout <<"Multiplication of "<<num1 <<" and " << num2 <<" Number is : " << num1 * num2 << endl;
        waitForEnter();
    }

    void division()
    {  
        clearScreen();
        if(num2 == 0){
            cout << "Number can't be divisble by 0" << endl;
            waitForEnter();
            return;
        }
        cout <<"Division of "<<num1 <<" and " << num2 <<" Number is : " << num1/num2 << endl;
        waitForEnter();
    }
};



int main()
{
    clearScreen();
    int choice;
    calc c;
    cout << "------- Welcome to Calculator ----------" << endl << endl;
    c.input();
    while (true)
    {
        clearScreen();
        cout << "---------- Calculator ----------" << endl << endl;
        cout <<"\tNumber 1: " << c.num1 << "\t Number 2: "<< c.num2 << endl;
        cout << "1.Addition" << endl;
        cout << "2.Subtraction" << endl;
        cout << "3.Multiplication" << endl;
        cout << "4.Division" << endl;
        cout << "5.Input New Numbers" <<endl;
        cout << "6.Exit" << endl;
        cout << "Enter Your Choice:- ";
        cin >> choice;

        switch(choice){
            case 1: c.addition();
                    break;
            case 2: c.subtraction();
                    break;
            case 3: c.multiplication();
                    break;
            case 4: c.division();
                    break;
            case 5: clearScreen();
                    cout << "------- Enter New Numbers -------" << endl << endl;
                    c.input();
                    break;
            case 6: return 0;
            default: cout << "Entered Wrong Choice... " << endl;
        }
    }
}
