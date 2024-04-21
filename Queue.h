#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
template <typename T> class Queue {
  template <typename K> class Node {
  public:
    K data;
    Node *next;
    Node(const K &data, Node *next) {
      this->data = data;
      this->next = next;
    }
  };
  Node<T> *front, *back;
  unsigned size;

public:
  Queue<T>() {
    front = back = nullptr;
    size = 0;
  }
  // PUSH FUNCTION
  // PUSH ITEM TO END OF QUEUE
  void pushBack(const T &item) {
    if (empty()) {
      front = back = new Node<T>(item, nullptr);
    } else {
      back->next = new Node<T>(item, nullptr);
      back = back->next;
    }
    size++;
  }
  // POP FUNCTION
  // REMOVE THE ITEM AT FRONT OF QUEUE
  void pop() {
    if (empty())
      return;
    else {
      Node<T> *temp = front;
      front = front->next;
      delete temp;
      size--;
    }
  }

  // TOP FUNCTION
  // RETURN THE ITEM AT FRONT OF QUEUE
  const T &top() const { return front->data; }

  // EMPTY FUNCTION
  // RETURNS IF THERE IS NO DATA
  bool empty() const { return size == 0; }
  // SIZEOF FUNCTION
  // RETURNS SIZE OF QUEUE
  unsigned sizeOf() const { return size; }
};

#endif