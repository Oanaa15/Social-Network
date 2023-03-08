//
// Created by Oana on 5/18/2022.
//

#include "Message.h"

Message::Message() {
    this->id = 0;
    this->sender = 0;
    this->receiver = 0;
    this->message = "";
}

Message::~Message() = default;

Message::Message(int i, int s, int r, string mes) {
    this->id = i;
    this->sender = s;
    this->receiver = r;
    this->message = mes;
}

void Message::set_id(int i) {
    this->id = i;

}

int Message::get_id() {
    return this->id;
}

void Message::set_sender(int s) {
    this->sender = s;
}

int Message::get_sender() {
    return this->sender;
}

void Message::set_receiver(int r) {
    this->receiver = r;
}

int Message::get_receiver() {
    return this->receiver;
}

Message &Message::operator=(const Message &mes) {
    this->id = mes.id;
    this->sender = mes.sender;
    this->receiver = mes.receiver;
    this->message = mes.message;
    return *this;
}

bool Message::operator==(const Message &mes) const {
    return this->id == mes.id && this->receiver == mes.receiver && this->sender == mes.sender &&
           this->message == mes.message;
}

void Message::set_message(string mes) {
    this->message = mes;

}

string Message::get_message() {
    return this->message;
}

std::istream &operator>>(istream &is, Message &m) {
    int id;
    cout << "Enter friendship id:";
    is >> id;
    m.id = id;

    int id1;
    cout << "Enter sender id:";
    is >> id1;
    m.sender = id1;

    int id2;
    cout << "Enter receiver id:";
    is >> id2;
    m.receiver = id2;

    string mes;
    cout << "Enter message:";
    is >> mes;
    m.message = mes;

    return is;
}

std::ostream &operator<<(ostream &os, Message &m) {
    os << m.id << " " << m.sender << " " << m.receiver << " " << m.message << endl;
    return os;
}
