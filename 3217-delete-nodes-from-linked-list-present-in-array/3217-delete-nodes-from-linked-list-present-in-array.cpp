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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        unordered_set<int> st;

        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }

        vector<int> temp;

        ListNode*curr=head;
        while(curr!=nullptr)
        {
            if(!st.count(curr->val))
            {
                temp.push_back(curr->val);
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