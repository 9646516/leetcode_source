// id:373323984
// runtime:36 ms
// memory:19.2 MB
// title:最小的k个数  LCOF
// translatedTitle:最小的k个数
// questionId:100301
// time:2022-10-15 22:07:26

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int>q;
        for(int i:arr){
            q.push(i);
            if(q.size()>k)q.pop();
        }
        vector<int>ret;
        while(!q.empty()){
            ret.push_back(q.top());q.pop();
        }
        return ret;
    }
};