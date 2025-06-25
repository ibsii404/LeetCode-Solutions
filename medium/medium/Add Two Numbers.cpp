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
     // Create a dummy node to build the result linked list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy; // pointer to build the new list
        int carry = 0;          // to store carry over value

        // Loop until both l1 and l2 are exhausted and carry is zero
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = 0;

            // If l1 is not null, add its value to sum and move l1
            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // If l2 is not null, add its value to sum and move l2
            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;        // add any previous carry
            carry = sum / 10;    // calculate new carry (if sum >= 10)

            // Create a new node with the digit value (sum % 10)
            curr->next = new ListNode(sum % 10);
            curr = curr->next;   // move to the next node
        }

        // Return the next of dummy because dummy was just a placeholder
        return dummy->next;
    }   
};