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

Node *deleteHead(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  Node *temp = head;
  head = head->next;
  head->back = nullptr;
  temp->next = nullptr; // optional ig
  delete temp;
  return head;
}

Node* deleteTail(Node* head){
  if(head == nullptr){
    return nullptr;
  }

  if (head->next == nullptr) {
    delete head;
    return nullptr; // Return nullptr because the list is now empty
  }
  
  Node* temp = head;
  while(temp->next->next != nullptr){
    temp=temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  return head;
}

Node* deleteAtK(Node* head, int k){
  if(head == NULL){
    return head;
  }

  if (head->next == nullptr) {
    delete head;
    return nullptr;
  }
  
  if(k==0){
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    delete temp;
    return head;
  }
  
  Node* temp = head;
  int cnt=1;
  Node* prev = NULL;
  while(temp->next != nullptr){
    cnt++;
    if(cnt == k){
      prev->next = prev->next->next;
      prev->back->back = prev->back;
    }
    prev=temp;
    temp = temp->next;
  }
  delete temp;
  return head;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node *head = doublyToArr(arr);
  head = deleteTail(head);
  while (head) {
    cout << head->data;
    head = head->next;
  }
  return 0;
}

