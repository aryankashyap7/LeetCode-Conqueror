class Solution {
public:
    bool isPalindrome(string s) {
        string ans="",rans="";
        for(char x:s){
            if(x>='A' && x<='Z')
                ans+=char(x+32);
            
            if(x>='a' && x<='z' || x>='0' && x<='9' )
                ans+=x;
        }
        rans=ans;
        reverse(rans.begin(),rans.end());
        
        return rans==ans;
    }
};