#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <utility>
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



int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node *head = doublyToArr(arr);
  int sum =0;
  while(head != NULL){
    Node* temp = head;
    while(temp != NULL){
      if(temp->data + head->data == sum){
        return <pair<temp->data, head->data>;
      }
      temp = temp->next;
    }
    head=head->next;
  }
  while (head) {
    cout << head->data;
    head = head->next;
  }
  return 0;
}

