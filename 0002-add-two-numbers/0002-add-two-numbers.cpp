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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) 
    {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* currentNode = dummyNode;
        int carry = 0;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        // Now we have to traverse to the entire LL

        while(temp1 != NULL || temp2 != NULL)
        {
            int sum = carry;

            if(temp1 != nullptr)
            {
                sum+= temp1 ->val;
            }
            if(temp2 != nullptr)
            {
                sum += temp2->val;
            }

            ListNode* firstNodeSum = new ListNode(sum %10);
            carry = sum/10;

            currentNode ->next = firstNodeSum ;

            currentNode = currentNode ->next;

            if(temp1 != nullptr) temp1 = temp1 ->next;
            if(temp2 != nullptr) temp2 = temp2 ->next;

           

        }

        // Now check if the carry is 0 or not 
        if(carry !=0 )
        {
            ListNode* addCarry = new ListNode(carry);

            currentNode ->next = addCarry;
        }

        // ListNode* afterSomeHead = dummyNode -> next;

        return dummyNode->next;

        
    }
};