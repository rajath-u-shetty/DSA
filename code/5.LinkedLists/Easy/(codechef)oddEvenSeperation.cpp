#include <iostream>
#include <string>
#include <vector>

/*struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *n) : val(x), next(n) {}
  };
  */
class Solution{
	public:
	Node* rearrange(Node* head)
	{
		//CODE HERE
		Node* even = nullptr;
		Node* odd = nullptr;
		Node* oddHead = nullptr;
		Node* evenHead = nullptr;
		
		if(head == NULL || head->next == NULL){
		    return head;
		}
	
	    Node* temp = head;
		while(temp != NULL){
		    if(temp->val % 2 == 0){
		        if(!evenHead){
		            even = evenHead = temp;
		        }else{
		            even->next = temp;
		            even = even->next;
		        }
		    }else{
		        if(!oddHead){
		            odd = oddHead  = temp;
		        }else{
		            odd->next = temp;
		            odd = odd->next;
		        }
		    }
		    temp = temp->next;
		}
		
       
        if(evenHead){
            even->next = oddHead;
            if(oddHead){
                odd->next = nullptr;
            }
        return evenHead;
        }else{
        odd->next = nullptr;
         return oddHead;   
        }
	}
};


using namespace std;

/*struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *n) : val(x), next(n) {}
  };
  */
class Solution{
	public:
	Node* rearrange(Node* head)
	{
		//CODE HERE
		Node* even = nullptr;
		Node* odd = nullptr;
		Node* oddHead = nullptr;
		Node* evenHead = nullptr;
		
		if(head == NULL || head->next == NULL){
		    return head;
		}
	
	    Node* temp = head;
		while(temp != NULL){
		    if(temp->val % 2 == 0){
		        if(!evenHead){
		            even = evenHead = temp;
		        }else{
		            even->next = temp;
		            even = even->next;
		        }
		    }else{
		        if(!oddHead){
		            odd = oddHead  = temp;
		        }else{
		            odd->next = temp;
		            odd = odd->next;
		        }
		    }
		    temp = temp->next;
		}
		
       
        if(evenHead){
            even->next = oddHead;
            if(oddHead){
                odd->next = nullptr;
            }
        return evenHead;
        }else{
        odd->next = nullptr;
         return oddHead;   
        }
	}
};

