/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 0, high = mountainArr.length() - 1;
        int ans = INT_MAX;

        //search the mountain head
        while(low<high){
            int mid = (low+high)>>1;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low = mid + 1;
            }else{
                high = mid;
            }
        }

        int fountainHead = low;
        //searching in left 
        low = 0, high = fountainHead;
        while(low<=high){
            int mid = (low+high)>>1;
            int midElem = mountainArr.get(mid);
            if(target==midElem){
                ans = min(ans, mid);
                high = mid - 1;
            }else if(target<midElem){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        //searching in right
        low = fountainHead, high = mountainArr.length()-1;
        while(low<=high){
            int mid = (low+high)>>1;
            int midElem = mountainArr.get(mid);
            if(target==midElem){
                ans = min(ans, mid);
                high = mid - 1;
            }else if(target<midElem){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};