#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *child;

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

Node *merge2LL(Node *list1, Node *list2) {
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  while (list1->next != NULL && list2->next != NULL) {
    if (list1->data <= list2->data) {
      temp->child = list1;
      temp = list1;
      list1 = list1->next;
    } else {
      temp->child = list2;
      temp = list2;
      list2 = list2->next;
    }
    temp->next = nullptr;
  }
  if (list1) {
    temp->next = list1;
  } else {
    temp->next = list2;
  }
  return dummyNode->next;
}

Node* f(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }

  Node* mergedHead = f(head->next);
  return merge2LL(head, mergedHead);
}

int main() {
  vector<int> arr1 = {3, 4, 6};

  Node *head = convertToLL(arr1);
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
