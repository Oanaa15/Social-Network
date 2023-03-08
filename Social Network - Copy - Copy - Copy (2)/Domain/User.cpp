//
// Created by Oana on 5/8/2022.
//

#include "User.h"

User::User() {
    this->id = 0;
    this->first_name = "";
    this->last_name = "";
    this->mail = "";
    this->age = 0;

}

User::User(int i, string f_name, string l_name, string m, int a) {
    this->id = i;
    this->first_name = f_name;
    this->last_name = l_name;
    this->mail = m;
    this->age = a;
}

User::User(const User &user) {
    this->id = user.id;
    this->first_name = user.first_name;
    this->last_name = user.last_name;
    this->mail = user.mail;
    this->age = user.age;
}

void User::set_id(int i) {
    this->id =i;
}

int User::get_id() {
    return this->id;
}

void User::set_first_name(string f_name) {
    this->first_name = f_name;
}

string User::get_first_name() {
    return this->first_name;
}

void User::set_last_name(string l_name) {
    this->last_name = l_name;
}

string User::get_last_name() {
    return this->last_name;
}

void User::set_mail(string m) {
    this->mail = m;
}

string User::get_mail() {
    return this->mail;
}

void User::set_age(int a) {
    this->age = a;
}

int User::get_age() {
    return this->age;
}

User &User::operator=(const User &user) {
    this->id = user.id;
    this->first_name = user.first_name;
    this->last_name = user.last_name;
    this->mail = user.mail;
    this->age = user.age;
    return *this;
}

bool User::operator==(const User &user) const {
    return this->id == user.id && this->first_name == user.first_name &&
    this->last_name == user.last_name && this->age == user.age && this->mail == user.mail;
}

std::istream &operator>>(istream &is, User &user) {
    int id;
    cout << "Enter user id:"; is >> id;
    user.id = id;

    string f_name;
    cout << "Enter your first name:"; is >> f_name;
    user.first_name = f_name;

    string l_name;
    cout << "Enter your last name:"; is >> l_name;
    user.last_name = l_name;

    string m;
    cout << "Enter your email:"; is >> m;
    user.mail = m;

    int a;
    std::cout << "Enter your age:"; is >> a;
    user.age = a;

    return is;
}

std::ostream &operator<<(ostream &os, User &user) {
    os << user.id << " " << user.first_name <<" " << user.last_name << endl <<" " << user.mail << " " << user.age << endl;
    return os;
}

User::~User() = default;
