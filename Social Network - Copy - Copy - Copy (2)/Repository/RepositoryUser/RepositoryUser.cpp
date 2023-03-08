//
// Created by Oana on 5/14/2022.
//

#include <vector>
#include <fstream>
#include "RepositoryUser.h"

RepositoryUser::RepositoryUser() = default;

RepositoryUser::~RepositoryUser() = default;

void RepositoryUser::add_user(User u) {
    users.add(u);
    this->save_to_File();

}

void RepositoryUser::delete_user(User u) {
    users.remove(u);
    this->save_to_File();
}

int RepositoryUser::get_size() {
    return users.size();
}

User RepositoryUser::get_by_id(int id) {
    for(auto& u: users.get_all()){
        if(id == u.get_id())
            return u;
    }
    throw std::runtime_error("Id was not found!!");
}

LSI<User> RepositoryUser::get_all_list() {
    return users;
}

void RepositoryUser::modify_user(User u, User new_u) {
    users.modify(u, new_u);
    this->save_to_File();
}

std::vector<User> RepositoryUser::get_all_vector() {
    return users.get_all();
}

RepositoryUser::RepositoryUser(string fname) {
    this->filename = fname;
    ifstream f(fname);
    while(f.is_open()){
        int id, age;
        string first_name, last_name, mail;
        f >> id >> first_name >> last_name >> mail >> age;
        if(!first_name.empty() && !last_name.empty() && !mail.empty()){
            User u(id, first_name, last_name, mail, age);
            users.add(u);
        }
        if(f.eof())
            f.close();
    }
}


void RepositoryUser::save_to_File() {
    ofstream g(this->filename);
    for (auto &u: users.get_all()){
        g << u << endl;
    }
    g.close();
}



