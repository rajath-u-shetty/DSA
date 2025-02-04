#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

class Node {
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }

  public:
  Node(int data1){
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

Node* RemoveHead(Node* head){
  if(head == NULL) return head;
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}

Node* RemoveTail(Node* head){
  if(head == NULL || head->next == NULL){
    return NULL;
  }

  Node* temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  return head;
}


int main() {
  vector<int> arr = {1,2,3,4,5,6};
  Node* head = convertArrToLL(arr);
  head = RemoveHead(head);
  Node* temp = head;
  while(temp){
    cout << temp->data;
    temp = temp->next;
  }
}

