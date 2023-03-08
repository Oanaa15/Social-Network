//
// Created by Oana on 5/22/2022.
//

#include "Console.h"

Console::Console(Network &n) : network(n) {}

void Console::run_menu_user() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "s. Show users." << endl;
        cout << "1. Add an user." << endl;
        cout << "2. Delete an user." << endl;
        cout << "3. Update an user." << endl;
        cout << "x. Close" << std::endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                network.add_user();
                break;
            }
            case 's': {
                network.show_all_users();
                break;
            }
            case '2': {
                network.delete_user();
                break;
            }
            case '3': {
                network.update_user();
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong! Try again!" << endl;
        }

    }

}

void Console::run_menu_friendship() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "s. Show friendships." << endl;
        cout << "1. Add a friendship." << endl;
        cout << "2. Delete a friendship." << endl;
        cout << "3. Update a friendship." << endl;
        cout << "x. Close" << std::endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                network.add_friendship();
                break;
            }
            case 's': {
                network.show_all_friendships();
                break;
            }
            case '2': {
                network.delete_friendship();
                break;
            }
            case '3': {
                network.update_friendship();
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong! Try again!" << endl;
        }

    }
}

void Console::run_menu_messages() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "s. Show messages." << endl;
        cout << "1. Add a message." << endl;
        cout << "2. Delete a message." << endl;
        cout << "x. Close" << std::endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                network.add_message();
                break;
            }
            case 's': {
                network.show_all_message();
                break;
            }
            case '2': {
                network.delete_message();
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong! Try again!" << endl;
        }

    }
}

void Console::run_menu_event() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "s. Show event." << endl;
        cout << "1. Add a event." << endl;
        cout << "2. Delete a event." << endl;
        cout << "3. Update a event." << endl;
        cout << "x. Close" << std::endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                network.add_event();
                break;
            }
            case 's': {
                network.show_all_events();
                break;
            }
            case '2': {
                network.delete_event();
                break;
            }
            case '3': {
                network.update_event();
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong! Try again!" << endl;
        }

    }


}

void Console::run_menu() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "u. Users Menu" << endl;
        cout << "f. Friendships Menu" << endl;
        cout << "m. Message Menu" << endl;
        cout << "e. Events Menu" << std::endl;
        cout << "1. Show my friends." << std::endl;
        cout << "2. Show my messages(sent and received)" << std::endl;
        cout << "x. Close" << std::endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case 'u': {
                run_menu_user();
                break;
            }
            case 'f': {
                run_menu_friendship();
                break;
            }
            case 'm': {
                run_menu_messages();
                break;
            }
            case 'e': {
                run_menu_event();
                break;
            }
            case '1': {
                cout << "Give your id:";
                int id;
                cin >> id;
                cout << endl;
                network.show_my_friends(id);
                break;
            }
            case '2': {
                cout << "Give your id:";
                int id;
                cin >> id;
                cout << endl;
                network.show_all_my_messages(id);
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong! Try again!" << endl;
        }

    }
}


