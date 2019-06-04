#include <iostream>
#include "person.h"
#include "teller.h"

using namespace std;

int main()
{
    Person p1("test test", "55/55/5555", "testname", "testpass");
    Teller t1("test test", "55/55/5555", "testname", "testpass", 18.5);
    //Person p1;
    cout << p1.getDetails() << endl
         << endl
         << t1.getDetails() << endl;
    return 0;
}
