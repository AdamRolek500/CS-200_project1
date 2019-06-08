#include <iostream>
#include <typeinfo>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "logger.h"
#include "menu.h"

#include "teller.h"
#include "client.h"
#include "admin.h"


using namespace std;

void audit();
bool login();
void addClient();
void addAdmin();
void addTeller();
void deposit();
void withdraw();
void seeAccount();
void save();
void load();
string decrypt(string to_decrypt, char key);
Person* chooseClient();

vector<Person*> persons;
Person *currentUser;

int main()
{
	load();
	save();
    Menu main("Main Menu");
	
	// Login System
	bool loggedIn = false;
	do {
		loggedIn = login();
	} while (!loggedIn);
	
	cout << "Welcome " << currentUser->getName() << endl;
	
	// Allowing user to see options based on type
	if(currentUser->getType() == "admin"){
	    main.addOption("Audit", audit);
	    main.addOption("Add Admin", addAdmin);
	    main.addOption("Add Teller", addTeller);
		main.addOption("Add Client", addClient); 
	}else if(currentUser->getType() == "teller"){
	    main.addOption("Audit", audit);
		main.addOption("Add Client", addClient);
		main.addOption("Deposit", deposit);
		main.addOption("Withdraw", withdraw);
	}else{
		main.addOption("See Account", seeAccount);
		main.addOption("Deposit", deposit);
		main.addOption("Withdraw", withdraw);
	}

    while(1)
        main.run();
}

string decrypt(string to_decrypt, char key){
    size_t pos = 0;
    std::string token;
    string delimiter = " ";
    string output = "";
    while ((pos = to_decrypt.find(delimiter)) != std::string::npos) {
        token = to_decrypt.substr(0, pos);
        output += (char)stoi(token) ^ key;
        to_decrypt.erase(0, pos + delimiter.length());
    }
    return output;
}

void save(){
	ofstream outfile;
    outfile.open("data.txt");
    vector<Person*>::iterator personPTR; 
	for (personPTR = persons.begin(); personPTR < persons.end(); personPTR++) 
        outfile << (*personPTR)->save();
}

void load(){
	ifstream infile; 
	infile.open("data.txt"); 
	string s, name, dob, username, password;
	int id;
	double ac1, ac2, pay;
	
	while(!infile.eof()){
		getline(infile, s);
		if(s == "teller"){
			getline(infile, name);
			getline(infile, dob);
			getline(infile, username);
			getline(infile, password);
			infile >> pay;
			persons.push_back(new Teller(decrypt(name, 'k'), decrypt(dob, 'k'), decrypt(username, 'k'), decrypt(password, 'k'), pay));
		}else if(s == ""){
			
		}else if(s == "admin"){
			getline(infile, name);
			getline(infile, dob);
			getline(infile, username);
			getline(infile, password);
			infile >> pay;
			persons.push_back(new Admin(decrypt(name, 'k'), decrypt(dob, 'k'), decrypt(username, 'k'), decrypt(password, 'k'), pay));
		}else{
			getline(infile, name);
			getline(infile, dob);
			getline(infile, username);
			getline(infile, password);
			infile >> id;
			infile >> ac1;
			infile >> ac2;
			persons.push_back(new Client(decrypt(name, 'k'), decrypt(dob, 'k'), decrypt(username, 'k'), decrypt(password, 'k'), id, ac1, ac2));
		}
	}
}

void seeAccount(){
	cout << static_cast<Client*>(currentUser)->getDetails() << endl;
}

Person* chooseClient(){
	vector<Person*>::iterator personPTR; 
	string name;
	
	cout << "Enter Name of Client > ";
	cin.ignore();
	getline(cin, name);
	
	for (personPTR = persons.begin(); personPTR < persons.end(); personPTR++) {
		if((*personPTR)->getType() == "client" && (*personPTR)->getName() == name){
			cout << "Found!" << endl;
        	return (*personPTR);
		}	
	}
	cout << "Not Found!" << endl;
}

void deposit(){
	if(currentUser->getType() == "client"){
		static_cast<Client*>(currentUser)->makeTransaction();
		return;
	}
	Person* cl = chooseClient();
	static_cast<Client*>(cl)->makeTransaction();
}

void withdraw(){
	if(currentUser->getType() == "client"){
		static_cast<Client*>(currentUser)->makeTransaction();
		return;
	}
	Person* cl = chooseClient();
	static_cast<Client*>(cl)->makeTransaction();
}

void audit(){
    cout << "===== Audit =====" << endl;
    vector<Person*>::iterator personPTR; 
	for (personPTR = persons.begin(); personPTR < persons.end(); personPTR++) 
        cout << (*personPTR)->getDetails() << endl << endl;
}

bool login(){
	string username, password;
	cout << "Enter Username > ";
	cin >> username;
	cout << "Enter Password > ";
	cin >> password;
	
	vector<Person*>::iterator personPTR; 
	for (personPTR = persons.begin(); personPTR < persons.end(); personPTR++) 
        if((*personPTR)->login(username, password)){
        	currentUser = (*personPTR);
        	return true;
		}
    return false;
}

void addClient(){
	string name, dob, username, password;
	double ac1, ac2;
	int id;
	
	cout << "Enter Name > ";
	cin.ignore();
	getline(cin, name);
	
	cout << "Enter Date of Birth > ";
	getline(cin, dob);
	
	cout << "Enter Username > ";
	getline(cin, username);
	
	cout << "Enter Password > ";
	getline(cin, password);
	
	cout << "Enter ID > ";
	cin >> id;
	
	cout << "Enter Checkings Balnce > ";
	cin >> ac1;
	
	cout << "Enter Savings Balnce > ";
	cin >> ac2;
	
	persons.push_back(new Client(name, dob, username, password, id, ac1, ac2));
}

void addAdmin(){
	string name, dob, username, password;
	double pay;
	
	cout << "Enter Name > ";
	cin.ignore();
	getline(cin, name);
	
	cout << "Enter Date of Birth > ";
	getline(cin, dob);
	
	cout << "Enter Username > ";
	getline(cin, username);
	
	cout << "Enter Password > ";
	getline(cin, password);
	
	cout << "Enter Pay > ";
	cin >> pay;
	
	persons.push_back(new Admin(name, dob, username, password, pay));
}

void addTeller(){
	string name, dob, username, password;
	double pay;
	
	cout << "Enter Name > ";
	cin.ignore();
	getline(cin, name);
	
	cout << "Enter Date of Birth > ";
	getline(cin, dob);
	
	cout << "Enter Username > ";
	getline(cin, username);
	
	cout << "Enter Password > ";
	getline(cin, password);
	
	cout << "Enter Pay > ";
	cin >> pay;
	
	persons.push_back(new Teller(name, dob, username, password, pay));
}

