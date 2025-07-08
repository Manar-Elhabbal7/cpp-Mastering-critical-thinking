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
        output << T_id << " " << Q_id << " " << user_id << " " << thread   << '\n';
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

    static void answer_thread(int q_id) {
        ifstream input("D:\\c++ vs\\Project Ask ME\\threads.txt");
        int t_id = -1; 
        string line;

        while (getline(input, line)) {
            istringstream iss(line);
            int T_id, Q_id, user_id;
            string thread;
            iss >> T_id >> Q_id >> user_id >> thread;
            if (Q_id == q_id) {
                t_id = T_id;
                break;
            }
        }
        input.close();

        if (t_id == -1) {
            cout << RED << "Thread not found for this question ID.\n" << RESET;
            return;
        }

        bool answered = false;
        ifstream input2("D:\\c++ vs\\Project Ask ME\\threads_ans.txt");
        string line2;
        while (getline(input2, line2)) {
            istringstream iss(line2);
            int T_id, Q_id;
            string existing_ans;
            iss >> T_id >> Q_id >> existing_ans;
            if (T_id == t_id && Q_id == q_id) {
                answered = true;
                break;
            }
        }
        input2.close();

        string user_answer;
        cout << "Enter your answer: ";
        cin >> user_answer;

        if (answered) {
            cout << RED << "Warning: You already answered this question. The answer will be overwritten.\n" << RESET;

            ifstream file_in("D:\\c++ vs\\Project Ask ME\\threads_ans.txt");
            ofstream temp("D:\\c++ vs\\Project Ask ME\\temp.txt");

            string current_line;
            while (getline(file_in, current_line)) {
                istringstream iss(current_line);
                int T_id, Q_id;
                string old_answer;
                iss >> T_id >> Q_id >> old_answer;

                if (T_id == t_id && Q_id == q_id) {
                    temp << t_id << " " << q_id << " " << user_answer << '\n';
                } else {
                    temp << current_line << '\n';
                }
            }

            file_in.close();
            temp.close();

            remove("D:\\c++ vs\\Project Ask ME\\threads_ans.txt");
            rename("D:\\c++ vs\\Project Ask ME\\temp.txt", "D:\\c++ vs\\Project Ask ME\\threads_ans.txt");

        } else {
            ofstream output("D:\\c++ vs\\Project Ask ME\\threads_ans.txt", ios::app);
            output << t_id << " " << q_id << " " << user_answer << '\n';
            output.close();
        }

        cout << GREEN << "Answer saved successfully\n" << RESET;
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
