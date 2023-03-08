//
// Created by Oana on 5/18/2022.
//

#ifndef PROIECTSDA_SERVICEUSER_H
#define PROIECTSDA_SERVICEUSER_H


#include "../../Repository/RepositoryUser/RepositoryUser.h"

class ServiceUser {
private:
    RepositoryUser repo;

public:
    ServiceUser(RepositoryUser &r);

    void create_user(User u);

    void remove_user(User u);

    void update_user(User old_u, User new_u);

    std::vector<User> get_all();

    User get_by_id(int id);





};


#endif //PROIECTSDA_SERVICEUSER_H
