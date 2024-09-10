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
 int findGcd(int num1 , int num2)
        {
            if(num2 == 0)
            {
                return num1;
            }
            return findGcd(num2 , num1%num2);
        }

    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
       
        if(head ->next == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        while(temp ->next !=NULL)
        {
          int gcd = findGcd(temp->val, temp->next->val);
          ListNode* newNode = new ListNode(gcd,temp->next);
          temp->next = newNode;
          temp = newNode->next;
        }
        return head;
    }
};