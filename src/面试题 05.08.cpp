// id:374584745
// runtime:0 ms
// memory:7 MB
// title:Draw Line LCCI
// translatedTitle:绘制直线
// questionId:100196
// time:2022-10-19 19:25:58

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int>ret(length);
        for(int i=x1;i<=x2;){
            int pos=y*w+i;
            int idx=pos/32;
            int now=pos%32;
            if(now==0&&i+32<=x2){
                ret[idx]=-1;
                i+=32;
            }else{
                now=31-now;
                ret[idx]|=1<<now;
                i++;
            }
        }
        return ret;
    }
};