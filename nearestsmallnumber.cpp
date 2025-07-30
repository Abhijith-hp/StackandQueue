#include<stack>
class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
     
        vector<int>ans;
        std::stack<int>st;
        
        for(int i=0;i<arr.size();i++){
           while(!st.empty() && st.top()>=arr[i])
               st.pop();
               
           int value = st.empty() ? -1 : st.top();
           
           ans.push_back(value);
           st.push(arr[i]);
        }
        return ans;
    }
};