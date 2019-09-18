#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"
#include <iostream>
using namespace std;
template <typename Tr>
class TraitsList {
public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;

private:
    Node<T>* head;
    Operation cmp;

    bool find(T data, Node<T> **&pointer) {
        pointer = &head;
        while(*pointer!= nullptr){
            if(cmp((*pointer)->data,data)){
                if(data==(*pointer)->data)
                    return true;
            }
            else return false;
            pointer = &((*pointer)->next);
        }
    }

public:
    TraitsList() : head(nullptr) {};

    bool insert(T data) {
        Node<T> **pointer;
        if(!find(data,pointer)){
            auto newNode =new Node<T>(data);
            newNode->next=(*pointer);
            (*pointer)=newNode;
            return true;
        }else return false;
    }

    bool remove(T data) {
        Node<T> **temp;
        if(find(temp,data)){
            delete find(temp,data);
            return true;
        } else return  false;
    }

    bool find(T data) {
        Node<T> **temp;
        return find(data,temp);
    }

    T operator [] (int index) {
        auto temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->data;
    }

    int size() {
        return this->nodes;
    }

    void print() {
        Node<T> *current = this->head;
        while (current != nullptr) {
            cout << current->data << ' ';
            current = current->next;
        }
    }

    ~TraitsList() {
        if(this->head)
            this->head->killSelf();
    }
};

#endif
