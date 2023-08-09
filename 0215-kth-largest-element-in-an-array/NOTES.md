This made me realise there are things like minheap,maxheap, priority queue
​
​
even the nthelement in array as a default cpp function
​
class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
return nums[k - 1];
}
};
​