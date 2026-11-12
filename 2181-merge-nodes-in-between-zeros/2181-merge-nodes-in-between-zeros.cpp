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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode*curr=head->next;
        vector<int> temp;
        int a=0;

        while(curr!=nullptr)
        {
           a+=curr->val;
           if(curr->val==0)
           {
                temp.push_back(a);
                a=0;
           }
           curr=curr->next;
        }

        ListNode*now=new ListNode(temp[0]);
        head=now;

        for(int i=1;i<temp.size();i++)
        {
            ListNode*dummy=new ListNode(temp[i]);
            now->next=dummy;
            now=dummy;
        }

        return head;

    }
};