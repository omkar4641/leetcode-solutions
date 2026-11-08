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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        ListNode* curr=head;
        vector<int> temp;

        while(curr!=nullptr)
        {
            temp.push_back(curr->val);
            curr=curr->next;
        }

        k = k%temp.size();

        vector<int> temp1(temp.size());
        int j=0;
        for(int i=temp.size()-k;i<temp.size();i++)
        {
            temp1[j]=temp[i];
            j++;
        }

        for(int i=0;i<temp.size()-k;i++)
        {
            temp1[j]=temp[i];
            j++;
        }

        ListNode* now=new ListNode(temp1[0]);
        head=now;

        for(int i=1;i<temp1.size();i++)
        {
            ListNode* dummy=new ListNode(temp1[i]);
            now->next=dummy;
            now=dummy;
        }

    return head;

    }
};