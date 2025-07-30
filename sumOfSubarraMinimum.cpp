class Solution {
public:

    int* previousSmall(vector<int>&arr){
        int size = arr.size();
        int *pse = new int[size];
        std::stack<int> st;
         
        for(int i=0;i<size;i++){
           

           while(!st.empty() && arr[st.top()] > arr[i])
                  st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
         }
         return pse;
    }

    int * nextSmall(vector<int>&arr){
        int size = arr.size();
        int *nse = new int[size];
        std::stack<int> st;

        for(int i = size - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()]>= arr[i])
              st.pop();

            nse[i] = st.empty() ? size : st.top();
            st.push(i);
        }
           return nse;
        
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        int* pse =  previousSmall(arr);
        int* nse = nextSmall(arr);
        int total = 0;
        const int MOD = 1e9 + 7;

        for(int i=0;i<arr.size();i++){
        
           int left = i - pse[i];
           int right = nse[i] - i;
           total = (total + (arr[i] * 1LL * left * right) % MOD) % MOD;
        }

        return total;
    }
};