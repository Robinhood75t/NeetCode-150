class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int st = 0; 
        int end = 0;
        unordered_map<char,int> mymp;
        int maxLen = INT_MIN;
        int maxFreq = INT_MIN;
        while(end < n){
            mymp[s[end]]++;
            maxFreq = max(maxFreq,mymp[s[end]]);

            while((end - st + 1) - maxFreq > k){
                mymp[s[st]]--;
                st++;
            }
            maxLen = max(maxLen,end - st + 1);
            end++;
        }
        return maxLen;
    }
};
