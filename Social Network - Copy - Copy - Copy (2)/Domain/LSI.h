//
// Created by Oana on 5/11/2022.
//

#ifndef PROIECTSDA_LSI_H
#define PROIECTSDA_LSI_H

#include <vector>
#include "Node.h"

template <class T>
class LSI {
private:
    Node<T>* head;
    int size_elems;
public:
    /**
     * lsi constructor
     */
    LSI(){
        head = nullptr;
        this->size_elems = 0;
    }
    /**
     * adds an element to the lsi
     * @param elem: type T
     */
    void add(T elem){
        if (head==nullptr)
        {
            head=new Node<T>(elem);
            this->size_elems ++;
        }
        else
        {
            Node<T>* p=head;
            while (p->next!=nullptr) {
                p=p->next;
            }
            p->next=new Node<T>(elem);
            this->size_elems ++;
        }
    }
    /**
     * removes an element from the list
     * @param e : type T
     * @return
     */
    T remove(T e){
        Node<T> *nodeToDelete = nullptr;
        T infoToReturn;

        if (head!= nullptr) { // if the list is not empty
            if (head->info == e) {
                nodeToDelete = head;
                head = head->next; //head points to the next node
            } else {
                Node<T> *p= head->next;
                Node <T> *q=head;
                while (p!= nullptr)
                    if (p->info == e) {
                        nodeToDelete = p;
                        p= nullptr;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
                if (nodeToDelete != nullptr)
                    q->next= nodeToDelete->next;
            }
        }
        if (nodeToDelete != nullptr) { // if the elem e was found
            infoToReturn = nodeToDelete->info;
            delete nodeToDelete;
            this->size_elems--;
            return infoToReturn;
        }
        return T(); // e does not exist in the list or the list is empty
    }

    /**
     * modifies an element
     * @param e : old element, type T
     * @param new_e : new elemnet, type T
     */
    void modify(T e,  T new_e) {
        if (head != nullptr) {
            if (head->info == e) {
                head->info = new_e;
                //head = head->next;
            } else {
                Node<T> *p = head->next;
                Node<T> *q = head;
                while (p != nullptr)
                    if (p->info == e) {
                        p->info = new_e;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
    }}}

    T& operator[](int index) const{

    }

    /**
     * gets all elements of the list
     * @return returns a vector containing the elements of the list
     */
    std::vector<T> get_all(){
        std::vector<T> v;
        Node<T>* p=head;
        while (p != nullptr) {
            v.push_back(p->info);
            p=p->next;
    }
        return v;
    }

    /**
     * size of the list
     * @return returns the size of the list
     */
    int size(){
        return this->size_elems;
    }



};


#endif //PROIECTSDA_LSI_H
