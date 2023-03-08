//
// Created by Oana on 5/14/2022.
//

#ifndef PROIECTSDA_MULTIMAP_H
#define PROIECTSDA_MULTIMAP_H


#include <iostream>
#include <vector>

template<class T, class U>
class Multimap {
private:
    struct ListNode {
        U value;
        ListNode* next;
    };

    struct DictNode {
        T key;
        ListNode* value;
        DictNode* next;
    };

    DictNode* searchAddress(T key);
public:
    /**
     * multimap constructor
     */
    Multimap();

    /**
     * multimap destructor
     */
    ~Multimap();

    /**
     * adds an element to the multimap
     * @param key type T
     * @param value type U
     */
    void put(T key, U value);

    /**
     * removes an element from the multimap
     * @param key type T
     * @param value type U
     */
    void remove(T key, U value);

    /**
     * gives a vector containing the value with the given key
     * @param key type T
     * @return a vector containing the value with the given key
     */
    std::vector<U> get(T key);

    /**
     * verifies if the key appears in the multimap
     * @param key type T
     * @return true or false
     */
    bool contains(T key);
    /**
     * verifies if the key and the value appears in the multimap
     * @param key type T
     * @param value type U
     * @return true or false
     */
    bool contains(T key, U value);

    /**
     * gets all elements of the multimap
     * @return all elements of the multimap
     */
    std::vector<std::vector<U>> getAll();

    /**
     * the size of the multimap
     * @return size of the multimap
     */
    int get_size();

private:
    DictNode* head;
};

template<class T, class U>
inline typename Multimap<T, U>::DictNode* Multimap<T, U>::searchAddress(T key) {
    DictNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T, class U>
inline Multimap<T, U>::Multimap()
        : head(nullptr)
{}

template<class T, class U>
inline Multimap<T, U>::~Multimap()
{
    DictNode* curr = head;
    while (curr != nullptr) {
        DictNode* next = curr->next;
        delete curr->value;
        delete curr;
        curr = next;
    }
}

template<class T, class U>
inline void Multimap<T, U>::put(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        DictNode* newNode = new DictNode;
        newNode->key = key;
        newNode->value = new ListNode;
        newNode->value->value = value;
        newNode->value->next = nullptr;
        newNode->next = head;
        head = newNode;
    }
    else {
        ListNode* newNode = new ListNode;
        newNode->value = value;
        newNode->next = current->value;
        current->value = newNode;
    }
}


template<class T, class U>
inline void Multimap<T, U>::remove(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return;
    }
    else {
        ListNode* curr = current->value;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            if (curr->value == value) {
                if (prev == nullptr) {
                    current->value = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

template<class T, class U>
inline std::vector<U> Multimap<T, U>::get(T key) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return std::vector<U>();
    }
    else {
        ListNode* curr = current->value;
        std::vector<U> result;
        while (curr != nullptr) {
            result.push_back(curr->value);
            curr = curr->next;
        }

        return result;
    }
}

template<class T, class U>
inline bool Multimap<T, U>::contains(T key) {
    return searchAddress(key) != nullptr;
}

template<class T, class U>
inline bool Multimap<T, U>::contains(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return false;
    }
    else {
        ListNode* curr = current->value;
        while (curr != nullptr) {
            if (curr->value == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
}

template<class T, class U>
inline std::vector<std::vector<U>> Multimap<T, U>::getAll() {
    std::vector<std::vector<U>> result;
    DictNode* current = head;
    while (current != nullptr) {
        result.push_back(get(current->key));
        current = current->next;
    }

    return result;
}

template<class T, class U>
int Multimap<T, U>::get_size() {
    int nr =0;
    for(auto& t: getAll())
        for(auto& elem: t)
            nr++;
    return nr;

}


#endif //PROIECTSDA_MULTIMAP_H
