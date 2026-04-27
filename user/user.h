#include <string>

using namespace std;

class User {
protected:
    string userId;
    string username;
    string password;
    string email;
    string userType;       // "Member", "Admin"
    int age;
    double weight;        // in kg
    double height;        // in cm
    string gender;
    string fitnessLevel;  // "Beginner", "Intermediate", "Advanced"
    string membershipId;
    string experience;
public:
    // getter setters
    string getUserId() const;
    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    string getUserType() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    string getGender() const;
    string getFitnessLevel() const;
    string getMembershipId() const;
    string getExperience() const;
    void setUserId();
    void setUserType();
    void setUsername();
    void setPassword();
    void setEmail();
    void setAge();
    void setWeight();
    void setHeight();
    void setGender();
    void setFitnessLevel();
    void setMembershipId();
    void setExperience();

    // Member Functions
    virtual void displayProfile() const;  // Polymorphism - virtual function
    void updateProfile();
    // login/register
    virtual ~User() {}
};
class Admin : public User {
public:
    void displayProfile() const override;  // Override for Admin profile display
    void manageUsers();  // Admin-specific function to manage users
};
