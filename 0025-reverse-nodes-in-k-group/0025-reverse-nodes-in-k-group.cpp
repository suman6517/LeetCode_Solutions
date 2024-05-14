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
class Solution 
{
    public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL)
        {
            ListNode* front = temp->next;
            temp ->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp , int k)
    {
        while(temp != NULL && k >1)
        {
            k--;
            temp = temp ->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp = head;
        ListNode* prevsLast = NULL;

        while(temp != NULL)
        {
            ListNode* kthNOde = getKthNode(temp , k);

            if(kthNOde == NULL)
            {
                 if(prevsLast)
                
                    prevsLast ->next = temp;
        
                break;
            }

            ListNode* nextNode = kthNOde ->next;
            kthNOde -> next = NULL;
            reverse (temp);

            if (temp == head)
            {
                head = kthNOde;
            }
            else
            {
                prevsLast ->next = kthNOde;
            }
           prevsLast = temp;
           temp =nextNode; 

        }
        return head;

    }
};