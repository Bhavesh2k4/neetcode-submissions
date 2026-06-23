class Solution {
public:
    string calc(string a){
        vector<int> freq(26,0);
        for(int i=0;i<a.length();i++){
            int ch=a[i]-'a';
            freq[ch]++;
        }
        string ans="";
        for(int i=0;i<26;i++){
            ans+=to_string(freq[i])+"#";
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string k=calc(strs[i]);
            if(m.find(k)!=m.end()){
                m[k].push_back(strs[i]);
            }
            else{
                m[k]={strs[i]};
            }
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
