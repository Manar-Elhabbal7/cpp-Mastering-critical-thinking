#pragma once
#include <bits/stdc++.h>
using namespace std;
class User {
public:
    string name, email, password, user_name;
    int id;
    

    User() {
        id = generateId();
    }

    User(string name, string email, string password, string user_name)
        : name(name), email(email), password(password), user_name(user_name) {
        id = generateId();
    }

    static int generateId() {
        int last_id = 0;
        ifstream infile("D:\\c++ vs\\Project Ask ME\\user_id.txt");
        if (infile >> last_id)
            infile.close();

        ofstream outfile("D:\\c++ vs\\Project Ask ME\\user_id.txt");
        outfile << last_id + 1;
        outfile.close();

        return last_id + 1;
    }
    static void List_System_Users() {
        ifstream input ("D:\\c++ vs\\Project Ask ME\\data.txt");
        string line;
        cout << "System Users:\n";
        while (getline(input, line)) {
            istringstream iss(line);
            string name, email, password, username;int id;
            
            iss >> username >> name >> email >> password >> id ;
            cout << "Id : " << id << " Name : " << name << '\n';
        }
    }
};
