// id:374566347
// runtime:0 ms
// memory:5.9 MB
// title:Binary Number to String LCCI
// translatedTitle:二进制数转字符串
// questionId:100203
// time:2022-10-19 18:07:40

class Solution {
public:
    string printBin(double num) {
        double P=0.5;
        string ret="0.";
        for(int i=0;i<10;i++){
            if(num>=P){
                num-=P;
                ret.push_back('1');
            }else{
                ret.push_back('0');
            }
            P*=0.5;
        }
        if(num>1e-8)return "ERROR";
        while(ret.back()=='0')ret.pop_back();
        if(ret.back()=='.')ret.push_back('0');
        return ret;
    }
};