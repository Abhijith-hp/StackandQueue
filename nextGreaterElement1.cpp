#include<stack>
class Solution {

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        std::stack<int>st;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])
                  st.pop();
            
            mpp[nums2[i]] = st.empty()? -1 : st.top();

            st.push(nums2[i]);
              
        }
        for(int num:nums1)
            ans.push_back(mpp[num]);

        return ans;
        
        
    }
};