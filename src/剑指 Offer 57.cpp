// id:373641550
// runtime:164 ms
// memory:98.2 MB
// title:和为s的两个数字 LCOF
// translatedTitle:和为s的两个数字
// questionId:100322
// time:2022-10-16 22:05:24

class Solution {
public:
    vector<int> twoSum(vector<int>& V, int target) {
        int pos=V.size()-1;
        for(int i=0;i<V.size();i++){
            while(pos>=0&&V[i]+V[pos]>target){
                pos--;
            }
            if(pos>=0&&V[i]+V[pos]==target){
                return {V[i],V[pos]};
            }
        }
        return {};
    }
};