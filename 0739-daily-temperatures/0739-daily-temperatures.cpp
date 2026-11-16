class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
      stack<pair<int,int>> st;
      st.push({temperatures[temperatures.size()-1],temperatures.size()-1});
      vector<int> ans(temperatures.size(),0);

      for(int i=temperatures.size()-2;i>=0;i--)
      {
         while(!st.empty() && st.top().first<=temperatures[i])
         {
            st.pop();
         }

         if(st.empty())
         {
            st.push({temperatures[i],i});
            continue;
         }
         ans[i]=st.top().second-i;
         st.push({temperatures[i],i});
      }

      return ans;

    }
};