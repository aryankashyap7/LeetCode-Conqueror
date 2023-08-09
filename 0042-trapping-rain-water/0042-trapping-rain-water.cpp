class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l[n],r[n];
        l[0]=height[0];
        r[n-1]=height[n-1];
        for(int x=1;x<height.size();x++){
            l[x]=max(height[x],l[x-1]);
        }
        for(int x=1;x<height.size();x++){
            r[n-x-1]=max(height[n-x-1],r[n-x]);
        }
        
        int sum=0;
        for(int i=1;i<n-1;i++){
            sum+=min(l[i],r[i])-height[i];
            // cout<<min(l[i],r[i])-height[i]<<" ";
        }
        
        return sum;
    }
};