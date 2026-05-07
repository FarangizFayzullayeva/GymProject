#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class User {
protected:
    int userId;
    char username[30];
    char password[15];
    char email[50];
    char userType[10];       // "Member", "Admin"
    int age;
    double weight;        // in kg
    double height;        // in cm
    char gender;       // "M", "F", "O" (Other)
    char fitnessLevel[15];  // "Beginner", "Intermediate", "Advanced"
    char membershipId[10];
    int experience;      // in years, for trainers
public:
    // getter setters

    int getUserId() const;
    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    string getUserType() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    char getGender() const;
    string getFitnessLevel() const;
    string getMembershipId() const;
    int getExperience() const;
    void setUserId(int IdUser);
    void setUserType(string typeUser);
    void setUsername(string name);
    void setPassword(string passwrd);
    void setEmail(string mail);
    void setAge(int Age);
    void setWeight(double Weight);
    void setHeight(double Height);
    void setGender(char gen);
    void setFitnessLevel(string lvl);
    void setMembershipId(string memId);
    void setExperience(int exp);
    

    // Member Functions
    virtual void displayProfile() const;  // Polymorphism - virtual function
    void updateProfile();
    void deleteProfile();
    // login/register

   User(int IdUser = 0, string typeUser="", string name = "", string passwrd = "", string mail = "", int Age = 0, double Weight = 0.0, double Height = 0.0, char gen = 'O', string lvl = "", string memId = "", int exp = 0) {
        setUserId(IdUser);
        setUserType(typeUser);
        setUsername(name);
        setPassword(passwrd);
        setEmail(mail);
        setAge(Age);
        setWeight(Weight);
        setHeight(Height);
        setGender(gen);
        setFitnessLevel(lvl);
        setMembershipId(memId);
        setExperience(exp);
       
    }
    virtual ~User() {}
};
class Admin : public User {

public:
    void displayProfile() const override;  // Override for Admin profile display
    void manageUsers();  // Admin-specific function to manage users
    void addUser();
    void removeUser();
    void updateUser();
    void reviewUserInfo();
};
class Trainer : public User{
    protected:
    string specialization;   // e.g. "Weight Loss", "Strength", "Cardio"
    int yearsOfExperience;
    vector<string> assignedMembers; // list of user IDs
    double rating;
    double salary;

    public: 
    void displayProfile() const override;
};


void User::setUserId(int IdUser){
    userId = IdUser;
}
void User::setUserType(string typeUser){
    // if(typeUser != "Member" && typeUser != "Admin" && typeUser != "Trainer"){
    //     cout << "Invalid user type! (Recommened checking for typo). Setting to 'Member' by default." << endl;
    //     typeUser = "Member";
    // }else{}
    int length = (typeUser.size() < 10) ? typeUser.size() : 9;
    for (int i = 0; i < length; ++i)
            userType[i]= typeUser[i];
    userType[length] = '\0';
    
}
void User::setUsername(string name){
    int length = (name.size() < 30) ? name.size() : 29;
    for (int i = 0; i < length; ++i)
            username[i] = name[i];
    username[length] = '\0';
    
}
void User::setPassword(string passwrd){

    int length = (passwrd.size() < 15) ? passwrd.size() : 14;
    for (int i = 0; i < length; ++i)
            password[i] = passwrd[i];
    password[length] = '\0';
}
void User::setEmail(string mail){
    int length = (mail.size() < 50) ? mail.size() : 49;
    for (int i = 0; i < length; ++i)
            email[i] = mail[i];
    email[length] = '\0';
}
void User::setAge(int Age){
    // if(Age < 0) {
    //     cout << "Invalid age! Setting your age to 0 by default." << endl;
    //     age = 0;
    // } else
    age = Age;
}
void User::setWeight(double Weight){
    // if(userWeight < 0) {
    //     cout << "Invalid weight! Setting your weight to 0 by default." << endl;
    //     weight = 0;
    // } else
    weight = Weight;
}
void User::setHeight(double Height){
    // if(Height < 0) {
    //     cout << "Invalid height! Setting your height to 0 by default." << endl;
    //     height = 0;
    // } else
    height = Height;
}
void User::setGender(char gen){
    // if(gen != 'M' && gen != 'F' && gen != 'O') {
    //     cout << "Invalid gender! Setting your gender to 'O' (Other) by default." << endl;
    // } else {
        gender = gen;
    // }
}
void User::setFitnessLevel(string lvl){
    // if(level != 'B' && level != 'I' && level != 'A') {
    //     cout << "Invalid fitness level! Setting your fitness level to 'B' (Beginner) by default." << endl;
    //     fitnessLevel = 'B';
    // } else
     int length = (lvl.size() < 15) ? lvl.size() : 14;
    for (int i = 0; i < length; ++i)
            fitnessLevel[i] = lvl[i];
    fitnessLevel[length] = '\0';
    
}
void User::setMembershipId(string memId){
    int length = (memId.size() < 10) ? memId.size() : 9;
    for (int i = 0; i < length; ++i)
            membershipId[i] = memId[i];
    membershipId[length] = '\0';
}
void User::setExperience(int exp){
    experience = exp;
}

int User::getUserId() const {
    return userId;
}
string User::getUsername() const {
    return username;
}
string User::getPassword() const {
    return password;
}   
string User::getEmail() const {
    return email;
}   
string User::getUserType() const {
    return userType;
}
int User::getAge() const {
    return age;
}
double User::getWeight() const {
    return weight;
}
double User::getHeight() const {
    return height;
}
char User::getGender() const {
    return gender;
}
string User::getFitnessLevel() const {
    return fitnessLevel;
}
string User::getMembershipId() const {
    return membershipId;
} 
int User::getExperience() const {
    return experience;
}

