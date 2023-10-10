class Solution {
public:
    bool equalFrequency(string word) {
        //map to store key (first) value (second) pair
        unordered_map<char,int> uomp;

        for(int i = 0; i < word.length();i++){
            if(uomp.find(word[i]) == uomp.end()) uomp[word[i]] = 1;
            else uomp[word[i]] += 1;
        }

        //storing the lowest and highest occurences of some char/s in word
        int lowest_freq = word.length();
        int highest_freq = -1;

        for(auto i: uomp){
            if (lowest_freq > i.second) lowest_freq = i.second;
            if (highest_freq < i.second) highest_freq = i.second;
        }

        //now we find how many chars have lowest and highest counts
        // also if low and high are different AND we get another frequency 
        // we just return false 
        // example abbccc, highfreq = 3 lowfreq = 1, highcount, lowcount = 1
        // and other freq = 1
        int lowest_count = 0;
        int highest_count = 0;

        for(auto i: uomp){
            if(i.second == highest_freq) highest_count++;
            else if(i.second == lowest_freq) lowest_count++;
            else if(i.second > 0) return false;
        }

        //when highest and lowest frequencies are same
        //also as per the loop above all counts will be stored in highest 
        // because it is above in the else if statement
        // we can have these possibilities
        // 1. aaaa      high and low frequencies = 4
        // 2. abc       high and low frequencies = 1
        // 3. aazz    high and low frequencies = 2
        cout<<highest_freq<<highest_count<<endl<<lowest_freq<<lowest_count;
        if (highest_freq == lowest_freq){
            //example 1. aaaa
            // it should be OK to remove one char and still meet the condition
            if(highest_count == 1) return true;
            // example 2. abc 
            // since all frequencies are 1 we can completely eleminate
            // one character from word and still maintain frequency
            if(highest_freq == 1) return true;

            //else, false example 3. aazz; as described in problem description
            return false;
        }

        // if we see the else if in the loop on line 30 
        // "else if(i.second > 0) return false;" we have already eleminated the
        // condition that we have more than 2 different frequencies.
        // So, when we have lowest frequency to be 1 AND
        // we have already checked that highest and lowest frequencies
        // are different we have a chance to eliminate the lowest frequency char
        // given that only one unique character has 1 frequency
        // example aaabbbcddd true since we can remove c
        if(lowest_count == 1 && lowest_freq == 1) return true;
        
        // if the difference in highest and lowest is more than 1
        // example
        // 1. ddaccb
        // 2. abbb
        // 3. abccc
        if((highest_freq - lowest_freq) > 1) return false;
        
        // if its the second case we can return true since lowestcount is 1
        // but if it was abccc it will be false
        if(highest_count != 1) return false;
        
        
        return true;
    }
};