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

Node *SortLL(Node *head1, Node *head2) {
  if (head1 == NULL) {
    return head2;
  } else if (head2 == NULL) {
    return head1;
  }

  Node* t1 = head1;
  Node* t2 = head2;
  Node* newNode = NULL;
  while(t1 != NULL || t2 != NULL){
    if(t1->data <= t2->data){
      if(!newNode){
        newNode = t1;
      }else{
        newNode->next = t1;
        newNode = newNode->next;
      }
    }else{
      if(!newNode){
        newNode = t2;
      }else{
        newNode->next = t2;
        newNode = newNode->next;
      }
    }
  }
  return newNode;

}

int main() {
  vector<int> arr1 = {3, 4, 6};
  vector<int> arr2 = {1, 2, 5};

  Node *head1 = convertToLL(arr1);
  Node *head2 = convertToLL(arr2);
  Node *newHead = SortLL(head1, head2);
  Node *temp = newHead;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
