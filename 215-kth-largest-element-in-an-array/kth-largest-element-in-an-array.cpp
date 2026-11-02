class Solution {
public:
int greatestkthelement(vector<int>&nums, int &k,int n){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<n;i++){
        int element=nums[i];
       if(pq.top()<element){
        pq.pop();
        pq.push(nums[i]);
       }
    }
    return pq.top();

}
    int findKthLargest(vector<int>& nums, int k) {
       int ans=greatestkthelement(nums,k,nums.size()) ;
       return ans;
    }
};