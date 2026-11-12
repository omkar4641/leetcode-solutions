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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()<1)
        {
            return nullptr;
        }

        vector<int> temp;
        for(int i=0;i<lists.size();i++)
        {
            ListNode*curr=lists[i];
            if(curr==nullptr)
            {
                continue;
            }

            while(curr!=nullptr)
            {
                temp.push_back(curr->val);
                curr=curr->next;
            }
        }

        if(temp.empty())
        {
            return nullptr;
        }

        sort(temp.begin(),temp.end());

        ListNode*now=new ListNode(temp[0]);
        ListNode*head=now;
        
        for(int i=1;i<temp.size();i++)
        {
            ListNode* dummy=new ListNode(temp[i]);
            now->next=dummy;
            now=dummy;
        }

        return head;

    }
};