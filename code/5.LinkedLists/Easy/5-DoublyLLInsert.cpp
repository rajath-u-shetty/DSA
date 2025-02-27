#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *back;
  Node *next;

public:
  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }

public:
  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *doublyToArr(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

Node *InsertAtHead(Node *head, int val) {
  Node *temp = new Node(val);
  temp->next = head;
  head->back = temp;
  return temp;
}

Node *InsertAtEnd(Node *head, int val) {
  if (head == NULL) {
    return head;
  }

  Node *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  Node *newNode = new Node(val, nullptr, temp);
  temp->next = newNode;
  return head;
}

Node *InserAtK(Node *head, int k, int val) {
  if (head == NULL) {
    return new Node(val);
  }

  if (k == 0) {
    Node *temp = head;
    temp->next = head;
    head->back = temp;
    return temp;
  }

  Node *temp = head;
  int cnt = 1;
  while (temp->next != nullptr) {
    cnt++;
    if (cnt == k) {
      Node *newNode = new Node(val);
      newNode->next = temp->next;
      newNode->back = temp;
      temp->next = newNode;
    }

    temp = temp->next;
    return head;
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node *head = doublyToArr(arr);
  head = InserAtK(head, 2, 6);
  while (head) {
    cout << head->data;
    head = head->next;
  }
  return 0;
}
