//
// Created by Oana on 5/18/2022.
//

#include "ServiceUser.h"

ServiceUser::ServiceUser(RepositoryUser &r): repo(r) {}

void ServiceUser::create_user(User u) {
    repo.add_user(u);
}

void ServiceUser::remove_user(User u) {
    repo.delete_user(u);
}

void ServiceUser::update_user(User old_u, User new_u) {
    repo.modify_user(old_u, new_u);
}

std::vector<User> ServiceUser::get_all() {
    return repo.get_all_vector();
}

User ServiceUser::get_by_id(int id) {
    return repo.get_by_id(id);
}
