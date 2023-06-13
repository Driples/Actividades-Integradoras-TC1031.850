//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "registro.h"
#include <string>

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename);
    void sort();
    void searchAndSave(const std::string &start, const std::string &end, const std::string &filename);

private:
    struct Node {
        Registro data;
        Node *prev;
        Node *next;
        Node(const Registro &data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;

    void clear();
    Node *mergeSort(Node *head);
    Node *merge(Node *first, Node *second);
    Node *split(Node *head);
};

#endif // DOUBLY_LINKED_LIST_H

