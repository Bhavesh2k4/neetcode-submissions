class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> mini;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            mini.push(nums[i]);
            if(mini.size()>k){
                mini.pop();
            }
        }
    }
    
    int add(int val) {
        mini.push(val);
        if(mini.size()>k){
            mini.pop();
        }
        return mini.top();
    }
};
