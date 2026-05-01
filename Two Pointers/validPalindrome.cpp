// without using two pointer appraoch
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char& ch: s){
            if(ch != ' ' && isalnum(ch)){
                str += tolower(ch);
            }
        }
        string t = str;
        reverse(t.begin(),t.end());
        return t == str;
    }
};
