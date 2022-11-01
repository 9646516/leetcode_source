// id:374895710
// runtime:0 ms
// memory:5.7 MB
// title:Add Without Plus LCCI
// translatedTitle:不用加号的加法
// questionId:1000025
// time:2022-10-20 18:09:24

class Solution {
public:
    int calc(int a,int b,int c){
        if(a&&b&&c)return 3;
        if(!a&&!b&&!c)return 0;
        if(!a&&!b)return 1;
        if(!a&&!c)return 1;
        if(!b&&!c)return 1;
        return 2;
    }
    int add(int a, int b) {
        int c=0;
        int lbit=0;
        for(int i=0;i<=31;i++){
            int a1=((a>>i)&1);
            int b1=((b>>i)&1);
            int res=calc(a1,b1,lbit);
            if(res&1)c|=1<<i;
            lbit=(res>>1)&1;
        }
        return c;
    }
};