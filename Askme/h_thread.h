#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "colors.h"
class Thread{
public:
    int T_id = 0, Q_id = 0, user_id = 0;
    string thread;
    
    Thread() = default;
    Thread(int T_id, int Q_id, int user_id, string thread) : T_id(T_id), Q_id(Q_id), user_id(user_id), thread(thread){}
    
    void saveTofile() const{
        ofstream output("D:\\c++ vs\\Project Ask ME\\threads.txt", ios::app);
        output << T_id << " " << Q_id << " " << user_id << " " << thread  << " " << '\n';
    }

    static void display_Thread_and_answer(int q) {
        ifstream input2("D:\\c++ vs\\Project Ask ME\\threads.txt");
        string line;
        cout << "Thread:\n";
        while (getline(input2, line)) {
            istringstream iss(line);
            int T_id, Q_id, user_id;
            string thread;
            iss >> T_id >> Q_id >> user_id >> thread ;
            if (Q_id == q)
                cout << thread << '\n';
        }
        
        cout << "Answer:\n";
        ifstream input3("D:\\c++ vs\\Project Ask ME\\threadsans.txt");
        string line2 ;
        while(getline(cin,line)){
            int t_id,q_id;
            string ans;
            istringstream iss(line2);
            iss >> t_id >> q_id >> ans;
            if (q_id == q)
                cout << ans << '\n';
        }
    }

    static void answer_thread(int t_id,int q_id) {

        cout << "Enter your answer:\n";
        string answer;cin >> answer;

        bool answered = false;
        ifstream input2("D:\\c++ vs\\Project Ask ME\\threadsans.txt");
        string line;
        while (getline(input2, line)) {
            istringstream iss(line);
            int T_id, Q_id;
            string ans;
            iss >> T_id >> Q_id >> ans;
            if (T_id == t_id && Q_id == q_id) {
                answered = true;
                break;
            }
        }
        input2.close();
        if (!answered) {
            ofstream output("D:\\c++ vs\\Project Ask ME\\threadsans.txt", ios::app);
            output << t_id << " " << q_id << " " << answer << '\n';
            output.close();
            cout <<GREEN<< "Answer saved successfully.\n";
        }
        else{
            cout <<"Warning: You have already answered this thread the answer will be updated.\n";
            //save to temp file and delete the old file and rename the temp file
            ifstream input("D:\\c++ vs\\Project Ask ME\\threadsans.txt");
            ofstream temp("D:\\c++ vs\\Project Ask ME\\temp.txt");
            string line;
            while (getline(input, line)) {
                istringstream iss(line);
                int T_id, Q_id;
                string ans;
                iss >> T_id >> Q_id >> ans;
                if (T_id == t_id && Q_id == q_id) {
                    temp << t_id << " " << q_id << " " << answer << '\n';
                }
                else {
                    temp << line << '\n';
                }
            }
            input.close();
            temp.close();
            remove("D:\\c++ vs\\Project Ask ME\\threadsans.txt");
            rename("D:\\c++ vs\\Project Ask ME\\temp.txt", "D:\\c++ vs\\Project Ask ME\\threadsans.txt");
            cout <<GREEN<< "Answer saved successfully.\n";

        }
    }

    static int getLastThreadId() {
        ifstream input("D:\\c++ vs\\Project Ask ME\\threads.txt");
        int last_id = 0;
        string line;
        while (getline(input, line)) {
            istringstream iss(line);
            int T_id, Q_id, user_id;
            string thread;
            iss >> T_id >> Q_id >> user_id >> thread;
            last_id = T_id;
        }
        input.close();
        return last_id + 1;
    }

};