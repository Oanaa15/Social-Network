//
// Created by Oana on 5/22/2022.
//

#include <fstream>
#include "RepositoryEvent.h"

RepositoryEvent::RepositoryEvent() = default;

RepositoryEvent::RepositoryEvent(string fname) {
    this->filename = fname;
    ifstream f(fname);
    while (f.is_open()) {
        int i, host;
        string name;
        f >> i >> name >> host;
        if (!name.empty()) {
            Event event(i, name, host);
            events.add(event);
        }
        if (f.eof())
            f.close();
    }

}

void RepositoryEvent::save_to_File() {
    ofstream g(this->filename);
    for (auto& ev: events.get_all()){
        g << ev;
    }
    g.close();
}

void RepositoryEvent::add_event(Event ev) {
    events.add(ev);
    this->save_to_File();

}

void RepositoryEvent::delete_event(Event ev) {
    events.remove(ev);
    this->save_to_File();

}

void RepositoryEvent::modify_event(Event old_ev, Event new_ev) {
    events.modify(old_ev, new_ev);
    this->save_to_File();
}

int RepositoryEvent::get_size() {
    return events.size();
}

Event RepositoryEvent::get_by_id(int id) {
    for(auto& ev: events.get_all()){
        if(id == ev.get_id())
            return ev;
    }
    throw std::runtime_error("Id was not found!!");
}

std::vector<Event> RepositoryEvent::get_all_vector() {
    return events.get_all();
}

RepositoryEvent::~RepositoryEvent() = default;
