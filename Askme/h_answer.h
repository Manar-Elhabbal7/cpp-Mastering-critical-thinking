#pragma once
#include <bits/stdc++.h>
using namespace std;
class Answer{
public:
    int  Q_id = 0;
    string answer;
    
    Answer() = default;
    Answer( int Q_id, string answer) : Q_id(Q_id), answer(answer) {}
    
    
    void saveTofile() const{
        ofstream output("D:\\c++ vs\\Project Ask ME\\answers.txt", ios::app);
        output << Q_id << " " << answer << '\n';
    }
    
    
    static void display_Answers(int q) {
        ifstream input2("D:\\c++ vs\\Project Ask ME\\answers.txt");
        string line;
        cout << "Answers:\n";
        while (getline(input2, line)) {
            istringstream iss(line);
            int Q_id;
            string answer;
            iss >> Q_id >> answer;
            if (Q_id == q)
                cout << answer << '\n';
        }
    }

};
