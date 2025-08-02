#include <cstdlib> 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int size = asteroids.size();
        for(int i = 0;i<size;i++){
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }else{
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])) st.pop_back();
                if(st.empty() or st.back()<0) st.push_back(asteroids[i]);
                if(!st.empty() && st.back()==abs(asteroids[i])) st.pop_back();

            }
           
        }
         return st;
    }
};