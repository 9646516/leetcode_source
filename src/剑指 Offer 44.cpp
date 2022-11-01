// id:373603508
// runtime:4 ms
// memory:5.9 MB
// title:数字序列中某一位的数字  LCOF
// translatedTitle:数字序列中某一位的数字
// questionId:100313
// time:2022-10-16 20:07:21

class Solution {
public:
    using ll=long long;
    ll P[11];
    ll prefix[11];
    int findNthDigit(int _n) {
        ll n=1LL*_n+1;
        P[0]=1;
        for(int i=1;i<=10;i++){
            P[i]=P[i-1]*10;
        }
        prefix[0]=0;
        for(int i=1;i<=10;i++){
            prefix[i]=i*(9*P[i-1]);
        }
        prefix[0]++;
        for(int i=1;i<=10;i++){
            prefix[i]+=prefix[i-1];
        }
        int B;
       for(int i=1;i<=10;i++){
           if(prefix[i]>=n){
               B=i;break;
           }
       }
       ll idx=n-prefix[B-1];
       int a=idx/B;
       int b=idx%B;
       if(b==0){
           b=B;
           a--;
       }
       string sb=to_string(P[B-1]+a);
       return sb[b-1]-'0';
    }
};