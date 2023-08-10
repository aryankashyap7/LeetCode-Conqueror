class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int maxcontainer=0;
        int left=0;
        int right=n-1;
        
        while(right>=left){
            int minheight=min(height[right],height[left]);
            int width=right-left;
            maxcontainer=max(maxcontainer,minheight*width);
            
            if(height[left]<height[right])
                left++;
            else
                right--;
            
        }
        return maxcontainer;
    }
};