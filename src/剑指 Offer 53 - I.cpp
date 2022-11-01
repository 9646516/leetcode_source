// id:373630918
// runtime:0 ms
// memory:12.7 MB
// title:在排序数组中查找数字  LCOF
// translatedTitle:在排序数组中查找数字 I
// questionId:100329
// time:2022-10-16 21:32:47

class Solution {
public:
    int search(vector<int>& V, int target) {
        auto p1=lower_bound(V.begin(),V.end(),target);
        auto p2=upper_bound(V.begin(),V.end(),target);
        if(p1==V.end()||*p1!=target)return 0;
        else{
            return p2-p1;
        }
    }
};