class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
       
        if(strs.size()==1)
            return strs[0];
        
        string prefix="{",tprefix="";
        for(int i=0;i<strs.size()-1;i++){
            int mlen=min(strs[i].size(),strs[i+1].size());
            for(int j=0;j<mlen;j++){
                if(strs[i][j]==strs[i+1][j])
                    tprefix+=strs[i][j];
                else
                    break;
            }
            prefix=min(prefix,tprefix);
            tprefix="";
        }
        return prefix == "{" ? "" : prefix;
    }
};