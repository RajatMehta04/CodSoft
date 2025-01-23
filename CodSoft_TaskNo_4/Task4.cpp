#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <limits>
using namespace std;

vector<vector<string>> task;   // Global 2D Dynamic Array

void waitForEnter() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cout << "Press Enter to Continue...";
    cin.get(); // Wait for Enter
}

void clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

void addTask(){
    clearScreen();
    cout << "-------- ADD TASK --------" << endl;
    while(true){
        string s;
        cin.ignore();
        cout << endl <<"Enter Task:- ";
        getline(cin, s);
        task.push_back({s,"Inomplete"});    // Pushing the Task by User 

        char ch;
        cout << "ADD MORE (Y/N):- ";
        cin >> ch;
        if(ch == 'N' || ch == 'n'){
            clearScreen();
            break;
        }
    }
}

void displayTask(){
    if(task.empty()){
        cout << "There is No Task!!!" << endl;
        return;
    }
    int cnt = 1;
    
    for (const auto& s : task) {
        cout << cnt++ <<". " << s[0] <<" [" << s[1] <<"]" << endl;
    }
    cout << endl ;
    
}


void markComplete(){
    while(true){
        clearScreen();
        cout << "-------- MARK TASK --------" << endl << endl;
        if(task.empty()){
            cout << "No Tasks Available!!!" << endl;
            waitForEnter();
            return;
        }

        int choice;
        displayTask();
        while(true){
            cout << "Enter Task Number:- ";
            cin>>choice;
            if(choice < 1 || choice > task.size()){
                cout << "Wrong Choice!" << endl;
            }
            else if(task[choice-1][1] == "Completed"){      // Marking the Task
                cout << "Already Completed" << endl;
            }
            else{
                task[choice-1][1] = "Completed";
                cout << "Task \"" << task[choice - 1][0] << "\" Marked as Completed!" << endl;
                break;
            }
        }
        char ch = tolower(ch);
        cout << "ADD MORE [Y/N]: ";
        cin>> ch;
        if(ch == 'n' ){
            return;
        }
    }
}

void deleteTask(){
    while(true){
        clearScreen();
        cout << "------ DELETE TASK ------" << endl << endl;
        if(task.empty()){
            displayTask();
            break;
        }

        int choice;
        displayTask();
        cout << "Enter Number to Delete:- ";
        cin >> choice;  
        cout << "Task " << choice <<" is Deleted!!!" << endl;
        task.erase(task.begin()+choice-1);      // Begin Deletion
        char ch = tolower(ch);
        cout << "ADD MORE [Y/N]: ";
        cin>> ch;
        if(ch == 'n' ){
            return;
        }
    }
}


int main() {
    int ch;
    while(true){
        clearScreen();
        cout << "---------- TO-DO-LIST ----------" << endl;
        cout << endl;
        cout << "1. ADD TASK"<< endl;
        cout << "2. DISPLAY TASK"<< endl;
        cout << "3. MARK COMPLETION" << endl; 
        cout << "4. DELETE TASK"<< endl;
        cout << "5. EXIT"<< endl;
        cout << "Select Choice:- ";
        cin >> ch;
        switch(ch){
            case 1: addTask();
                    break;
            case 2: clearScreen();
                    cout << "------ DISPLAY TASK ------" <<endl << endl;
                    displayTask();
                    waitForEnter();
                    break;
            case 3: markComplete();
                    break;
            case 4: deleteTask();
                    break;
            case 5: return 0;
            default: "Select Proper Choice!!!";        
        }
    }
    
}
