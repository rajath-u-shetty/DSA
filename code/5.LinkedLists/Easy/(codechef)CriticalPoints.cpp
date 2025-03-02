#include <iostream>
#include <string>
#include <vector>

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


/*
Node is defined as:
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data = data;
      this->next = nullptr;
  }
}
*/
int solve(Node* head){
    if(head == NULL){
        return 0;
    }
    
    if(head->next == NULL){
        return 1;
    }
    
    Node* temp = head->next;
    Node* prev = head;
    int cnt=0;
    while(temp->next != NULL){
        if(temp->data > prev->data && temp->data > temp->next->data){
            cnt++;
        }else if(temp->data < prev->data && temp->data < temp->next->data){
            cnt++;
        }
        prev = temp;
        temp = temp->next;
    }
    
    return cnt;
}

