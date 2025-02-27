#include <cstddef>
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

Node *DeleteKey(Node* head, int key){
  Node* temp = head;
  while(temp != NULL){
    if(temp->data == key){
      if(temp == head){
        temp = temp->next;
      }

      Node* Next = temp->next;
      Node* prev = temp->back;

      if(Next){
        Next->back = prev;
      }

      if(prev){
        prev->next = Next;
      }

      delete temp;
      temp = Next;
    }else{
      temp = temp->next;
    }
  }
  return head;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node *head = doublyToArr(arr);
  while (head) {
    cout << head->data;
    head = head->next;
  }
  return 0;
}


