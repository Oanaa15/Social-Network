//
// Created by Oana on 5/18/2022.
//

#ifndef PROIECTSDA_MESSAGE_H
#define PROIECTSDA_MESSAGE_H

#include <iostream>
using namespace std;

class Message {
private:
    int id;
    int sender;
    int receiver;
    string message;
public:
    Message();

    ~Message();

    Message(int i, int s, int r, string mes);

    void set_id(int i);
    int get_id();

    void set_sender(int s);
    int get_sender();

    void set_receiver(int r);
    int get_receiver();

    void set_message(string mes);
    string get_message();

    Message& operator=(const Message& mes);
    bool operator==(const Message& mes) const;

    friend std::istream &operator>>(std::istream& is, Message& m);
    friend std::ostream &operator<<(std::ostream& os, Message& m);

};


#endif //PROIECTSDA_MESSAGE_H
