// id:325862293
// runtime:20 ms
// memory:7.8 MB
// title:Longest Palindromic Substring
// translatedTitle:最长回文子串
// questionId:5
// time:2022-06-16 14:13:56

class Solution {
public:
    string longestPalindrome(string sb) {
        string s;
        for(auto i:sb){
            s.push_back('$');
            s.push_back(i);
        }
        s.push_back('$');
        uint64_t H[2005];
        uint64_t P[2005];
        uint64_t H2[2005];
        H[0]=s[0];
        for(int i=1;i<s.size();i++){
            H[i]=H[i-1]*233+s[i];
        }
        H2[s.size()-1]=s[s.size()-1];
        for(int i=(int)s.size()-2;i>=0;i--){
            H2[i]=H2[i+1]*233+s[i];
        }
        P[0]=1;
        for(int i=1;i<=s.size();i++){
            P[i]=P[i-1]*233;
        }
        int res=-1;
        int pos=-1;
        for(int i=0;i<(int)s.size();i++){
            int L=0,R=s.size(),ans=0;
            while(L<=R){
                int mid=(L+R)/2;
                int l=i-mid;
                int r=i+mid;
                bool ok=0;
                if(l<0||r>=s.size()){
                    ok=0;
                }else{
                    auto hash1=H[r];
                    if(l-1>=0)hash1-=H[l-1]*P[r-l+1];
                    auto hash2=H2[l];
                    if(r+1<s.size()){
                        hash2-=H2[r+1]*P[r-l+1];
                    }
                    ok=(hash1==hash2);
                }
                if(ok){
                    ans=mid;
                    L=mid+1;
                }else{
                    R=mid-1;
                }
            }
            if(res<ans){
                res=ans;
                pos=i;
            }
        }
        string ret;
        int l=pos-res;
        int r=pos+res;
        for(int i=l;i<=r;i++){
            if(s[i]=='$')continue;
            ret.push_back(s[i]);
        }
        return ret;
    }
};