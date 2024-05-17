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
    private:
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1 ->val < list2 ->val)
            {
                temp ->next = list1;
                temp = list1;
                list1 = list1 ->next;
            }
            else
            {
                temp ->next = list2;
                temp = list2;
                list2 = list2 ->next;
            }
        }
        if(list1 != NULL)
        {
            temp ->next = list1;
        }
        if(list2 != NULL)
        {
            temp ->next = list2;
        }
        return dummyNode ->next;
    }
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* fast = head ->next;
        ListNode* slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast ->next ->next;
            slow = slow ->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) 
    {    
        if(head == NULL || head ->next == NULL)
        {
            return head;
        }
        ListNode* middle = getMiddle(head);

        ListNode* rightHead = middle -> next;
        middle -> next = NULL;
        ListNode* leftHead = head;

         leftHead = sortList(leftHead);
         rightHead = sortList(rightHead);

        return merge(leftHead , rightHead);

    }
};