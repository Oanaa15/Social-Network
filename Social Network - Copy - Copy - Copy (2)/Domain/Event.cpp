//
// Created by Oana on 5/22/2022.
//

#include "Event.h"

Event::Event() {
    this->id = 0;
    this->event_name = "";
    this->id_host = 0;
}

Event::Event(int i, string e_name, int host) {
    this->id = i;
    this->event_name = e_name;
    this->id_host = host;
}

void Event::set_id(int i) {
    this->id = i;
}

int Event::get_id() {
    return this->id;
}

void Event::set_host(int h) {
    this->id_host = h;
}

int Event::get_host() {
    return this->id_host;
}

void Event::set_event_name(string e_name) {
    this->event_name = e_name;
}

string Event::get_event_name() {
    return this->event_name;
}

Event &Event::operator=(const Event &ev) {
    this->id = ev.id;
    this->event_name = ev.event_name;
    this->id_host = ev.id_host;
    return *this;
}

bool Event::operator==(const Event &ev) const {
    return this->id == ev.id && this->id_host == ev.id_host && this->event_name == ev.event_name;
}

std::istream &operator>>(istream &is, Event &ev) {
    int id;
    cout << "Enter event id:";
    is >> id;
    ev.id = id;

    string e_name;
    cout << "Enter name event:";
    is >> e_name;
    ev.event_name = e_name;

    int host;
    cout << "Enter the id of the host:";
    is >> host;
    ev.id_host = host;
    return is;
}

std::ostream &operator<<(ostream &os, Event &ev) {
    os << ev.id << " " << ev.event_name << " " << ev.id_host << endl;
    return os;
}

Event::~Event() = default;
