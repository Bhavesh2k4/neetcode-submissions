class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }   
        vector<int> freq(26,0);
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }
        int l=0;
        for(int r=0;r<s2.length();r++){
            freq[s2[r]-'a']--;
            if(r-l+1>s1.length()){
                freq[s2[l]-'a']++;
                l++;
            }
            if(allzero(freq)){
                return true;
            }
        }
        return false;
    }

    bool allzero(vector<int> &freq){
        for(int x:freq){
            if(x!=0){
                return false;
            }
        }
        return true;
    }
};
