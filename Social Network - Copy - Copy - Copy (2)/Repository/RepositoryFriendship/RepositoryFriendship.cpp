//
// Created by Oana on 5/16/2022.
//

#include <fstream>
#include <iostream>
#include "RepositoryFriendship.h"

RepositoryFriendship::RepositoryFriendship() = default;

RepositoryFriendship::~RepositoryFriendship() = default;

void RepositoryFriendship::add_friendship(Friendship fr) {
    int ok= 1;
    for(auto& f : get_all())
        if(f == fr)
            ok = 0;
    if(ok == 1){
        list.add(fr);
        this->save_to_File();
    }
}

int RepositoryFriendship::get_size() {
    return list.size();
}

void RepositoryFriendship::delete_friendship(Friendship fr) {
    list.remove(fr);
    this->save_to_File();
}

void RepositoryFriendship::modify_friendship(Friendship old_fr, Friendship new_fr) {
    list.modify(old_fr, new_fr);
    this->save_to_File();
}

RepositoryFriendship::RepositoryFriendship(string fname) {
    this->filename = fname;
    ifstream f(fname);
    while(f.is_open()){
        int i, s, r;
        f >> i >> s >> r;
        string st;
        int ci = i;
        st = to_string(ci);
        if(!st.empty() && i > 0 && s> 0 && r>0){
            Friendship fr(i, s, r);
            int ok= 1;
            for(auto& fr1 : get_all())
                if(fr1 == fr)
                    ok = 0;
            if(ok == 1) {
                list.add(fr);
            }
        }
        if(f.eof())
            f.close();
    }
}

void RepositoryFriendship::save_to_File() {
    ofstream g(this->filename);
    for (auto &fr: list.get_all()){
        g << fr.get_id() << " "<<fr.get_sender() <<" "<< fr.get_receiver() << endl;
    }
    g.close();
}

Friendship RepositoryFriendship::get_by_id(int i) {
    for(auto& fr: list.get_all()){
        if(i == fr.get_id())
            return fr;
    }
    throw std::runtime_error("Id was not found!!");
}

std::vector<Friendship> RepositoryFriendship::get_all() {
    return list.get_all();
}
