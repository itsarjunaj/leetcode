class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int size=piles.size();
        priority_queue<int>maxheap;
        for(int i=0;i<size;i++){
            maxheap.push(piles[i]);
        }
        while(k--){
            int top=maxheap.top();
            maxheap.pop();
            int ans=top-(top/2);
            maxheap.push(ans);
            
        }
        int count=0;
       while(!maxheap.empty()){
        count+=maxheap.top();
          maxheap.pop();
          
       }
    return count;
    }
};