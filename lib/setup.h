#ifndef SETUP_H
#define SETUP_H

#include "infLib.h"

using namespace std;

int setup() {
    writeFile("data/setupData.inf", "");
    cout << "Welcome to InfOS Setup!" << endl;
    cout << "Press any key to continue." << "\n" <<endl;
    getch();

    cout << "What would be the name of this computer?" << endl;
    string computerName;
    cin >> computerName;
    writeLine("data/setupData.inf", 1 , computerName);

    cout << "What would be the name of this user?" << endl;
    string userName;
    cin >> userName;
    writeLine("data/setupData.inf", 2 , userName);

    cout << "Add a keyword for this system? If you dont want to add you can just skip this." << endl;
    string keyword;
    cin >> keyword;
    writeLine("data/setupData.inf", 3 , keyword);

    cout << endl;
    cout << "Setup is complete! Closing your system in 3 seconds..." << endl;
    wait(3);

    return 0;
}

#endif