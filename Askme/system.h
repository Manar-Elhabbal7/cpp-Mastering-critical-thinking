#pragma once
#include <bits/stdc++.h>
#include "h_user.h"
#include "h_questions.h"
#include "h_thread.h"
#include "h_answer.h"
#include "userauth.h"
using namespace std;
#include "colors.h"

class System {
public:
    static void showMenu() {
        cout << YELLOW << "======= Main Menu =======\n";
        //done
        cout << BLUE << "1: Print Questions To Me\n"; 
        //done
        cout <<  "2: Print Questions From Me\n";
        //done
        cout <<  "3: Answer Question\n";
        //done
        cout <<  "4: Answer Thread\n";
        //done
        cout <<  "5: Delete Question\n";
        //on a thread or not on a thread mmmm
        cout << "6: Ask Question\n";
        //done
        cout << "7: List System Users\n";
        //missunderstand
        cout << "8: Feed\n";
        //done
        cout << "9: Log Out\n" << RESET;
        cout << YELLOW << "=========================\n" << RESET;
    }
    void choose(){
        int choice ; 
        cout <<"Enter number in range 1-8 : ";
        cin >> choice ;
        
            switch (choice) {
                case 1:
                Question::print_all();
                break;

                case 2:{
                    int id = UserAuth::id;
                    Question::print_my_questions(id);
                    break;
                }

                case 3: {
                    cout  << "Enter Question ID: ";
                    int question_id ; cin >> question_id ;
                    Question::answer_question(question_id);
                    break;
                }
                //not tested
                case 4:{
                    cout  << "Enter Thread ID: ";
                    int thread_id ; cin >> thread_id ;
                    cout  << "Enter Question ID: ";
                    int i_q ; cin >> i_q ;
                    
                    Thread::answer_thread(thread_id,i_q);
                    break;
                }

                break;

                case 5:{
                    cout  << "Enter Question ID: ";
                    int question_id ; cin >> question_id ;
                    Question::delete_Question(question_id);
                    break;
                }
                
                //not tested
                case 6:{
                    // cout <<"Enter question id to ask a thread or -1 to ask new question  : ";
                    // int q_id ; cin >> q_id ;
                    // Question::askMe(q_id);
                    break;
                }
                

                case 7:
                User::List_System_Users();
                break;

                case 8:
                //feed
                break;

                case 9:
                UserAuth::logout();
                break;

                default:
                    cout << RED <<"Error : invalid number .... Try Again\n";
                    showMenu();
            }
            
        
    }
};
