//Sergio Alfonso Casillas Santoyo - A01424863
//Eliuth Balderas Neri - A01703315
#include "doubly_linked_list.h"
#include <fstream>
#include <iostream>
#include <sstream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() { clear(); }

void DoublyLinkedList::loadFromFile(const std::string &filename) {
  std::ifstream in(filename);
  std::string line;
  while (std::getline(in, line)) {
    std::istringstream iss(line);
    std::string fecha, ip, falla;
    iss >> fecha;
    fecha += " ";
    std::string temp;
    iss >> temp;
    fecha += temp;
    fecha += " ";
    iss >> temp;
    fecha += temp;
    iss >> ip;
    std::getline(iss, falla);
    falla = falla.substr(1);

    Node *new_node = new Node(Registro(fecha, ip, falla));
    if (!head) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      new_node->prev = tail;
      tail = new_node;
    }
    ++size;
  }
  in.close();
}

void DoublyLinkedList::saveToFile(const std::string &filename) {
  std::ofstream out(filename);
  Node *current = head;
  while (current) {
    out << current->data.getFecha() << " " << current->data.getIP() << " "
        << current->data.getFalla() << std::endl;
    current = current->next;
  }
  out.close();
}

void DoublyLinkedList::sort() {
  head = mergeSort(head);
  Node *current = head;
  while (current->next) {
    current = current->next;
  }
  tail = current;
}

void DoublyLinkedList::searchAndSave(const std::string &start,
                                     const std::string &end,
                                     const std::string &filename) {
  Registro start_reg(start, "", "");
  Registro end_reg(end, "", "");

  Node *start_node = head;
  while (start_node && start_node->data < start_reg) {
    start_node = start_node->next;
  }

  if (!start_node) {
    std::cout << "La fecha de inicio no se encuentra en la bitácora."
              << std::endl;
    return;
  }

  Node *end_node = start_node;
  while (end_node && end_node->data <= end_reg) {
    end_node = end_node->next;
  }

  if (!end_node) {
    std::cout << "La fecha de fin no se encuentra en la bitácora." << std::endl;
    return;
  }

  std::ofstream out(filename);
  Node *current = start_node;

  while (current != end_node) {
    out << current->data.getFecha() << " " << current->data.getIP() << " "
        << current->data.getFalla() << std::endl;
    std::cout << current->data.getFecha() << " " << current->data.getIP() << " "
              << current->data.getFalla() << std::endl;
    current = current->next;
  }
  out.close();
}

void DoublyLinkedList::clear() {
  Node *current = head;
  while (current) {
    Node *next_node = current->next;
    delete current;
    current = next_node;
  }
  head = tail = nullptr;
  size = 0;
}

DoublyLinkedList::Node *DoublyLinkedList::mergeSort(Node *head) {
  if (!head || !head->next) {
    return head;
  }

  Node *second = split(head);

  head = mergeSort(head);
  second = mergeSort(second);

  return merge(head, second);
}

DoublyLinkedList::Node *DoublyLinkedList::merge(Node *first, Node *second) {
  if (!first)
    return second;
  if (!second)
    return first;

  if (first->data <= second->data) {
    first->next = merge(first->next, second);
    first->next->prev = first;
    first->prev = nullptr;
    return first;
  } else {
    second->next = merge(first, second->next);
    second->next->prev = second;
    second->prev = nullptr;
    return second;
  }
}

DoublyLinkedList::Node *DoublyLinkedList::split(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *temp = slow->next;
  slow->next = nullptr;
  return temp;
}

