//
// Created by Oana on 5/22/2022.
//

#ifndef PROIECTSDA_SERVICEFRIENDSHIP_H
#define PROIECTSDA_SERVICEFRIENDSHIP_H


#include "../../Repository/RepositoryFriendship/RepositoryFriendship.h"

class ServiceFriendship {
private:
    RepositoryFriendship repo;
public:
    ServiceFriendship(RepositoryFriendship &r);

    void create_friendship(Friendship f);

    void remove_friendship(Friendship f);

    void update_friendship(Friendship old_f, Friendship new_f);

    Friendship get_by_id(int i);

    std::vector<Friendship> get_all();


};


#endif //PROIECTSDA_SERVICEFRIENDSHIP_H
