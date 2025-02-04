#include <cstdlib>
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

Node* removeByValue(Node* head, int val){
  if(head == NULL){
    return head;
  }
  
  if(val == head->data){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
  Node* temp = head;
  Node* prev = NULL;
  while(temp != NULL){
    if(temp->data == val){
      prev->next = prev->next->next;
      delete temp;
      return head;
    }
    prev = temp;
    temp = temp->next;
  }
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node *head = convertToLL(arr);
  head = removeByValue(head, 3);
  cout << head->data << endl;
  Node *temp = head;
  while (temp) {
    cout << temp->data;
    temp = temp->next;
  }
}

