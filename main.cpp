#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>



using namespace std;

bool isLoggedIn(){
  string username, password, un, pw;
  cout << "Enter username: ";
  cin  >> username;
  cout << "enter password: ";
  cin >> password;
  ifstream read("data/" + username + ".txt");
  getline(read, un);
  getline(read, pw);
  if(un == username && pw == password){
    return true;
  }
  else {
    return false;
  }
}



void change_password(){
  string username;
  string oldPassword;
  string usr;
  string pwd;
  string new_password;
  cout << "Please enter you username: "; cin>> username;
  cout<< "Please enter your current password: \n"; cin >> oldPassword;
  ifstream read("data/" + username + ".txt");
  getline(read, usr);
  getline(read, pwd);
  if(username == usr && oldPassword == pwd ){
    cout << " Enter your new password: "; cin>> new_password;
    ofstream file;
    file.open("data/" + username + ".txt");
    file << username <<endl <<new_password;
    file.close();
    cout << "Password successfully changed \n";
  }else{
    cout << "Incorrect Password ";
    system("read -n 1 -s -p \"press 3 to try again!...\"");
  }

}

void create_bank_account(){
  if(isLoggedIn()){
    string account_number, username;
    int account_pin;
    cout << "enter username "; cin>> username;
    cout << "enter account number "; cin>> account_number;
    cout << "enter account pin "; cin>> account_pin;
    ofstream file;
    file.open("data/" + username + "acct" + ".txt");
    file << account_number<<endl << account_pin;
    file.close();
    cout << "account succesfully created";
  }else{
    cout << "you need to be logged in to create an account \n";
  }
}

void create_account(){
   string username, password;
    cout << "Select a username: "; cin >> username;
    cout << "Select a password: "; cin >> password;
    ofstream file;
    file.open("data/" + username + ".txt");
    file << username <<endl << password;
    file.close();
}


void make_deposit(){
  string username;
  string pin;
  int amount;


}

int main(){
  
  int choice ;
  cout << "1 Register \n2: Login\n3: Change password\n4 Create Account\nYour choice: ";
  cin>> choice;
  if(choice == 1){
    create_account();
    main();
  } else if(choice == 2){
    bool status = isLoggedIn();
    if(!status){
      cout << "Login Incorrect"<<endl;
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      return 0;
    }
    else {
      cout << "Successully logged in"<<endl;
      system("read -n 1 -s -p \"press any key to continue...\"");
      return 1;
    }
  }else if(choice == 3){
    change_password();
  }else if(choice == 4){
    create_bank_account();
  }

  return 0;
}