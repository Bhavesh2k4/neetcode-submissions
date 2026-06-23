class MedianFinder {
public:
    MedianFinder() {
    }
    priority_queue<int,vector<int>,greater<int>> mini;
    priority_queue<int> maxi;
    
    void addNum(int num) {
        if(maxi.empty() || num<=maxi.top()){
            maxi.push(num);
        }else{
            mini.push(num);
        }

        if(maxi.size() > mini.size()+1 ){
            mini.push(maxi.top());
            maxi.pop();
        }else if(mini.size() > maxi.size()+1){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(mini.size()==maxi.size()){
            return (mini.top()+maxi.top())/2.0;
        }
        else{
            if(maxi.size()>mini.size()){
                return maxi.top();
            }
            else{
                return mini.top();
            }
        }
    }
};
