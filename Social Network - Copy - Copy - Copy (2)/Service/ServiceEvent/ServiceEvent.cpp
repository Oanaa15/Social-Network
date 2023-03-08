//
// Created by Oana on 5/22/2022.
//

#include "ServiceEvent.h"

ServiceEvent::ServiceEvent(RepositoryEvent &r) : repo(r)  {}

void ServiceEvent::create_event(Event ev) {
    repo.add_event(ev);
}

void ServiceEvent::remove_event(Event ev) {
    repo.delete_event(ev);
}

void ServiceEvent::update_event(Event old_e, Event new_e) {
    repo.modify_event(old_e, new_e);
}

Event ServiceEvent::get_by_id(int i) {
    return repo.get_by_id(i);
}

std::vector<Event> ServiceEvent::get_all() {
    return repo.get_all_vector();
}
