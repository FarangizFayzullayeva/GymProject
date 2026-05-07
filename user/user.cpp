#include "user.h"
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
int enterChoiceMenu();
void Register(fstream& outUserInfo);
void Login();
int main(){
fstream outUserInfo("userInfo.dat", ios::in | ios::out | ios::binary);

if (!outUserInfo) {
    ofstream createFile("userInfo.dat", ios::binary);
    User emptyUser;
    for (int i = 0; i < 100; i++) {
        createFile.write(reinterpret_cast<char*>(&emptyUser), sizeof(User));
    }
    createFile.close();
    outUserInfo.open("userInfo.dat", ios::in | ios::out | ios::binary);
}
if (!outUserInfo) {
    cerr << "File could not be opened.\n";
    return 1;
}
   
int choice;
while ((choice = enterChoiceMenu()) != 3) {
    switch(choice){
    case 1:
        Register(outUserInfo);
        break;
    case 2:
        Login();
        break;
    default:
        cout << "Invalid choice! Please try again." << endl;
    break;
    }
}
}
int enterChoiceMenu(){
    int choice;
    cout<< setw (30)<<"WELCOME TO THE FITNEO!  "<<endl;
    cout << setw(36)<< "1.Register" << endl;
    cout << setw(36) << "2.Login" << endl;
    cout << setw(36) << "3.Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
void Register(fstream& outUserInfo){
    string userType, username, password, email, fitLvl, memId;
    int age, expYears, userId;
    char gender;
    double weight,height;
    cout << "Registering a new user..." << endl;
    cout << "\nEnter your User ID: ";
    cin >> userId;
    outUserInfo.clear();
    outUserInfo.seekg((userId - 1) * sizeof(User), ios::beg);
    User user;
    int i = 0;
    outUserInfo.read(reinterpret_cast<char*>(&user), sizeof(User));

    while(user.getUserId() != 0) {
        cout << "Account with the ID #" << userId << " already exists." << endl;
        cout << "Please enter a different User ID: ";
        cin >> userId;
        outUserInfo.clear();
        outUserInfo.seekg((userId - 1) * sizeof(User), ios::beg);
        outUserInfo.read(reinterpret_cast<char*>(&user), sizeof(User));

    }

    cout << "\nEnter your User Type(Member/Admin/Trainer): ";
    cin >> userType;
    while(userType != "Member" && userType != "Admin" && userType != "Trainer"){
        cout << "Invalid input!  Try again... (Recommened checking for typo)." << endl;
        cin >> userType;
    }
    cout << "\nEnter your Username: ";
    cin >> username;
    cout << "\nEnter your Password: ";
    cin >> password;
    while(password.size() < 8){
        cout<< "Password should contain at least 8 characters! Try again..." << endl;
        cin >> password;
    }
    cout << "\nEnter your Email: ";
    cin >> email;
// #include <regex>
// bool isValidEmail(const string& email) {
//     const regex pattern(R"(^[\w\.-]+@[\w\.-]+\.[a-zA-Z]{2,}$)");
//     return regex_match(email, pattern);
// }
//     while(!isValidEmail(email)){
//         cout << "Invalid email format! Try again." << endl;
//         cin >> email;
//     }

    cout << "\nEnter your Age: ";
    cin >> age;
    while(age<0 || age>100){
        cout<< "Invalid input! Your age must be between 0 and 100. Try again..." << endl;
        cin >> age;
    }
    cout << "\nEnter your Weight(kg): ";
    cin >> weight;
    while(weight<0){
        cout<< "Invalid input! Your weight must be a positive number. Try again..." << endl;
        cin >> weight;
    }
    cout << "\nEnter your Height(cm): ";
    cin >> height;
    while(height<0){
        cout<< "Invalid input! Your height must be a positive number. Try again..." << endl;
        cin >> height;
    }
    cout << "\nEnter your Gender( F(Female)/ M(Male)/ O(Other) ): ";
    cin >> gender;
    while(gender != 'M' &&gender != 'F' && gender!= 'O'){
        cout<< "Invalid input! Try again..." << endl;
        cin >> gender;
    }
    cout << "\nEnter your Fitness Level(Beginner/Intermediate/Advanced): ";
    cin >> fitLvl;
    while(fitLvl != "Beginner" && fitLvl !="Intermediate" && fitLvl!= "Advanced"){
        cout << "Invalid input! Try again..." << endl;
        cin >> fitLvl;
    }
    cout << "\nEnter your Membership ID: ";
    cin >> memId;
    cout << "\nEnter your Years of Experience at a gym (0 if less than 12 months): ";
    cin >> expYears;
    while(expYears > age || expYears < 0){
        cout<< "Invalid input! Try again..." << endl;
        cin >> expYears;
    }
User newUser(userId, userType, username, password, email, age, weight, height, gender, fitLvl, memId, expYears);
  outUserInfo.seekp((userId - 1) * sizeof(User), ios::beg);

        outUserInfo.write(reinterpret_cast< char*>(&newUser), sizeof(User));
}

void initializeFile(fstream& file) {
    file.clear();
    file.seekp(0);

    User emptyUser; // default user = empty record

    for (int i = 0; i < 100; i++) {
        file.write(reinterpret_cast<char*>(&emptyUser), sizeof(User));
    }
}