class Solution {
public:
    bool isValid(char c){
        if(('a'<=c && c<='z')||('A'<=c && c<='Z')||('0'<=c && c<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            while(left<right && !isValid(s[left])){
                left++;
            }
            while(left<right && !isValid(s[right])){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
