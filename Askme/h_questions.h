#pragma once
#include <bits/stdc++.h>
#include "h_answer.h"
#include "userauth.h"

class Question{
public:
    int Q_id = 0, user_id = 0;
    string question;
    
    Question() = default;
    Question(int Q_id, int user_id, string question) : Q_id(Q_id), user_id(user_id), question(question) {}

    
    static int getLastQuestionId() {
        ifstream input("D:\\c++ vs\\Project Ask ME\\Questions.txt");
        int last_id = 0;
        string line;
        while (getline(input, line)) {
            istringstream iss(line);
            int Q_id, user_id;
            string question;
            iss >> Q_id >> user_id >> question;
            last_id = Q_id;
        }
        input.close();
        return last_id + 1;
    }
    void saveTofile() const{
        ofstream output("D:\\c++ vs\\Project Ask ME\\Questions.txt", ios::app);
        output << Q_id << " " << user_id << " " << question << '\n';
    }
    void display_Questions() const{
        ifstream input2("D:\\c++ vs\\Project Ask ME\\Questions.txt");
        string line;
        cout << "Question \n";
        while (getline(input2, line)) {
            istringstream iss(line);
            int Q_id, user_id;
            string question;
            iss >> Q_id >> user_id >> question;
            if (user_id == this->user_id)
                cout << question << '\n';
        }
    }
    static void delete_Question(int q_id){

        //delete from questions(done)
        ifstream input("D:\\c++ vs\\Project Ask ME\\Questions.txt");
        ofstream temp("D:\\c++ vs\\Project Ask ME\\temp_q.txt");
        string line ;
    
        while (getline(input, line)) {
            istringstream iss(line);
            int Q_id, user_id;
            string question;
            iss >> Q_id >> user_id >> question;
            if(q_id != Q_id){
                temp<< Q_id << " " << user_id << " " << question << '\n';
            }
        }
        input.close();
        temp.close();

        remove("D:\\c++ vs\\Project Ask ME\\Questions.txt");
        rename("D:\\c++ vs\\Project Ask ME\\temp_q.txt", "D:\\c++ vs\\Project Ask ME\\Questions.txt");

        //delete from answers
        ifstream input2("D:\\c++ vs\\Project Ask ME\\answers.txt");
        ofstream temp2("D:\\c++ vs\\Project Ask ME\\temp_a.txt");
        string line2 ;
    
        while (getline(input2, line2)) {
            istringstream iss(line2);
            int Q_id;
            string answer;
            iss >> Q_id >> answer;
            if(q_id != Q_id){
                temp2<< Q_id << " " << answer << '\n';
            }
        }
        input2.close();
        temp2.close();

        remove("D:\\c++ vs\\Project Ask ME\\answers.txt");
        rename("D:\\c++ vs\\Project Ask ME\\temp_a.txt", "D:\\c++ vs\\Project Ask ME\\answers.txt");

        //delete from threads
        ifstream input3("D:\\c++ vs\\Project Ask ME\\threads.txt");
        ofstream temp3("D:\\c++ vs\\Project Ask ME\\temp_t.txt");
        string line3 ;
    
        while (getline(input3, line3)) {
            istringstream iss(line3);
            int T_id, Q_id, user_id;
            string thread;
            iss >> T_id >> Q_id >> user_id >> thread;
            if(q_id != Q_id){
                temp3 << T_id << " " << Q_id << " " << user_id << " " << thread << '\n';

            }
        }
        input3.close();
        temp3.close();

        remove("D:\\c++ vs\\Project Ask ME\\threads.txt");
        rename("D:\\c++ vs\\Project Ask ME\\temp_t.txt", "D:\\c++ vs\\Project Ask ME\\threads.txt");

        //delete from threadsans
        ifstream input4("D:\\c++ vs\\Project Ask ME\\threads_ans.txt");
        ofstream temp4("D:\\c++ vs\\Project Ask ME\\temp_ta.txt");
        string line4 ;
    
        while (getline(input4, line4)) {
            istringstream iss(line4);
            int T_id, Q_id;
            string answer;
            iss >> T_id >> Q_id >> answer;
            if(q_id != Q_id){
                temp4<< T_id << " " << Q_id << " " << answer << '\n';
            }
        }
        input4.close();
        temp4.close();

        remove("D:\\c++ vs\\Project Ask ME\\threads_ans.txt");
        rename("D:\\c++ vs\\Project Ask ME\\temp_ta.txt", "D:\\c++ vs\\Project Ask ME\\threads_ans.txt");

    }


    static void answer_question(int q_id){
        bool found = false;
        ifstream input("D:\\c++ vs\\Project Ask ME\\Questions.txt");
        string line , ques;
        
    
        while (getline(input, line)) {
            istringstream iss(line);
            int Q_id, user_id;
            string question;
            iss >> Q_id >> user_id >> question;
            if(q_id == Q_id){
                found = true;
                ques = question;
                break;
            }
        }
        if(!found){
            cout <<RED <<"Question not found\n" << RESET;
            //System::showMenu();
        }

        ifstream input2 ("D:\\c++ vs\\Project Ask ME\\answers.txt");
        string line2,ans ; 
        bool answered = false;
        while (getline(input2, line2)) {
            istringstream iss(line2);
            int Q_id;
            string answer;
            iss >> Q_id >> answer;
            if(q_id == Q_id){
                answered = true;
                ans = answer;
                break;
            }
        }
        input2.close();

        cout << "Question id : ( " << q_id << " ) the question is : " << ques << '\n';
        
        string ans_n;
        if(answered) {
            
            cout <<"Answer : " << ans << '\n';
            cout <<RED << "Warning :already answered , the answer will be overwritten\n" << RESET;

            cout << "Enter your answer : ";
            cin >> ans_n;
            
            ifstream input3("D:\\c++ vs\\Project Ask ME\\answers.txt");
            ofstream temp7("D:\\c++ vs\\Project Ask ME\\temp_a.txt");
            string line3 ;

            while (getline(input3, line3)) {
                istringstream iss(line3);
                int Q_id2;
                string answer2;
                iss >> Q_id2 >> answer2;
                if(Q_id2 != q_id){
                    temp7 << Q_id2 << " " << answer2 << '\n';
                }
            }
            input3.close();
            temp7.close();

            remove("D:\\c++ vs\\Project Ask ME\\answers.txt");
            rename("D:\\c++ vs\\Project Ask ME\\temp_a.txt", "D:\\c++ vs\\Project Ask ME\\answers.txt");
            Answer answer(q_id, ans_n);
            answer.saveTofile();
            
        }
        else{
            cout << "Enter your answer : "; 
            cin >> ans_n;
            Answer answer(q_id, ans_n);
            answer.saveTofile();
        }
        cout <<GREEN << "Answer saved successfully\n" << RESET;
        //System::showMenu();
    }

    static void print_my_questions(int user_id){
        //print question and its answer
        cout << "These Questions are from U : \n";
        ifstream input("D:\\c++ vs\\Project Ask ME\\Questions.txt");
        string line ;
        map<int , tuple<int,string>>mp_q;
        while (getline(input, line)) {
            istringstream iss(line);
            int Q_id, user_id2;
            string question;
            iss >> Q_id >> user_id2 >> question;
            if(user_id == user_id2){
                mp_q[Q_id] = make_tuple(Q_id,question);
            }
        }
        input.close();
        map<int ,tuple<int,string>>Ans;
        ifstream input2("D:\\c++ vs\\Project Ask ME\\answers.txt");
        string line2;
        while (getline(input2, line2)) {
            istringstream iss(line2);
            int Q_id;
            string answer;
            iss >> Q_id >> answer;
            if(mp_q.find(Q_id) != mp_q.end()){
                Ans[Q_id] = make_tuple(Q_id,answer);
            }
        }
        input2.close();
        for(auto i : mp_q){
            cout << "Question id : (" << get<0>(i.second)  << ") The question is : " << get<1>(i.second) << '\n';
            if(Ans.find(get<0>(i.second)) != Ans.end()){
                cout << "Answer : " << get<1>(Ans[get<0>(i.second)]) << '\n';
            }
        }
        
        //System::showMenu();
    }

    static void print_all(){
        vector<pair<int,string>>v;
        ifstream input("D:\\c++ vs\\Project Ask ME\\Questions.txt");
        string line ;
        while (getline(input, line)) {
            istringstream iss(line);
            int Q_id, user_id;
            string question;
            iss >> Q_id >> user_id >> question;
            v.push_back(make_pair(Q_id,question));
        }
        input.close();
        for(auto i : v){
            cout << "Question id : (" << i.first << ") The question is : " << i.second << '\n';
            ifstream input2("D:\\c++ vs\\Project Ask ME\\answers.txt");
            string line2;
            while (getline(input2, line2)) {
                istringstream iss(line2);
                int Q_id;
                string answer;
                iss >> Q_id >> answer;
                if(Q_id == i.first){
                    cout << "Answer : " << answer << '\n';
                }
            }
            input2.close();

            ifstream inputThread("D:\\c++ vs\\Project Ask ME\\threads.txt");
            string lineThread;
            int t_id;
            while (getline(inputThread, lineThread)) {
                istringstream iss(lineThread);
                int q_id,user_id;
                string thread;
                iss >> t_id >> q_id >> user_id >> thread;
                if(q_id == i.first){
                    cout << "Thread : " << thread << '\n';
                }
            }

            inputThread.close();

            ifstream ans("D:\\c++ vs\\Project Ask ME\\threads_ans.txt");
            string lineAns;
            while (getline(ans, lineAns)) {
                istringstream iss(lineAns);
                int t_id2,q_id;
                string ans_n;
                iss >> t_id2 >> q_id >> ans_n;
                if(q_id == i.first){
                    cout << "Answer : " << ans_n << '\n';
                }
            }
            ans.close();
        }
        //System::showMenu();
    }

    static void askMe(int q_id){
        
        if(q_id == -1){
            cout << "Enter your question : ";
            string q ; cin >> q;
            int q_id = Question::getLastQuestionId();
            //user id 
            int u_id = UserAuth::id;
            Question question(q_id, u_id, q);
            question.saveTofile();
            cout << GREEN << "Question saved successfully\n" << RESET;
        }
        else{
            cout <<"Enter Your thread question : ";
            string q ; cin >> q;
            int t_id = Thread::getLastThreadId();
            //user id 
            int u_id = UserAuth::id;
            Thread thread(t_id, q_id, u_id, q);
            thread.saveTofile();
            cout << GREEN << "Question saved successfully\n" << RESET;
        }
    }

};
