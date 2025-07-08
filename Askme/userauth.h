#pragma once
#include <bits/stdc++.h>
#include "h_user.h"
using namespace std;


class UserAuth {
public:
        string username, name, email, password;
        static int id;
        bool allowAnonymous;
        bool found = false;
        static bool status ;

    void Menu() {
        cout << "Menu:\n";
        cout << setw(5) <<"1] Log In\n";
        cout << setw(5) <<"2] Sign Up\n";
        cout << setw(5) <<"3] Log Out\n";
        cout << "Enter Number in range 1-3: ";
        int choice; cin >> choice;

        if (choice <= 0 || choice > 3) {
            cout << RED <<"Invalid Choice\n";
            return;
        }

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                SignUp();
                break;
            case 3:
                logout();
                break;
        }
    }

    UserAuth() = default;

    void login() {
        cout << "Enter Your Username & Password: ";
        string inputUser, inputPass;
        cin >> inputUser >> inputPass;

        ifstream input("D:\\c++ vs\\Project Ask ME\\data.txt");
        
        while (input >> username >> name >> email >> password >> id ) {
            if (username == inputUser && password == inputPass) {
                found = true;
                cout << GREEN <<"Login Successful! Welcome, " << name << "\n";
                status = true;
                break;
            }
        }
        
        input.close();
        if (!found) {
            cout << RED << " Invalid Username or Password\n" << RESET;
            Menu();
        }
    }

    void SignUp() {
        
        cout << "Enter Username (No spaces): ";
        cin >> username;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Email: ";
        cin >>email;
        cout << "Enter Password: ";
        cin >>password;
        
        
        ofstream output("D:\\c++ vs\\Project Ask ME\\data.txt", ios::app);

        User user(name, email, password, username);
        id = user.id;

            output << username << " "
                    << name << " "
                    << email << " "
                    << password << " "
                    << id << " "
                    << "\n";
        
        output.close();
        cout <<GREEN<< "You registered successfully!\n";
        status = true;
        
    }

    static void logout() {
        cout << GREEN << "You logged out successfully!\n";
        return;
    }
};

bool UserAuth::status = false;
int UserAuth ::id = 0;
