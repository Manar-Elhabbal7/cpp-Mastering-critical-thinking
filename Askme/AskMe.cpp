#include <bits/stdc++.h>
#include "h_thread.h"
#include "h_user.h"
#include "h_questions.h"
#include "h_answer.h"
#include "userauth.h"
#include "system.h"
using namespace std;


int main() {
    UserAuth auth;
    auth.Menu();
    System s; 
    if(UserAuth::status){
        s.showMenu();
        s.choose();
    }
        
    return 0;
}
//author : The GOAT
/*
the bugs untill now :
    //1 : in function answer question it can be a thread or a question
    //sol : can make another one for answer thread 
    //solved by using a new file for just threads answers

    //2: when i need to call show Menu can not as the implemention is not upove it
    //sol : i can seperate all of classes in headers
    //solve by the goat 

    3: not done (funtion feed )

    4: ask question i can ask thread (shown in pdf )

    5.problem in function AskMe about UserAuth::status

    6. in print all not print the answer of thread
*/