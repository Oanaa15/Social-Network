//
// Created by Oana on 5/22/2022.
//

#include "Network.h"
#include <string>

Network::Network(ServiceUser &serU, ServiceFriendship &serF, ServiceMessage &serM, ServiceEvent &serE) : serviceUser(
        serU),
                                                                                                         serviceFriendship(
                                                                                                                 serF),
                                                                                                         serviceMessage(
                                                                                                                 serM),
                                                                                                         serviceEvent(
                                                                                                                 serE) {}

void Network::add_user() {
    User user;
    cin >> user;
    int ok = 1;
    for (auto &u: serviceUser.get_all()) {
        if (u == user || user.get_id() == u.get_id()) {
            ok = 0;
        }
    }
    if (ok == 0) {
        cout << "There is already a user with given id!";
    } else
        serviceUser.create_user(user);
}

void Network::delete_user() {
    cout << "Give the id of the user you want to delete:" << endl;
    int id, ok = 0;
    cin >> id;
    for (auto &u: serviceUser.get_all()) {
        if (id == u.get_id()) {
            serviceUser.remove_user(u);
            ok = 1;
        }
    }
    if (ok == 0)
        cout << "There is no user with given id!";

}

void Network::update_user() {
    cout << "Give the id of the user you want to update:" << endl;
    int id, ok = 0;
    cin >> id;
    cout << "Give the new updated user:" << endl;
    User user;
    cin >> user;
    for (auto &u: serviceUser.get_all()) {
        if (id == u.get_id()) {
            serviceUser.update_user(u, user);
            ok = 1;
        }
    }
    if (ok == 0)
        cout << "There is no user with given id!";

}

void Network::show_all_users() {
    for (auto &u: serviceUser.get_all()) {
        cout << u;
    }
}

void Network::add_friendship() {
    cout << "Add a friendship!These are the users!" << endl;
    show_all_users();
    cout << endl;
    Friendship friendship;
    cin >> friendship;
    int ok = 0;
    for (auto &u: serviceUser.get_all()) {
        if (friendship.get_receiver() == u.get_id() || friendship.get_sender() == u.get_id()) {
            ok++;
        }
    }
    if (ok == 2) {
        for (auto &fr: serviceFriendship.get_all())
            if (fr == friendship)
                ok = 0;
        if (ok != 0)
            serviceFriendship.create_friendship(friendship);
        }
    else
        cout << "There is no user with given id! There must be 2 existent users to create a friendship!";

    }


void Network::delete_friendship() {
    cout << "Give the id of the friendship you want to delete:" << endl;
    int id, ok = 0;
    cin >> id;
    for (auto &fr: serviceFriendship.get_all()) {
        if (id == fr.get_id()) {
            serviceFriendship.remove_friendship(fr);
            ok = 1;
        }
    }
    if (ok == 0)
        cout << "There is no friendship with given id!";
}

void Network::update_friendship() {
    cout << "Give the id of the friendship you want to update:" << endl;
    int id, ok = 0;
    cin >> id;
    cout << "Give the new updated friendship:" << endl;
    Friendship friendship;
    cin >> friendship;
    for (auto &fr: serviceFriendship.get_all()) {
        if (id == fr.get_id()) {
            serviceFriendship.update_friendship(fr, friendship);
            ok = 1;
        }
    }
    if (ok == 0)
        cout << "There is no user with given id!";

}

void Network::show_all_friendships() {
    for (auto &fr: serviceFriendship.get_all()) {
        cout << fr;

    }
}

void Network::add_message() {
    cout << "Sent a message!" << endl;
    cout << "Give the id of the message:";
    int i;
    cin >> i;
    int id1;
    cout << "Give your id:";
    cin >> id1;
    int id2;
    cout << "Give the id of the person you want to send a message:";
    cin >> id2;
    int ok = 0;
    for (auto &u: serviceUser.get_all()) {
        if (id1 == u.get_id() || id2 == u.get_id()) {
            ok++;
        }
    }
    if (ok == 2) {
        cout << "Type your message:";
        string mesaj;
        //string bufferedMessage;
        std::getline(std::cin, mesaj);
        std::getline(std::cin, mesaj);

        Message new_message(i, id1, id2, mesaj);
        for (auto &messages: serviceMessage.get_all_messages())
            for (auto &m: messages)
                if (m == new_message || m.get_id() == new_message.get_id())
                    ok = 0;
        if (ok != 0)
            serviceMessage.create_message(new_message);
    } else
        cout << "There is no user with given id! There must be 2 existent users for a message to be sent!";

}

void Network::show_all_message() {
    for (auto &mes: serviceMessage.get_all_messages()) {
        for (auto &m: mes) {
            cout << m;
        }

    }
}

void Network::delete_message() {
    cout << "Give the id of the message you want to delete:";
    int idtoDelete;
    cin >> idtoDelete;
    int ok = 0;
    for (auto &mes: serviceMessage.get_all_messages()) {
        for (auto &m: mes) {
            if (idtoDelete == m.get_id()) {
                ok = 1;
                serviceMessage.remove_message(m);
            }

        }
    }
    if (ok == 0)
        cout << "There is no message with given id!";
}

void Network::add_event() {
    Event event;
    cin >> event;
    int ok = 1;
    for (auto &u: serviceEvent.get_all()) {
        if (event.get_id() == u.get_id()) {
            ok = 0;
        }
    }
    for (auto &e: serviceEvent.get_all()) {
        if (event.get_id() == e.get_id()) {
            ok = 0;
        }
    }
    if (ok == 0)
        cout << "There is already a user with given id!";
    else {
        serviceEvent.create_event(event);
    }

}

void Network::delete_event() {
    cout << "Give the id of the event you want to delete:";
    int id_event, ok = 0;
    cin >> id_event;
    for (auto &e: serviceEvent.get_all()) {
        if (id_event == e.get_id()) {
            ok = 1;
            serviceEvent.remove_event(e);
        }
    }
    if (ok == 0)
        cout << "There is no event with given id!";
}

void Network::update_event() {
    cout << "Give the id of the event you want to update:";
    int id_event;
    cin >> id_event;
    int ok = 0;
    Event event;
    cin >> event;
    int ok1 = 0;
    for (auto &u: serviceEvent.get_all()) {
        if (event.get_id() == u.get_id()) {
            ok1 = 1;
        }
    }
    if (ok1 == 1)
        for (auto &e: serviceEvent.get_all()) {
            if (id_event == e.get_id()) {
                ok = 1;
                serviceEvent.update_event(e, event);
            }
        }
    if (ok == 0)
        cout << "There is no event with given id!";


}

void Network::show_all_events() {
    for (auto &e: serviceEvent.get_all()) {
        cout << e;
    }

}

void Network::show_my_friends(int id) {
    int ok = 0;
    for (auto &u: serviceUser.get_all()) {
        if (u.get_id() == id)
            ok = 1;
    }
    if (ok == 1) {
        int ok1 = 0;
        for (auto &fr: serviceFriendship.get_all()) {
            if (id == fr.get_receiver()) {
                User u = serviceUser.get_by_id(fr.get_sender());
                cout << u;
                ok1 = 1;
            }
            if (id == fr.get_sender()) {
                User u2 = serviceUser.get_by_id(fr.get_receiver());
                cout << u2;
                ok1 = 1;
            }
        }
        if (ok1 == 0) {
            cout << "Sorry! Your friend list is empty!";
        }
    } else
        cout << "There is no user with such id!";

}

void Network::show_all_my_messages(int id) {
    int ok = 0;
    for (auto &u: serviceUser.get_all()) {
        if (u.get_id() == id)
            ok = 1;
    }
    if (ok == 1) {
        int ok1 = 0;
        for (auto &mes: serviceMessage.get_all_messages()) {
            for (auto &m: mes) {
                if (id == m.get_sender() || id == m.get_receiver())
                    cout << m;
                ok1 = 1;
            }
        }
        if (ok1 == 0) {
            cout << "You have no messages sent or received!";
        }
    } else
        cout << "There is no user with such id!";

}



