#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, string dob, string username, string password);

    string getName();
    void setName(string name);

    string getDOB();
    void setDOB(string dob);

    string getUsername();
    void setUsername(string username);
    
	string getPassword(); 
    void setPassword(string password);

    bool login(string username, string password);

    virtual string getDetails();

private:
    string name;
    string dob;
    string username;
    string password;
};

#endif // PERSON_H
