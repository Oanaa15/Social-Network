//
// Created by Oana on 5/22/2022.
//

#ifndef PROIECTSDA_EVENT_H
#define PROIECTSDA_EVENT_H

#include <iostream>
using namespace std;

class Event {
private:
    int id, id_host;
    string event_name;

public:
    Event();

    ~Event();

    Event(int i, string e_name, int host);

    void set_id(int i);
    int get_id();

    void set_host(int h);
    int get_host();

    void set_event_name(string e_name);
    string get_event_name();

    Event& operator=(const Event& ev);
    bool operator==(const Event& ev) const;

    friend std::istream &operator>>(std::istream& is, Event& ev);
    friend std::ostream &operator<<(std::ostream& os, Event& ev);













};


#endif //PROIECTSDA_EVENT_H
