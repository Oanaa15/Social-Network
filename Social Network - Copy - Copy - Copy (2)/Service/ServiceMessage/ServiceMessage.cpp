//
// Created by Oana on 5/22/2022.
//

#include "ServiceMessage.h"

ServiceMessage::ServiceMessage(RepositoryMessage &r) : repo(r) {}

void ServiceMessage::create_message(Message mes) {
    repo.add_message(mes);
}

void ServiceMessage::remove_message(Message mes) {
    repo.delete_message(mes);
}

std::vector<std::vector<Message>> ServiceMessage::get_all_messages() {
    return repo.get_all();
}

int ServiceMessage::messages_size() {
    return repo.get_size();
}



