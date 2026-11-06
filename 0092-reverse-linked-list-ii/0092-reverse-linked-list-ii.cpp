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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode*curr=head;
        ListNode*a=nullptr;
        int count=1;

        while(count<left)
        {
            count++;
            a=curr;
            curr=curr->next;
        }
        ListNode*b=curr;

        ListNode* prev=nullptr;
        ListNode* temp=nullptr;
        count=left;

        while(count<=right)
        {
            count++;
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        b->next=curr;
        if(a!=nullptr)
        {
            a->next=prev;
        }
        else
        {
            return prev;
        }

        return head;

    }
};