#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
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

Node *MergeSortLL(Node *head1, Node *head2) {
  if (!head1) {
    return head2;
  } else if (!head2) {
    return head1;
  }

  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  while (head1->next != NULL && head2->next != NULL) {
    if (head1->data <= head2->data) {
      temp->next = head1;
      temp = head1;
      head1 = head1->next;
    } else {
      temp->next = head2;
      temp = head2;
      head2 = head2->next;
    }
  }

  if (head1) {
    temp->next = head1;
  } else {
    temp->next = head2;
  }

  return dummyNode->next;
}

Node *f(Node *list[]) {
  Node *head = list[0];

  for (int i = 0; i < list.size(); i++) {
    head = MergeSortLL(head, list[i]);
  }

  return head;
}

int main() {
  vector<int> arr1 = {3, 4, 6};
  vector<int> arr2 = {1, 2, 5};

  Node *head1 = convertToLL(arr1);
  Node *head2 = convertToLL(arr2);
  Node *newHead = MergeSortLL(head1, head2);
  Node *temp = newHead;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
