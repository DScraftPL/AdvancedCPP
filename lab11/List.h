#pragma once

#include <iostream>
#include <memory>

class Element {
public:
  int wartosc;
  std::shared_ptr<Element> prev;
  std::shared_ptr<Element> next;
  Element(int _wartosc) : wartosc(_wartosc), prev(nullptr), next(nullptr) {
    std::cout << "Konstruktor Element" << std::endl;
  }
  ~Element() { std::cout << "Destruktor Element" << std::endl; }
};

class List {
public:
  std::shared_ptr<Element> head;
  std::shared_ptr<Element> tail;
  List() : head(nullptr), tail(nullptr) {
    std::cout << "Konstruktor List" << std::endl;
  }
  ~List() {
    std::cout << "Destruktor List" << std::endl;
    while (!isEmpty()) {
      pop_front();
    }
  }
  bool isEmpty() {
    if (head == nullptr && tail == nullptr) {
      return true;
    }
    return false;
  }
  void push_front(int wart) {
    auto element = std::make_shared<Element>(wart);
    if (isEmpty()) {
      head = element;
      tail = element;
    } else {
      element->next = head;
      head->prev = element;
      head = element;
    }
  }
  void push_back(int wart) {
    auto element = std::make_shared<Element>(wart);
    if (isEmpty()) {
      head = element;
      tail = element;
    } else {
      element->prev = tail;
      tail->next = element;
      tail = element;
    }
  }
  void pop_front() {
    if (isEmpty()) {
      return;
    }
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
      return;
    }
    head = head->next;
    head->prev = nullptr;
  }
  void pop_back() {
    if (isEmpty()) {
      return;
    }
    if (head == tail) {
      head = nullptr;
      tail = nullptr;
      return;
    }
    tail = tail->prev;
    tail->next = nullptr;
  }
  void display() {
    if (isEmpty()) {
      std::cout << "Lista jest pusta" << std::endl;
      return;
    }
    auto cur = head;
    while (cur) {
      std::cout << cur->wartosc << " ";
      cur = cur->next;
    }
    std::cout << std::endl;
  }
};
