class Solution {
public:
// making palindrome with the half part provided
    int r(long long half,bool odd){
        if(odd)
        half/=10;

        string s=to_string(half);
        reverse(s.begin(),s.end());
        return stoll(s);
    }

//function to find closest numbers of one less and one more digit than num and check whether it is also closest then prevAns generated
   long long helper(long long num,int digits,long long prevAns){
         
       long long mn=pow(10,digits)+1,//smallest palindrome of 'n+1' digits
       mx=pow(10,digits-1)-1; //greatest palindrome of 'n-1' digits
    //    eg:-100 & 999 ,mn=1001 & mx=99.
       if(abs(mx-num)<=abs(mn-num)) //if mx is closer to the num than mn
return abs(mx-num)<=abs(prevAns-num)?mx:prevAns; //also closer than prev ans
       
       else
return abs(mn-num)<abs(prevAns-num)?mx:prevAns;
   }

    string nearestPalindromic(string n) {
        int size=n.size();
     
     long long num=stoll(n), mul=pow(10,(size)/2); 
     
        // special case for one digit numbers
           if(size==1) return to_string(num-1);

    long long half=num/mul, ans=half*mul+r(half,size%2),
    ans2=(half-1)*mul+r(half-1,size%2),ans3=(half+1)*mul+r(half+1,size%2);
    
    long long diff1=abs(num-ans),diff2=abs(num-ans2),diff3=abs(num-ans3);

        // we will generate 5 palindromes 
        // 1)with the same middlepart
        // 2)with middlepart-1
        // 3)with middlepart+1
        // 4)greatest palindrome with one digit less
        // 5)smallest palindrome with one digit extra
      long long finalAns;
       
            int minDiff=min(diff1,min(diff2,diff3));
//  here we are finding which one is closest among first three keeping in mind if any 2 are at same distance then we have to take the smaller number that's why we checked for the 'middlepart-1' number first

            if(minDiff==diff2)
            finalAns=ans2;
            else if(minDiff==diff1 ){
            if(num!=ans)
            finalAns=ans;
            else
            finalAns= diff2<=diff3? ans2 : ans3;
            }
            else 
            finalAns=ans3;

        return to_string(helper(num,size,finalAns));
    }
    
};
 