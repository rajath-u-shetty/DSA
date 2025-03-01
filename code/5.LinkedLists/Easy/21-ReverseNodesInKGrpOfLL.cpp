#include <algorithm>
#include <cstddef>
#include <iostream>
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

Node *convertArrToLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

Node *findKthNode(Node *head, int k) {
  Node *temp = head;
  while (k--) {
    temp = temp->next;
  }
  return temp;
}

Node *reverseNode(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *temp = reverseNode(temp->next);
  Node *front = temp->next;
  front->next = head;
  head->next = nullptr;
  return temp;
}

Node *ReverseKGrp(Node *head, int k) {
  Node *temp = head;
  Node *prev = nullptr;

  while (temp != NULL) {
   Node* kthNode = findKthNode(temp, k);

    if (kthNode == NULL) {
      if (prev) {
        prev->next = temp;
      }
      break;
    }

    Node* next = kthNode->next;
    kthNode->next = nullptr;
    reverseNode(temp);

    if (temp == head) {
      head = kthNode;
    } else {
      prev->next = kthNode;
    }

    prev = temp;
    temp = next;
  }
  return head;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node *head = convertArrToLL(arr);

  Node *prev = nullptr;
  Node *temp = head;
  while (temp != NULL) {
    Node *next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }

  return 0;
}
