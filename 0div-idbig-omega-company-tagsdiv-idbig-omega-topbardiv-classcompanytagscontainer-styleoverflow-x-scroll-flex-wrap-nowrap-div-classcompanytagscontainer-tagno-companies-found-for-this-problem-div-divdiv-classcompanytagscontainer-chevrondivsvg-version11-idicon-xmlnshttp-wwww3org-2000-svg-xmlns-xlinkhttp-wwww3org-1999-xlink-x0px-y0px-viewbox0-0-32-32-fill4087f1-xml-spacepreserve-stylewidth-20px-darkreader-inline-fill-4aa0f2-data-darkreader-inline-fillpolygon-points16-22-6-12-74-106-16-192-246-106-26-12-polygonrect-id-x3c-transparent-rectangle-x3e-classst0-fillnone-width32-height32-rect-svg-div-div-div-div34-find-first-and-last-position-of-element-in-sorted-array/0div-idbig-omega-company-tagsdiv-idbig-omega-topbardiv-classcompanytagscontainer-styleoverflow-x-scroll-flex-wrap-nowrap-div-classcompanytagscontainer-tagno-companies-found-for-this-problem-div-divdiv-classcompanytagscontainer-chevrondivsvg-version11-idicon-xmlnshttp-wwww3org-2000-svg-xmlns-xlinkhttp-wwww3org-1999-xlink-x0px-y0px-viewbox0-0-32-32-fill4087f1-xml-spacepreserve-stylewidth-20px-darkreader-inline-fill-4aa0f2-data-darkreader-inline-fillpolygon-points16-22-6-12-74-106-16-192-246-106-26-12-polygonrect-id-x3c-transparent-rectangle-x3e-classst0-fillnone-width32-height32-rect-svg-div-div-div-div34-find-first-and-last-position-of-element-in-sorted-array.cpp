class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int exit=0, flag=0, ele=0;

        for(int i=0; i<nums.size(); i++) {

            if(nums[i] == target && flag == 0) {
                ele = i; // storing the index of first target value
                ans.push_back(i); // pushing the first index
                flag = 1;
            }
            else if(nums[i] == target && flag != 0){
                exit = i; // index is updating till the last target value
            }
            
        }
        
        if(flag !=0 && exit != 0)
        ans.push_back(exit); // both first and last index found

        else if(flag !=0 && exit == 0)
        ans.push_back(ele); // only single target value is there so push it again
    
        else
        return{-1, -1};
        
        return ans;
    }
};