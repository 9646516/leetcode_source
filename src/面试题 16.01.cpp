// id:374641675
// runtime:0 ms
// memory:7.1 MB
// title:Swap Numbers LCCI
// translatedTitle:交换数字
// questionId:100258
// time:2022-10-19 22:00:54

class Solution {
public:
    vector<int> swapNumbers(vector<int>& V) {
        swap(V[0],V[1]);
        return V;
    }
};