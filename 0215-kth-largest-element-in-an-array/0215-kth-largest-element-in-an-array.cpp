class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap;
        int maximus=INT_MIN;
        for(auto x:nums){
            maxheap.push(x);
        }
        
        
        for(int i=0;i<k;i++){
            maximus=maxheap.top();
            maxheap.pop();
        }
     return maximus;   
    }
};
