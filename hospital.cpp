#include<bits/stdc++.h>
using namespace std;
const string admin ="ManarElhabbal";
const string pass = "manarelhabbal619";
map<int,deque<string>> mp; //specialization : info
void addPatient(){
    string sen;int sp;
    cout <<"Enter Specialization , name , status : \n";
    cin >>sp;
    cin.ignore(); 
    getline(cin,sen);
    stringstream ss;
    string name;bool status;
    ss << sen;
    ss >> name >> status;

    if(mp[sp].size()==5){
        cout <<"Sorry this specialization is Full now.\n";
        return;
    }
    
    if(status){
        mp[sp].push_front(name +" urgent");
    }
    else{
        mp[sp].push_back(name +" normal");
    }
}
void printAllPatients(){
    for(auto &i:mp){
        cout <<"------------------------------------------------------------\n";
        cout << "There are "<<i.second.size()<<" Patients"<<" In the specialization "<<i.first<< "\n";
        
        for(auto &j:i.second){
            cout << j << "\n";
        }
        
    }
}
void pick(){
    int sp;
    cout <<"Enter Specialization [1-5] : \n";
    cin >> sp;
    if(sp<1 || sp>5){
        cout <<"Invalid Specialization.\n";
        return;
    }
    if(mp[sp].empty()){
        cout <<"No patient available ,Rest Ya doctor .\n";
        return;
    }
    stringstream ss;
    string name;
    ss << mp[sp].front();
    ss >> name;
    mp[sp].pop_front();
    cout <<"Doctor picked : " << name << "\n";
}
void Exit(){
    cout <<"See You Later ...\n";
    exit(0);
}
void menu(){
    cout <<"---------- Welcome to Our Hospital ----------\n";
    cout <<"[1] Add patient .\n";
    cout <<"[2] Print All patients. \n";
    cout <<"[3] Pick a patient for A doctor. \n";
    cout <<"[4] Exit.\n";
    cout << "-------------------------------------------\n";
    int ch {0}; cout <<"Enter a choice please \n";
    cin >> ch;
    switch(ch){
    case 1:addPatient(); break;
    case 2:printAllPatients(); break;
    case 3:pick(); break;
    case 4:Exit(); break;
    default: cout << "Invalid choice.\n"; break;
    }
}
void system(){
    while(true){
        menu();
    }
}
signed main(){
    string username,password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if(username == admin && password == pass){
        system();
    }
    else{
        cout << "Invalid username or password.\n";
    }
    return 0;
}
