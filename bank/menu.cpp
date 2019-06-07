//
// Created by adamrolek500 on 6/5/19.
//

#include <iostream>
#include "menu.h"

Menu::Menu() {

}

Menu::Menu(string menuName) {
    this->menuName = menuName;
}

void Menu::addOption(string option, void (*f)()) {
    this->menuOptions.push_back(option);
    this->menuFunctions.push_back(f);
}

void Menu::run() {
    int i;

    cout << "==== " + this->menuName + " ====" << endl;
    for(i = 0; i < this->menuOptions.size(); i++){
        cout << "\t" << i << ") " << this->menuOptions[i] << endl;
    }
    cout << "\t" << i << ") Exit" << endl;
    cout << "Enter your choice > ";
    cin >> i;

    if (i == this->menuOptions.size()){
        cout << "Goodbye!" << endl;
        exit(0);
    } else if (i < 0 || i > this->menuOptions.size()) {
        return;
    } else {
        this->menuFunctions[i]();
    }
}
