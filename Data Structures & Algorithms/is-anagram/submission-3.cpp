class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> count(26);
        //---------------------
        for(int i=0;i<s.length();i++){
            int c=s[i]-'a';
            count[c]++;
        }
        for(int i=0;i<t.length();i++){
            int c=t[i]-'a';
            count[c]--;
        }
        //---------------------------
        // These 2 loops could be implemented in a single loop
        /*for (int i=0;i<s.length();i++){
            int c1=s[i]-'a';
            int c2=t[i]-'a';
            count[c1]++;
            count[c2]--;
        }*/
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }
};
