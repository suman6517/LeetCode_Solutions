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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        ListNode* oddHead = head;
        ListNode* evenHead = head -> next;
        ListNode* evens = evenHead;

        while(evens != NULL && evens ->next !=NULL)
        {
            oddHead ->next = oddHead->next->next;
            evens->next = evens->next->next;

            oddHead = oddHead ->next;
            evens = evens ->next;
        }
        oddHead->next = evenHead;
        return head;
        
    }
};