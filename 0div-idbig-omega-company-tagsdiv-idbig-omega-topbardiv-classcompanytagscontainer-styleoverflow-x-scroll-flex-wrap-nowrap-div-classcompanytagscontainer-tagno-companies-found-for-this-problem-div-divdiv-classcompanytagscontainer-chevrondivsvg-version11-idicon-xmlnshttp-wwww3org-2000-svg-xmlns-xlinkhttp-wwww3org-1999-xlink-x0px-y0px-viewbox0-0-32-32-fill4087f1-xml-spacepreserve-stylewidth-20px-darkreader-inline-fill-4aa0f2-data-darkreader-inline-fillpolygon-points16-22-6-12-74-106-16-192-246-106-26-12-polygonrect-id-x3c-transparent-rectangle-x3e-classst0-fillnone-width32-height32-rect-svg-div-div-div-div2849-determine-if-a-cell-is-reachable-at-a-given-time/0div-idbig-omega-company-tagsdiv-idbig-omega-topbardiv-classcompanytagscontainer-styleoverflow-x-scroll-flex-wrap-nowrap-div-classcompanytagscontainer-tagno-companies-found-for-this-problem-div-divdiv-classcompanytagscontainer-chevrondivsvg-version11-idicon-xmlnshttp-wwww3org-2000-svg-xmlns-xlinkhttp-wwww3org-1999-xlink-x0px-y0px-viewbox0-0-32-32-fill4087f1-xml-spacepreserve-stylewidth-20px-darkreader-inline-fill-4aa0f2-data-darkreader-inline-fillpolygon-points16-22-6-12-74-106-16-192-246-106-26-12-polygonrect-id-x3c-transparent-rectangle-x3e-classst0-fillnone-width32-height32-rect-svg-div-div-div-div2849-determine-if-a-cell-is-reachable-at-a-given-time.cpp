class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int a = abs(fx - sx);
        int b = abs(fy - sy);
        if(a==0 and b==0 and t==1) return false;
        return max(a,b) <= t;
    }
};