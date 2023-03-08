//
// Created by Oana on 5/22/2022.
//

#include "ServiceFriendship.h"

ServiceFriendship::ServiceFriendship(RepositoryFriendship &r): repo(r) {}

void ServiceFriendship::create_friendship(Friendship f) {
    repo.add_friendship(f);
}

void ServiceFriendship::remove_friendship(Friendship f) {
    repo.delete_friendship(f);
}

void ServiceFriendship::update_friendship(Friendship old_f, Friendship new_f) {
    repo.modify_friendship(old_f, new_f);
}

Friendship ServiceFriendship::get_by_id(int i) {
    return repo.get_by_id(i);
}

std::vector<Friendship> ServiceFriendship::get_all() {
    return repo.get_all();
}


