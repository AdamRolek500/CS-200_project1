//
// Created by adamrolek500 on 6/5/19.
//

#ifndef BANK_MENU_H
#define BANK_MENU_H

#include <vector>
#include <string>

using namespace std;

class Menu {
    public:
       Menu();
       Menu(string menuName);
       // Utils
       void addOption(string option, void (*f)());
       void run();
    private:
        vector<string> menuOptions;
        vector<void (*)()> menuFunctions;
        string menuName;
};


#endif //BANK_MENU_H
