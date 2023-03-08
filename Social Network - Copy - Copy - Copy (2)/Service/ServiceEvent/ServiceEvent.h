//
// Created by Oana on 5/22/2022.
//

#ifndef PROIECTSDA_SERVICEEVENT_H
#define PROIECTSDA_SERVICEEVENT_H


#include "../../Repository/RepositoryEvent/RepositoryEvent.h"

class ServiceEvent {
private:
    RepositoryEvent repo;

public:
    ServiceEvent(RepositoryEvent &r);

    void create_event(Event ev);

    void remove_event(Event ev);

    void update_event(Event old_e, Event new_e);

    Event get_by_id(int i);

    std::vector<Event> get_all();

};


#endif //PROIECTSDA_SERVICEEVENT_H
