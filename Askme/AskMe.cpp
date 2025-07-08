#include <bits/stdc++.h>
#include "h_thread.h"
#include "h_user.h"
#include "h_questions.h"
#include "h_answer.h"
#include "userauth.h"
#include "system.h"
using namespace std;

//Author : The Goat 
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

