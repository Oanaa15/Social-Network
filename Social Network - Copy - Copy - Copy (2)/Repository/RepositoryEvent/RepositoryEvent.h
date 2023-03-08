//
// Created by Oana on 5/22/2022.
//

#ifndef PROIECTSDA_REPOSITORYEVENT_H
#define PROIECTSDA_REPOSITORYEVENT_H


#include "../../Domain/LSI.h"
#include "../../Domain/Event.h"

class RepositoryEvent {
private:
    LSI<Event> events;
    string filename;

public:
    RepositoryEvent();

    RepositoryEvent(string fname);

    void save_to_File();

    ~RepositoryEvent();

    void add_event(Event ev);

    void delete_event(Event ev);

    void modify_event(Event old_ev, Event new_ev);

    int get_size();

    Event get_by_id(int id);

    std::vector<Event> get_all_vector();



};


#endif //PROIECTSDA_REPOSITORYEVENT_H
