class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int currentProduct = 1;

        // Traverse the array from left to right
        for (int i = 0; i < nums.size(); i++) {
            currentProduct *= nums[i];
            maxProduct = max(maxProduct, currentProduct);
            
            // Reset currentProduct if it becomes zero
            if (currentProduct == 0)
                currentProduct = 1;
        }
        
        currentProduct = 1;  // Reset currentProduct
        
        // Traverse the array from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            currentProduct *= nums[i];
            maxProduct = max(maxProduct, currentProduct);
            
            // Reset currentProduct if it becomes zero
            if (currentProduct == 0)
                currentProduct = 1;
        }
        
        return maxProduct;
    }
};
