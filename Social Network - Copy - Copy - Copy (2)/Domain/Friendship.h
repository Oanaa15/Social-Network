//
// Created by Oana on 5/16/2022.
//

#ifndef PROIECTSDA_FRIENDSHIP_H
#define PROIECTSDA_FRIENDSHIP_H

#include <iostream>
using namespace std;

class Friendship {
private:
    int id;
    int sender;
    int receiver;
public:
    Friendship();

    Friendship(int i, int s, int r);

    ~Friendship();

    void set_id(int i);
    int get_id();

    void set_sender(int s);
    int get_sender();

    void set_receiver(int r);
    int get_receiver();


    Friendship& operator=(const Friendship& fr);
    bool operator==(const Friendship& fr) const;

    friend std::istream &operator>>(std::istream& is, Friendship& fr);
    friend std::ostream &operator<<(std::ostream& os, Friendship& fr);













};


#endif //PROIECTSDA_FRIENDSHIP_H
