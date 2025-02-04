#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node *convertToLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

Node *removeHead(Node *head) {
  if (head == NULL)
    return head;
  Node *temp = head;
  head = head->next;
  delete temp;
  return head;
}

Node *removeTail(Node *head) {
  if (head == NULL)
    return head;

  Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  delete temp->next;

  temp->next = nullptr;
  return head;
}

Node *removeKInLL(Node *head, int k) {
  Node *temp = head;

  if (head == NULL) {
    return head;
  }

  temp = head;
  if (k == 1) {
    head = head->next;
    delete temp;
    return head;
  }

  temp = head->next;
  int cnt = 1;
  Node* prevNode = NULL;
  while (temp != NULL) {
    cnt++;
    if (cnt == k) {
      prevNode->next = prevNode->next->next;
      delete temp;
      break;
    }
    prevNode = temp;
    temp = temp->next;
  }

  return head;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node *head = convertToLL(arr);
  head = removeKInLL(head, 3);
  cout << head->data << endl;
  Node *temp = head;
  while (temp) {
    cout << temp->data;
    temp = temp->next;
  }
}
