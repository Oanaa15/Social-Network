//
// Created by Oana on 5/18/2022.
//

#ifndef PROIECTSDA_REPOSITORYMESSAGE_H
#define PROIECTSDA_REPOSITORYMESSAGE_H


#include "../../Domain/Message.h"
#include "../../Domain/Multimap.h"

class RepositoryMessage {
private:
    Multimap<int, Message> mp;
    string filename;
public:
    RepositoryMessage();

    RepositoryMessage(string fname);

    void save_to_File();

    ~RepositoryMessage();

    void add_message(Message mes);

    void delete_message(Message mes);

    int get_size();

    std::vector<std::vector<Message>> get_all();




};


#endif //PROIECTSDA_REPOSITORYMESSAGE_H
