#include <iostream>
#include "graph.h"
#include "Djistra.h"
#include "metrodata.h"
#include <fstream>
#include <string>
#include <cctype> 
#include <limits> 

using namespace std;
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

string toUpperCase(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    return str;
}

void signUp() {
    string first, last, username, password;
    cout << "\033[36mEnter First name: \033[0m";
    cin >> first;
    cout << "\033[36mEnter Last name: \033[0m";
    cin >> last;

    first = toLowerCase(first);
    last = toLowerCase(last);
    username = first + last;
    
    cout << "\033[36mEnter password: \033[0m";
    cin >> password;
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open()) {
        logFile << username << " " << password << endl;
        system("CLS");
        cout << "\033[32mSign-up successful! Please sign in now.\033[0m" << endl;
        
        logFile.close();
    } else {
        cout << "\033[31mError opening log file.\033[0m" << endl;
    }
}

bool signIn() {
    string username, password, fileUsername, filePassword, first,last;
    int attempts = 3;  

    while (attempts > 0) {
        cout << "\033[36mEnter First name: \033[0m";
        cin >> first;
        cout << "\033[36mEnter Last name: \033[0m";
        cin >> last;
    
    // Convert to lowercase and create the username
    first = toLowerCase(first);
    last = toLowerCase(last);
    username = first + last;
        cout << "\033[36mEnter password: \033[0m";
        cin >> password;
        username = toLowerCase(username);

        ifstream logFile("log.txt");
        if (!logFile.is_open()) {
            cout << "\033[31mError opening log file.\033[0m" << endl;
            return false;
        }
        while (logFile >> fileUsername >> filePassword) {
            if (fileUsername == username && filePassword == password) {
                logFile.close();
                cout << "\033[32mSign-in successful!\033[0m" << endl;
                return true;
            }
        }

        logFile.close();
        attempts--;
        cout << "\033[31mInvalid username or password. You have " << attempts << " attempts left.\033[0m" << endl;
        
        if (attempts == 0) {
            cout << "\033[31mToo many failed attempts. Exiting the program.\033[0m" << endl;
            return false;
        }

        char retryChoice;
        cout << "\033[36mDo you want to try again? (y/n): \033[0m";
        cin >> retryChoice;
        if (retryChoice == 'n' || retryChoice == 'N') {
            return false;
        }
    }
    return false;  
}

void askForSourceAndDestination(string &source, string &destination,GraphStructure<string> &graph) {
    cout << "\033[36mEnter source station: \033[0m";
    cin >> source;
    source = toUpperCase(source); 
    
    cout << "\033[36mEnter destination station: \033[0m";
    cin >> destination;
    destination = toUpperCase(destination);
     dijkstra_algo<string>(graph,source,destination);  

}

string centerText(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    if (padding > 0) {
        return string(padding, ' ') + text;
    }
    return text;
}

void displayMetroBusDesign() {
    const int screenWidth = 80;
    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string CYAN = "\033[36m";

    cout << CYAN;
    cout << centerText("     _______________________________", screenWidth) << endl;
    cout << centerText("    |                               |", screenWidth) << endl;
    cout << centerText("    |    WELCOME TO METRO BUS!     |", screenWidth) << endl;
    cout << centerText("    |_______________________________|", screenWidth) << endl;
    cout << centerText("          O                O        ", screenWidth) << endl;
    cout << centerText("                                     ", screenWidth) << endl;
    cout << RESET;
}

void displayMenu() {
    const int screenWidth = 80; // Adjust for desired screen width
    const string separator = string(screenWidth, '*');

    // ANSI color codes
    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string CYAN = "\033[36m";

    displayMetroBusDesign();

    // Menu layout
    cout << CYAN << centerText("", screenWidth) << "\n";
    cout << separator << endl;
    cout << centerText("WELCOME TO METRO MANAGEMENT SYSTEM", screenWidth) << endl;
    cout << separator << endl;
    cout << "\n";
    cout << GREEN << centerText("* * * * * * LOGIN PANEL * * * * * *", screenWidth) << RESET << endl;
    cout << "\n";

    cout << centerText("1. LOGIN", screenWidth) << endl;
    cout << centerText("   2. REGISTER", screenWidth) << endl;
    cout << RED << centerText("3. EXIT", screenWidth) << RESET << endl;
    cout << "\n";

    cout << separator << endl;
    cout << "\n";
    cout << CYAN << centerText("Enter Your Choice: ", screenWidth) << RESET;
}


int main() {
    GraphStructure<string> graph = metroRoutes();
    int choice;
    bool loggedIn = false;

    // Ask if user wants to sign up or sign in
    while (true) {
        displayMenu();
        
        // Handle invalid menu choice input
        if (!(cin >> choice)) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "\033[31mInvalid input! Please enter a valid option.\033[0m" << endl;
            system("CLS");
            continue;
        }

        switch (choice) {
            case 1:
                loggedIn = signIn();
                if (loggedIn) {
                    bool flag=true;
                    while(flag){
                    // After successful sign-in, ask for source and destination
                    string source, destination;
                    askForSourceAndDestination(source, destination,graph);
                    cout<<endl;
                    string hello;
                    cout<<"Do you want to close maps"<<endl;
                    cout<<"Press Y/y "<<endl;
                    cin>>hello;
                    if(hello=="y" || hello=="Y"){
                        flag=false;
                        cout<<"EXSIT SUCCESSFULLY"<<endl;
                    }
                    }
                }
                break;

            case 2:
                signUp(); // Sign-up process
                break;

            case 3:
                cout << "\033[31mExiting...\033[0m" << endl;
                return 0;

            default:
                cout << "\033[31mInvalid option, please try again!\033[0m" << endl;
        }

        if (loggedIn) {
            break; // Exit the loop if the user is logged in successfully
        }
    }

    return 0;
   
}
