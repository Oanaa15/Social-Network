//
// Created by Oana on 5/22/2022.
//

#ifndef PROIECTSDA_SERVICEMESSAGE_H
#define PROIECTSDA_SERVICEMESSAGE_H


#include "../../Repository/RepositoryMessage/RepositoryMessage.h"

class ServiceMessage {
private:
    RepositoryMessage repo;

public:
    ServiceMessage(RepositoryMessage &r);

    void create_message(Message mes);

    void remove_message(Message mes);

    std::vector<std::vector<Message>> get_all_messages();

    int messages_size();







};


#endif //PROIECTSDA_SERVICEMESSAGE_H
