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
class Compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min heap (smaller values have higher priority)
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
         // Make the Min Heap First First 
        //  priority_queue<ListNode* , vector<ListNode*>, Compare >p(lists , lists.size());
        priority_queue<ListNode* , vector<ListNode*>, Compare >p;

         for (ListNode* list : lists) {
            if (list != nullptr) {
                p.push(list);
            }
        }
         ListNode* root = new ListNode(0);
         ListNode* tail =  root;

         ListNode* temp ;

         while (!p.empty())
         {
            temp = p.top();
            p.pop();
            tail ->next =temp;
            tail = tail->next;
            if(temp->next)
            {
                p.push(temp ->next);
            }
         }

         return root->next;

    }
};