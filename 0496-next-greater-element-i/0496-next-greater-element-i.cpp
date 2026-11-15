class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> st;
        vector<int> nextG(nums2.size(),-1);
        st.push(nums2[nums2.size()-1]);

        for(int i=nums2.size()-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<nums2[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                st.push(nums2[i]);
                continue;
            }
            nextG[i]=st.top();
            st.push(nums2[i]);
        }

        int j=0;
        vector<int> ans(nums1.size(),-1);

        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]]=i;
        }

        for(int i=0;i<nums1.size();i++)
        {
            if(mp.find(nums1[i])!=mp.end())
            {
                ans[i]=nextG[mp[nums1[i]]];
            }
        }

        return ans;
    }
};