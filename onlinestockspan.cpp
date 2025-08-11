class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        
        stack<pair<int,int>> st;
        int index = -1; 
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            int ans = next(arr[i],i,st);
            res.push_back(ans);
        }
        return res;
        
    }
    int next(int price,int index,stack<pair<int,int>>&st) {
       
       while(!st.empty() && st.top().second <= price){
        st.pop();
       }
       int ans = index - (st.empty() ? -1 : st.top().first);
       st.push({index,price});
       return ans;   
        }
    
  


};