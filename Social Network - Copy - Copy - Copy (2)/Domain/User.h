//
// Created by Oana on 5/8/2022.
//

#ifndef PROIECTSDA_USER_H
#define PROIECTSDA_USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
private:
    int id;
    string first_name;
    string last_name;
    string mail;
    int age;
public:

    User();

    User(int i, string f_name, string l_name, string m, int a);

    ~User();

    User(const User &user);

    void set_id(int i);
    int get_id();

    void set_first_name(string f_name);
    string get_first_name();

    void set_last_name(string l_name);
    string get_last_name();

    void set_mail(string m);
    string get_mail();

    void set_age(int a);
    int get_age();

    User& operator=(const User& user);
    bool operator==(const User& user) const;

    friend std::istream &operator>>(std::istream& is, User& user);
    friend std::ostream &operator<<(std::ostream& os, User& user);






};


#endif //PROIECTSDA_USER_H
