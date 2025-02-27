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

Node *InsertHead(Node *head, int val) {
  // Node *temp = new Node(val);
  // temp->next = head;
  // return temp;

  return new Node(val, head);
}

Node* InsertAtLast(Node* head, int val){
  Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = new Node(val);
  return head;
}

Node* InsertAtK(Node* head, int val, int pos){
  if(head == NULL){
    return new Node(val);
  }
  
  Node* temp = head;
  int cnt = 1;
  Node* newNode = new Node(val);
  while(temp != NULL){
    cnt++;
    if(cnt == pos){
      newNode->next = temp->next;
      temp->next = newNode;
      return head;
    }
    temp=temp->next;
  }
  
  return head;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node *head = convertToLL(arr);
  head = InsertHead(head, 2);
  Node *temp = head;
  while (temp) {
    cout << temp->data;
    temp = temp->next;
  }
}
