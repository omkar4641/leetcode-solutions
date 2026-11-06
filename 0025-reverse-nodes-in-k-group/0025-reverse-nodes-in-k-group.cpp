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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        vector<int> temp;
        ListNode*curr=head;

        while(curr!=nullptr)
        {
            temp.push_back(curr->val);
            curr=curr->next;
        }


        for(int i=0;i+k<=temp.size();i+=k)
        {
            reverse(temp.begin()+i,temp.begin()+i+k);
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