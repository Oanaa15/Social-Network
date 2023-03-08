//
// Created by Oana on 5/11/2022.
//

#ifndef PROIECTSDA_NODE_H
#define PROIECTSDA_NODE_H

template <typename T>
class LSI;

template <class T>
class Node {
private:
    T info;
    Node<T>* next;
public:
    Node(T info, Node<T>* next) : info(info), next(next){}
    Node(T info) : info(info){ next= nullptr;}
    friend class LSI<T>;

};


#endif //PROIECTSDA_NODE_H
