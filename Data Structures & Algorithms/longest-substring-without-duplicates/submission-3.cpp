class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
       int l=0;
       unordered_map<char,int> m;
       int maxi=INT_MIN;
       for(int r=0;r<s.length();r++){
        if(m.find(s[r])!=m.end()){
            l=max(m[s[r]]+1,l);
        }
        m[s[r]]=r;
        maxi=max(maxi,r-l+1);
       }
       return maxi; 
    }
};
