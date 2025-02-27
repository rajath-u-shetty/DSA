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


Node* DetechFirstNodeLoop(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      slow = head;
      while(slow != head){
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return  NULL;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node *head = convertArrToLL(arr);

  Node* prev = nullptr;
  Node* temp = head;
  while(temp != NULL){
    Node* next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }

  return 0;
}



