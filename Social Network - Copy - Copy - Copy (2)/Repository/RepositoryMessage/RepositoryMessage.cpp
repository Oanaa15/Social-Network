//
// Created by Oana on 5/18/2022.
//

#include <fstream>
#include "RepositoryMessage.h"

RepositoryMessage::RepositoryMessage() = default;

RepositoryMessage::~RepositoryMessage() = default;

void RepositoryMessage::add_message(Message mes) {
    mp.put(mes.get_id(), mes);
    this->save_to_File();
}

void RepositoryMessage::delete_message(Message mes) {
    mp.remove(mes.get_id(), mes);
    this->save_to_File();
}


std::vector<std::vector<Message>> RepositoryMessage::get_all() {
    return mp.getAll();
}

RepositoryMessage::RepositoryMessage(string fname) {
    this->filename = fname;
    ifstream f(fname);
    while (f.is_open()) {
        //getline
        //string split (" ") => sring[]
        // i = string[0] s = string[1], r = string[2] mes = string[3 - legth];
        int i, s, r;
        string mes;
        f >> i >> s >> r;
        getline(f, mes);
        if (!mes.empty()) {
            Message message(i, s, r, mes);
            mp.put(message.get_id(), message);
        }
        if (f.eof())
            f.close();
    }

}

void RepositoryMessage::save_to_File() {
    ofstream g(this->filename);
    for (auto &message: mp.getAll()) {
        for (auto &m: message)
            g << m;
    }
    g.close();
}

int RepositoryMessage::get_size() {
    return mp.get_size();
}
