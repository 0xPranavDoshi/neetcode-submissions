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
        int carry = 0;

        if (l1->val + l2->val >= 10) {
            carry = 1;
        }        

        ListNode* sum = new ListNode((l1->val + l2->val) % 10);
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        ListNode* curr = sum;            

        while (l1 || l2 || carry) {            
            int a = (l1 != nullptr) ? l1->val : 0;
            int b = (l2 != nullptr) ? l2->val : 0;    

            int s = a + b + carry;
            if (s >= 10) {
                s = s % 10;
                carry = 1;
            } else {
                carry = 0;
            }

            curr->next = new ListNode(s);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;            
        }

        return sum;
    }
};
