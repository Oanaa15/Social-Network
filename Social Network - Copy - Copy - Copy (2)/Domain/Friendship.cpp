//
// Created by Oana on 5/16/2022.
//

#include "Friendship.h"

Friendship::Friendship() {
    this->id = 0;
    this->sender = 0;
    this->receiver = 0;

}

Friendship::Friendship(int i, int s, int r) {
    this->id = i;
    this->sender = s;
    this->receiver = r;

}

void Friendship::set_id(int i) {
    this->id = i;

}

int Friendship::get_id() {
    return this->id;
}

void Friendship::set_sender(int s) {
    this->sender = s;
}

int Friendship::get_sender() {
    return this->sender;
}

void Friendship::set_receiver(int r) {
    this->receiver = r;
}

int Friendship::get_receiver() {
    return this->receiver;
}

Friendship &Friendship::operator=(const Friendship &fr) {
    this->id = fr.id;
    this->receiver = fr.receiver;
    this->sender = fr.sender;
    return *this;
}

bool Friendship::operator==(const Friendship &fr) const {
    return this->id == fr.id && this->receiver == fr.receiver && this->sender == fr.sender;
}

std::istream &operator>>(istream &is, Friendship &fr) {
    int id;
    cout << "Enter friendship id:"; is >> id;
    fr.id = id;

    int id1;
    cout << "Enter first user id:"; is >> id1;
    fr.sender = id1;

    int id2;
    cout << "Enter second user id:"; is >> id2;
    fr.receiver = id2;
    return is;
}

std::ostream &operator<<(ostream &os, Friendship &fr) {
    os << fr.id << " " << fr.sender << " "<< fr.receiver <<endl;
    return os;
}


Friendship::~Friendship() = default;
