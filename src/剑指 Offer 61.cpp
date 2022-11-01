// id:373653891
// runtime:0 ms
// memory:9.7 MB
// title:扑克牌中的顺子  LCOF
// translatedTitle:扑克牌中的顺子
// questionId:100341
// time:2022-10-16 22:45:06

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int>V(20);
        int s1=0;
        for(int i:nums){
            if(i==0)s1++;
            else V[i]++;
        }
        int s;
        for(int i=0;i<20;i++){
            if(V[i]){
                s=i;
                break;
            }
        }
        for(int i=s;i<s+5;i++){
            if(V[i]==0){
                if(s1==0)return 0;
                else s1--;
            }else if(V[i]==1){
                continue;
            }else if(V[i]>1){
                return 0;
            }
        }
        return 1;
    }
};