#include <iostream>
#include <typeinfo>
#include "person.h"
#include "teller.h"

using namespace std;

int main()
{
    Person p1("test test", "55/55/5555", "testname", "testpass");
    Teller t1("test test", "55/55/5555", "testname", "testpass", 18.5);
//    //Person p1;
//    cout << p1.getDetails() << endl
//         << endl
//         << t1.getDetails() << endl;
//
//    cout << p1.getName() << endl
//         << endl
//         << t1.getName() << endl;
//
//    t1.setName("New Name");
    p1.setName("NEW NAME");
//
//    cout << p1.getDetails() << endl
//         << endl
//         << t1.getDetails() << endl;

    // Polymorphism
    Person* ps[2];
    ps[0] = &t1;
    ps[1] = &p1;

    for(int i = 0; i < 2; i++){
        cout << ps[i]->getDetails();
        cout << endl;
    }

    return 0;
}
