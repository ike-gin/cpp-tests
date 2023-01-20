#include <iostream>
using namespace std;

class Node {
public:
  void printData() { cout << data << endl; }

private:
  int key;
  Node *next;
  /* Other members of Node Class */
  int data = 5;
  // Now class  LinkedList can
  // access private members of Node
  friend class LinkedList;
};

class LinkedList {
public:
  void incrNodeData(Node &n) { n.data++; }
};

int main() {
  Node n;
  LinkedList l;

  n.printData();
  l.incrNodeData(n);
  n.printData();
}
