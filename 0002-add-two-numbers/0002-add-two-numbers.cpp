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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        vector<int> temp1;
        vector<int> temp2;
        ListNode*curr=nullptr;

            curr=l1;
            while(curr!=nullptr)
            {
               temp1.push_back(curr->val);
               curr=curr->next;
            }

            curr=l2;
            while(curr!=nullptr)
            {
               temp2.push_back(curr->val);
               curr=curr->next;
            }

        vector<int> answer;
        int i=0;
        int carry=0;

        while(i<temp1.size() || i<temp2.size() || carry)
        {
            int sum=carry;
            if(i<temp1.size())
            {
                sum+=temp1[i];
            }

            if(i<temp2.size())
            {
                sum+=temp2[i];
            }

            answer.push_back(sum%10);
            carry=sum/10;
            i++;
        }
       

        ListNode*noww=new ListNode(answer[0]);
        ListNode*head=noww;

        for(int i=1;i<answer.size();i++)
        {
            ListNode*dummy=new ListNode(answer[i]);
            noww->next=dummy;
            noww=dummy;
        }

        return head;
    }
};