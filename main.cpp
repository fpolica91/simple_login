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


int main(){
  int choice ;
  cout << "1 Register \n2: Login\n3: Change password\n Your choice: ";
  cin>> choice;
  if(choice == 1){
    string username, password;
    cout << "Select a username: "; cin >> username;
    cout << "Select a password: "; cin >> password;
    ofstream file;
    file.open("data/" + username + ".txt");
    file << username <<endl << password;
    file.close();
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
  }

  return 0;
}