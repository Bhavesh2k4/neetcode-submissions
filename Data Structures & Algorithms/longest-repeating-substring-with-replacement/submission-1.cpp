class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        unordered_map<char,int> freq;
        int maxfreq=0;
        int maxi=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]]++;
            if(freq[s[r]]>maxfreq){
                maxfreq=freq[s[r]];
            }
            while((r-l+1)-maxfreq>k){
                freq[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};
