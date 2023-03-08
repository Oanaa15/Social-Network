//
// Created by Oana on 5/16/2022.
//

#ifndef PROIECTSDA_REPOSITORYFRIENDSHIP_H
#define PROIECTSDA_REPOSITORYFRIENDSHIP_H


#include "../../Domain/LSI.h"
#include "../../Domain/Friendship.h"

class RepositoryFriendship {
private:
    LSI<Friendship> list;
    string filename;
public:
    RepositoryFriendship();

    RepositoryFriendship(string fname);

    ~RepositoryFriendship();

    void add_friendship(Friendship fr);

    void delete_friendship(Friendship fr);

    void modify_friendship(Friendship old_fr, Friendship new_fr);

    int get_size();

    std::vector<Friendship> get_all();

    Friendship get_by_id(int i);

    void save_to_File();


};


#endif //PROIECTSDA_REPOSITORYFRIENDSHIP_H
