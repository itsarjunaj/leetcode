class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n,0);
        stack<int>s;
        
        for(int i=n-1;i>=0;i--){
           
            
            while(!s.empty()&&s.top()<heights[i]){
              s.pop();
           ans[i]++;
            }  
            if(!s.empty())ans[i]++;
            s.push(heights[i]);
        }
     return ans;   
    }
};