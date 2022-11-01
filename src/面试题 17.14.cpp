// id:374922904
// runtime:40 ms
// memory:18.4 MB
// title:Smallest K LCCI
// translatedTitle:最小K个数
// questionId:1000021
// time:2022-10-20 19:56:08

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,less<int>>q;
        for(int i:arr){
            q.push(i);
            if(q.size()==k+1)q.pop();
        }
        vector<int>ret;
        while(!q.empty()){
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
};