#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(l1 != NULL || l2 != NULL || carry > 0){
            int n1=0;
            int n2=0;
            if(l1 != NULL){
                n1 = l1->val;
                l1=l1->next;
            }
            if(l2 != NULL){
                n2 = l2->val;
                l2=l2->next;
            }

            int sum = n1 + n2 + carry;
            carry=sum/10;
            
            ListNode* newNode = new ListNode();
            if(sum>9){
                newNode->val = sum%10;
                temp->next = newNode;
                temp=temp->next;
            }else{
                newNode->val = sum;
                temp->next = newNode;
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};
