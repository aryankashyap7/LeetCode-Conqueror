// O(n^2) Approach
​
class Solution {
public:
int maxProduct(const std::vector<int>& nums) {
​
int n = nums.size();
int maxProduct = INT_MIN;
for (int i = 0; i < n; i++) {
int currentProduct = 1;
for (int j = i; j < n; j++) {
currentProduct *= nums[j];
maxProduct = max(maxProduct, currentProduct);
}
}
return result;
​
}
};