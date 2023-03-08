//
// Created by Oana on 5/9/2022.
//

#include <cassert>
#include <fstream>
#include "Tests.h"
#include "../Domain/User.h"
#include "../Domain/LSI.h"
#include "../Repository/RepositoryUser/RepositoryUser.h"
#include "../Domain/Friendship.h"
#include "../Domain/Multimap.h"
#include "../Repository/RepositoryFriendship/RepositoryFriendship.h"
#include "../Domain/Message.h"
#include "../Service/ServiceUser/ServiceUser.h"
#include "../Repository/RepositoryMessage/RepositoryMessage.h"
#include "../Service/ServiceFriendship/ServiceFriendship.h"
#include "../Service/ServiceMessage/ServiceMessage.h"
#include "../Domain/Event.h"
#include "../Repository/RepositoryEvent/RepositoryEvent.h"
#include "../Service/ServiceEvent/ServiceEvent.h"

void test_user_constructor(){
    User u;
    assert(u.get_id() == 0);
    assert(u.get_age() == 0);
    assert(u.get_first_name().empty());
    assert(u.get_mail().empty());
    assert(u.get_last_name().empty());
}

void test_user_constructor2(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);

    assert(u.get_id() == 1);
    assert(u.get_age() == 20);
    assert(u.get_first_name() == "Alex");
    assert(u.get_mail() == "alextopan@yahoo.com");
    assert(u.get_last_name() == "Topan");
}
void test_getters_setters(){
    User u;
    u.set_id(1);
    u.set_age(16);
    u.set_first_name("Aura");
    u.set_last_name("Steje");
    u.set_mail("aura@yahooo.com");

    assert(u.get_id() == 1);
    assert(u.get_age() == 16);
    assert(u.get_first_name() == "Aura");
    assert(u.get_mail() == "aura@yahooo.com");
    assert(u.get_last_name() == "Steje");


}

void test_user_operators(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    u = u2;
    assert( u == u2);

}

void test_add_lsi(){
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    list->add(u);
    list->add(u2);
    list->add(u3);

    assert(list->size() == 3);
}

void test_delete_lsi(){
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    list->add(u);
    list->add(u2);
    list->add(u3);

    assert(list->size() == 3);

    list->remove(u2);
    assert(list->size() == 2);

}

void test_get_all_lsi(){
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    list->add(u);
    list->add(u2);
    list->add(u3);

    vector<User> v = list->get_all();
    assert(v[0] == u);
    assert(v[1] == u2);
    assert(v.size() == 3);
}

void test_repo_get_all_vector(){
    RepositoryUser repo;
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);

    repo.add_user(u);
    repo.add_user(u2);
    repo.add_user(u3);

    assert(repo.get_all_vector().size() == 3);
}

void test_modify_lsi(){
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    list->add(u);
    list->add(u2);

    assert(list->size() == 2);

    list->modify(u, u3);

    vector<User> v = list->get_all();
    assert(v[0] == u3);
}

void test_repo_add(){
    remove("userTests.txt");
    fstream f;
    f.open("userTests.txt", ios::in);
    f.open("userTests.txt", ios::out);
    RepositoryUser repo("userTests.txt");
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);

    repo.add_user(u);
    repo.add_user(u2);
    repo.add_user(u3);

    assert(repo.get_size() == 3);
    assert(repo.get_all_vector().size() == 3);
}


void test_repo_remove(){
    remove("userTests.txt");
    fstream f;
    f.open("userTests.txt", ios::in);
    f.open("userTests.txt", ios::out);
    RepositoryUser repo("userTests.txt");
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);

    repo.add_user(u);
    repo.add_user(u2);
    repo.add_user(u3);
    assert(repo.get_size() == 3);

    repo.delete_user(u2);
    assert(repo.get_size() == 2);
    assert(repo.get_all_vector().size() == 2);
}

void test_repo_modify(){
    remove("userTests.txt");
    fstream f;
    f.open("userTests.txt", ios::in);
    f.open("userTests.txt", ios::out);
    RepositoryUser repo("userTests.txt");
    LSI<User>* list = new LSI<User>();
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);

    repo.add_user(u);
    repo.add_user(u2);
    assert(repo.get_size() == 2);

    repo.modify_user(u, u3);
    assert(repo.get_by_id(3) == u3);
}


void test_constructor_fr(){
    Friendship u;
    assert(u.get_id() == 0);
    assert(u.get_sender() == 0);
}

void test_constructor2_fr(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    Friendship fr(1, 1, 2);

    assert(fr.get_id() == 1);
    assert(fr.get_sender() == 1);
    assert(fr.get_receiver() == 2);


}
void test_getters_setters_fr(){
    Friendship fr;
    fr.set_id(1);
    fr.set_sender(1);
    fr.set_receiver(2);

    assert(fr.get_id() == 1);
    assert(fr.get_sender() == 1);
    assert(fr.get_receiver() == 2);
}

void test_fr_operators(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);

    fr = fr2;
    assert(fr.get_receiver() == 3);
    assert(fr == fr2);
}


void test_add_multimap(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);

    Multimap<int, Friendship> multimap;
    multimap.put(1, fr);
    multimap.put(2, fr2);
    assert(multimap.get_size() == 2);
    assert(multimap.contains(1));
    assert(multimap.contains(2));
}

void test_delete_multimap(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);

    Multimap<int, Friendship> multimap;
    multimap.put(1, fr);
    multimap.put(2, fr2);

    multimap.remove(2, fr2);
    assert(multimap.contains(1, fr));
    assert(multimap.get_size() == 1);
}

void test_add_friendship(){
    remove("frTests.txt");
    fstream f;
    f.open("frTests.txt", ios::in);
    f.open("frTests.txt", ios::out);
    RepositoryFriendship repo("frTests.txt");
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);

    repo.add_friendship(fr);
    repo.add_friendship(fr2);


    assert(repo.get_size() == 2);
}

void test_delete_friendship(){
    remove("frTests.txt");
    fstream f;
    f.open("frTests.txt", ios::in);
    f.open("frTests.txt", ios::out);
    RepositoryFriendship repo("frTests.txt");
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);

    repo.add_friendship(fr);
    repo.add_friendship(fr2);

    assert(repo.get_size() == 2);

    repo.delete_friendship(fr2);
    assert(repo.get_size() == 1);
}

void test_modify_friendship(){
    remove("frTests.txt");
    fstream f;
    f.open("frTests.txt", ios::in);
    f.open("frTests.txt", ios::out);
    RepositoryFriendship repo("frTests.txt");
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);
    Friendship fr3(3, 1, 3);

    repo.add_friendship(fr);
    repo.add_friendship(fr2);


    assert(repo.get_size() == 2);

    repo.modify_friendship(fr, fr3);

    assert(repo.get_by_id(3) == fr3);
}


void test_constructor_mess(){
    Message m;
    assert(m.get_id() == 0);
    assert(m.get_sender() == 0);
    assert(m.get_message().empty());
}

void test_constructor2_mess(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    Message m(1, 1, 2, "ce faci?");

    assert(m.get_id() == 1);
    assert(m.get_sender() == 1);
    assert(m.get_receiver() == 2);
    assert(m.get_message() == "ce faci?");


}
void test_getters_setters_mess(){
    Message m;
    m.set_id(1);
    m.set_sender(1);
    m.set_receiver(2);
    m.set_message("nu");

    assert(m.get_id() == 1);
    assert(m.get_sender() == 1);
    assert(m.get_receiver() == 2);
    assert(m.get_message() == "nu");
}

void test_mess_operators(){
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Oana", "Maria", "oaanaaa@yahoo.es", 21);
    Message m(1, 1, 2, "saluut");
    Message m1(2, 2, 3, "heyy");

    m = m1;
    assert(m == m1);

}
void test_service_user_create(){
    remove("userTests.txt");
    fstream f;
    f.open("userTests.txt", ios::in);
    f.open("userTests.txt", ios::out);
    RepositoryUser repo("userTests.txt");
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    ServiceUser ser(repo);
    ser.create_user(u);
    ser.create_user(u2);
    ser.create_user(u3);
    assert(ser.get_all().size() == 3);
    assert(ser.get_by_id(2) == u2);
}

void test_service_user_delete(){
    remove("userTests.txt");
    fstream f;
    f.open("userTests.txt", ios::in);
    f.open("userTests.txt", ios::out);
    RepositoryUser repo("userTests.txt");
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    ServiceUser ser(repo);
    ser.create_user(u);
    ser.create_user(u2);
    ser.create_user(u3);
    assert(ser.get_all().size() == 3);

    ser.remove_user(u3);
    assert(ser.get_all().size() == 2);
}
void test_service_user_modify(){
    remove("userTests.txt");
    fstream f;
    f.open("userTests.txt", ios::in);
    f.open("userTests.txt", ios::out);
    RepositoryUser repo("userTests.txt");
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);
    User u2(2, "Andreea", "Tamasan", "andreeatifa@yahoo.com", 19);
    User u3(3, "Raul", "Turc", "turcraul@mail.ro", 18);
    ServiceUser ser(repo);
    ser.create_user(u);
    ser.create_user(u2);
    assert(ser.get_all().size() == 2);

    ser.update_user(u2, u3);
    assert(ser.get_by_id(3) == u3);
}

void test_service_user_get_all(){
    remove("userTests.txt");
    fstream f;
    f.open("userTests.txt", ios::in);
    f.open("userTests.txt", ios::out);
    RepositoryUser repo("userTests.txt");
    User u(1,"Alex", "Topan", "alextopan@yahoo.com", 20);

    ServiceUser ser(repo);
    ser.create_user(u);

    assert(ser.get_all().size() == 1);
}

void test_repo_add_mes(){
    remove("messageTests.txt");
    fstream f;
    f.open("messageTests.txt", ios::in);
    f.open("messageTests.txt", ios::out);
    RepositoryMessage repo("messageTests.txt");
    Message m(1, 1, 2, "saluut");
    Message m1(2, 2, 3, "heyy");
    Message m2(3, 3, 1, "dc?");
    repo.add_message(m);
    repo.add_message(m1);
    repo.add_message(m2);

    assert(repo.get_size() == 3);
    assert(repo.get_all().size() == 3);
}

void test_repo_delete_mes(){
    RepositoryMessage repo;
    Message m(1, 1, 2, "saluut");
    Message m1(2, 2, 3, "heyy");
    Message m2(3, 3, 1, "dc?");
    repo.add_message(m);
    repo.add_message(m1);
    repo.add_message(m2);

    assert(repo.get_size() == 3);
    assert(repo.get_all().size() == 3);

    repo.delete_message(m2);
    assert(repo.get_size() == 2);
}

void test_repo_get_all_mes(){
    RepositoryMessage repo;
    Message m(1, 1, 2, "saluut");
    Message m1(2, 2, 3, "heyy");
    Message m2(3, 3, 1, "dc?");
    repo.add_message(m);
    repo.add_message(m1);
    repo.add_message(m2);

    assert(repo.get_size() == 3);
    assert(repo.get_all().size() == 3);
}

void test_service_friendship_create(){
    remove("frTests.txt");
    fstream f;
    f.open("frTests.txt", ios::in);
    f.open("frTests.txt", ios::out);
    RepositoryFriendship repo("frTests.txt");
    ServiceFriendship ser(repo);
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);

    ser.create_friendship(fr);
    ser.create_friendship(fr2);

    assert(ser.get_all().size() == 2);
}

void test_service_friendship_remove(){
    remove("frTests.txt");
    fstream f;
    f.open("frTests.txt", ios::in);
    f.open("frTests.txt", ios::out);
    RepositoryFriendship repo("frTests.txt");
    ServiceFriendship ser(repo);
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);

    ser.create_friendship(fr);
    ser.create_friendship(fr2);

    assert(ser.get_all().size() == 2);
    ser.remove_friendship(fr2);
    assert(ser.get_all().size() == 1);
}

void test_service_friendship_update(){
    remove("frTests.txt");
    fstream f;
    f.open("frTests.txt", ios::in);
    f.open("frTests.txt", ios::out);
    RepositoryFriendship repo("frTests.txt");
    ServiceFriendship ser(repo);
    Friendship fr(1, 1, 2);
    Friendship fr2(2, 2, 3);
    Friendship fr3(3, 3, 1);

    ser.create_friendship(fr);
    ser.create_friendship(fr2);

    ser.update_friendship(fr, fr3);

    assert(ser.get_all().size() == 2);
    assert(ser.get_by_id(3) == fr3);
}

void test_service_message_remove(){
    remove("messageTests.txt");
    fstream f;
    f.open("messageTests.txt", ios::in);
    f.open("messageTests.txt", ios::out);
    RepositoryMessage repo("messageTests.txt");
    ServiceMessage ser(repo);
    Message m(1, 1, 2, "saluut");
    Message m1(2, 2, 3, "heyy");
    Message m2(3, 3, 1, "dc?");

    ser.create_message(m);
    ser.create_message(m1);
    ser.create_message(m2);
    assert(ser.messages_size() == 3);

    ser.remove_message(m);
    assert(ser.messages_size() == 2);
}

void test_service_messages_create(){
    remove("messageTests.txt");
    fstream f;
    f.open("messageTests.txt", ios::in);
    f.open("messageTests.txt", ios::out);
    RepositoryMessage repo("messageTests.txt");
    ServiceMessage ser(repo);
    Message m(1, 1, 2, "saluut");
    Message m1(2, 2, 3, "heyy");
    Message m2(3, 3, 1, "dc?");

    ser.create_message(m);
    ser.create_message(m1);
    ser.create_message(m2);

    assert(ser.get_all_messages().size() == 3);

}


void test_constructor_event() {
    Event event;
    assert(event.get_id() == 0);
    assert(event.get_event_name().empty());
    assert(event.get_host() == 0);

}

void test_constructor2_event() {
    Event event(1, "Untold", 1);
    assert(event.get_id() == 1);
    assert(event.get_event_name() == "Untold");
    assert(event.get_host() == 1);
}

void test_getters_setters_event() {
    Event event;
    event.set_id(1);
    event.set_event_name("Untold");
    event.set_host(2);
    assert(event.get_id() == 1);
    assert(event.get_event_name() == "Untold");
    assert(event.get_host() == 2);

}

void test_event_operators() {
    Event event(1, "Untold", 1);
    Event event2(2, "Nerversea", 3);

    event = event2;
    assert(event == event2);
}

void test_repo_add_event() {
    remove("eventTests.txt");
    fstream f;
    f.open("eventTests.txt", ios::in);
    f.open("eventTests.txt", ios::out);
    RepositoryEvent repo("eventTests.txt");
    Event event(1, "Untold", 1);
    Event event2(2, "Neversea", 3);
    Event event3(3, "Food&Films", 2);

    repo.add_event(event);
    repo.add_event(event2);
    repo.add_event(event3);

    assert(repo.get_size() == 3);
    assert(repo.get_all_vector().size() == 3);

}

void test_repo_remove_event() {
    remove("eventTests.txt");
    fstream f;
    f.open("eventTests.txt", ios::in);
    f.open("eventTests.txt", ios::out);
    RepositoryEvent repo("eventTests.txt");
    Event event(1, "Untold", 1);
    Event event2(2, "Neversea", 3);
    Event event3(3, "Food&Films", 2);

    repo.add_event(event);
    repo.add_event(event2);
    repo.add_event(event3);

    assert(repo.get_size() == 3);
    assert(repo.get_all_vector().size() == 3);

    repo.delete_event(event3);

    assert(repo.get_size() == 2);
    assert(repo.get_all_vector().size() == 2);
}

void test_repo_modify_event() {
    remove("eventTests.txt");
    fstream f;
    f.open("eventTests.txt", ios::in);
    f.open("eventTests.txt", ios::out);
    RepositoryEvent repo("eventTests.txt");
    Event event(1, "Untold", 1);
    Event event2(2, "Neversea", 3);
    Event event3(3, "Food&Films", 2);

    repo.add_event(event);
    repo.add_event(event2);

    assert(repo.get_size() == 2);
    assert(repo.get_all_vector().size() == 2);

    repo.modify_event(event2, event3);
    assert(repo.get_by_id(3) == event3);

}

void test_service_event_create() {
    remove("eventTests.txt");
    fstream f;
    f.open("eventTests.txt", ios::in);
    f.open("eventTests.txt", ios::out);
    RepositoryEvent repo("eventTests.txt");
    ServiceEvent ser(repo);
    Event event(1, "Untold", 1);
    Event event2(2, "Neversea", 3);
    Event event3(3, "Food&Films", 2);

    ser.create_event(event);
    ser.create_event(event2);
    ser.create_event(event3);

    assert(ser.get_all().size() == 3);

}

void test_service_event_remove() {
    remove("eventTests.txt");
    fstream f;
    f.open("eventTests.txt", ios::in);
    f.open("eventTests.txt", ios::out);
    RepositoryEvent repo("eventTests.txt");
    ServiceEvent ser(repo);
    Event event(1, "Untold", 1);
    Event event2(2, "Neversea", 3);
    Event event3(3, "Food&Films", 2);

    ser.create_event(event);
    ser.create_event(event2);
    ser.create_event(event3);

    assert(ser.get_all().size() == 3);

    ser.remove_event(event3);
    assert(ser.get_all().size() == 2);

}

void test_service_event_modify() {
    remove("eventTests.txt");
    fstream f;
    f.open("eventTests.txt", ios::in);
    f.open("eventTests.txt", ios::out);
    RepositoryEvent repo("eventTests.txt");
    ServiceEvent ser(repo);
    Event event(1, "Untold", 1);
    Event event2(2, "Neversea", 3);
    Event event3(3, "Food&Films", 2);

    ser.create_event(event);
    ser.create_event(event3);

    assert(ser.get_all().size() == 2);

    ser.update_event(event3, event2);
    assert(ser.get_by_id(2) == event2);

}

void run_tests(){
    ///Lsi:
    test_add_lsi();
    test_modify_lsi();
    test_get_all_lsi();
    test_delete_lsi();


    ///User:
    test_user_constructor();
    test_user_constructor2();
    test_getters_setters();
    test_user_operators();

    ///Repo User:
    test_repo_add();
    test_repo_get_all_vector();
    test_repo_remove();
    test_repo_modify();

    ///Service User:
    test_service_user_create();
    test_service_user_delete();
    test_service_user_modify();
    test_service_user_get_all();


    ///Multimap:
    test_add_multimap();
    test_delete_multimap();


    ///Friendship:
    test_constructor_fr();
    test_constructor2_fr();
    test_getters_setters_fr();
    test_fr_operators();

    ///Repo Friendship:
    test_add_friendship();
    test_delete_friendship();
    test_modify_friendship();

    ///Service friendship:
    test_service_friendship_create();
    test_service_friendship_remove();
    test_service_friendship_update();


    ///Message:
    test_constructor_mess();
    test_constructor2_mess();
    test_getters_setters_mess();
    test_mess_operators();

    ///Repo message:
    test_repo_add_mes();
    test_repo_delete_mes();
    test_repo_get_all_mes();

    ///Service messages:
    test_service_messages_create();
    test_service_message_remove();


    ///Event:
    test_constructor_event();
    test_constructor2_event();
    test_getters_setters_event();
    test_event_operators();

    ///Repo event:
    test_repo_add_event();
    test_repo_remove_event();
    test_repo_modify_event();

    ///Service event:
    test_service_event_create();
    test_service_event_remove();
    test_service_event_modify();
}
