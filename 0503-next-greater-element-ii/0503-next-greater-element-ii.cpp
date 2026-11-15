class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }

        vector<int> ans(n,-1);

        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
            {
                st.pop();
            }

            if(i<n && !st.empty())
            {
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }


        return ans;


    }
};