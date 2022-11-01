// id:374296705
// runtime:0 ms
// memory:6.1 MB
// title:Is Unique LCCI
// translatedTitle:判定字符是否唯一
// questionId:100158
// time:2022-10-18 21:19:52

class Solution {
public:
    bool isUnique(string s) {
        int mask=0;
        for(char i:s){
            int B=i-'a';
            if((mask>>B)&1){
                return 0;
            }
            mask|=1<<B;
        }
        return 1;
    }
};