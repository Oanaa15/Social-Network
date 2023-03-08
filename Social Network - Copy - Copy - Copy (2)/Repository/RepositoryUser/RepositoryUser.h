//
// Created by Oana on 5/14/2022.
//

#ifndef PROIECTSDA_REPOSITORYUSER_H
#define PROIECTSDA_REPOSITORYUSER_H


#include "../../Domain/User.h"
#include "../../Domain/LSI.h"

class RepositoryUser {
private:
    LSI<User> users;
    string filename;
public:
    RepositoryUser();

    RepositoryUser(string fname);

    void save_to_File();

    ~RepositoryUser();

    void add_user(User u);

    void delete_user(User u);

    void modify_user(User u, User new_u);

    int get_size();

    LSI<User> get_all_list();

    User get_by_id(int id);

    std::vector<User> get_all_vector();

};


#endif //PROIECTSDA_REPOSITORYUSER_H
