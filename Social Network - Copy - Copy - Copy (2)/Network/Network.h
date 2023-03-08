//
// Created by Oana on 5/22/2022.
//

#ifndef PROIECTSDA_NETWORK_H
#define PROIECTSDA_NETWORK_H


#include "../Service/ServiceUser/ServiceUser.h"
#include "../Service/ServiceFriendship/ServiceFriendship.h"
#include "../Service/ServiceMessage/ServiceMessage.h"
#include "../Service/ServiceEvent/ServiceEvent.h"

class Network {
private:
    ServiceUser serviceUser;
    ServiceFriendship serviceFriendship;
    ServiceMessage serviceMessage;
    ServiceEvent serviceEvent;

public:
    Network(ServiceUser &serU, ServiceFriendship &serF, ServiceMessage &serM, ServiceEvent &serE);

    void add_user();
    void delete_user();
    void update_user();
    void show_all_users();

    void add_friendship();
    void delete_friendship();
    void update_friendship();
    void show_all_friendships();
    void show_my_friends(int id);

    void add_message();
    void delete_message();
    void show_all_message();
    void show_all_my_messages(int id);

    void add_event();
    void delete_event();
    void update_event();
    void show_all_events();



};


#endif //PROIECTSDA_NETWORK_H
