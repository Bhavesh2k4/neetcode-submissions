class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=INT_MIN;
        int n=s.length();
        int start=0;
        for(int i=0;i<s.length();i++){
            //odd length palindrome bab
            //                      l i r
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                int len=r-l+1;
                if(len>maxi){
                    maxi=len;
                    start=l;
                }
                l--;
                r++;
            }
            //even length palindrome abba
            //                        i r
            //                        l
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                int len=r-l+1;
                if(len>maxi){
                    start=l;
                    maxi=len;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxi);
    }
};
