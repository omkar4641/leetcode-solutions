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
    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        vector<int> temp;
        ListNode*curr=head;

        while(curr!=nullptr)
        {
            temp.push_back(curr->val);
            curr=curr->next;
        }

        int i=0;
        int j=0;

        while(j<temp.size())
        {
            if((j-i+1)%2==0)
            {
                reverse(temp.begin()+i,temp.begin()+j+1);
            }
            int a=i;
            i=j+1;
            j=i+i-a;
        }
        j=temp.size()-1;

        if((j-i+1)%2==0)   //this is for last remaning elements when j will go out off bound in above while loop and we stil
        {                                                //need to check for last remainig elements size is even or odd
            reverse(temp.begin()+i,temp.begin()+j+1);
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