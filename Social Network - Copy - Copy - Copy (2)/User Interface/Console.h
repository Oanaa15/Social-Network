//
// Created by Oana on 5/22/2022.
//

#ifndef PROIECTSDA_CONSOLE_H
#define PROIECTSDA_CONSOLE_H


#include "../Network/Network.h"

class Console {
private:
    Network network;

public:
    Console(Network &n);

    void run_menu_user();

    void run_menu_friendship();

    void run_menu_messages();

    void run_menu_event();

    void run_menu();


};


#endif //PROIECTSDA_CONSOLE_H
