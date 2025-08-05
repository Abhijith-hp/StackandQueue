#include<stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      std::stack <int>st;
      int maxArea= 0;
      int size = heights.size();
      int nse,pse;
      for(int i=0;i<size;i++){
        while(!st.empty() && heights[i]<heights[st.top()]){
            int element  = st.top();
            st.pop();
            nse = i;
            pse = st.empty()? -1 : st.top();
            int area = heights[element] * (nse-pse-1);
            maxArea = max(area,maxArea);
        }
        st.push(i);
        
        
      }  
      while(!st.empty()){
            int element  = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = size;
            int area = heights[element] * (nse-pse-1);
            maxArea = max(area,maxArea);
        }
      return maxArea;
    }
};