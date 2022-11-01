// id:373667386
// runtime:4 ms
// memory:9.2 MB
// title:排序数组中两个数字之和
// translatedTitle:排序数组中两个数字之和
// questionId:1000237
// time:2022-10-16 23:35:34

class Solution {
public:
    vector<int> twoSum(vector<int>& V, int target) {
        int pos=V.size()-1;
        for(int i=0;i<V.size();i++){
            while(pos>=0&&V[i]+V[pos]>target)pos--;
            if(pos>=0&&V[i]+V[pos]==target){
                return {i,pos};
            }
        }
        return {};
    }
};