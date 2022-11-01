// id:376341444
// runtime:20 ms
// memory:10.3 MB
// title:Find Substring With Given Hash Value
// translatedTitle:查找给定哈希值的子串
// questionId:2275
// time:2022-10-25 16:26:26

class Solution {
public:
    string subStrHash(string s, int power, int MOD, int k, int hashValue) {
        long long P=1;
        for(int i=1;i<=k;i++){
            P=P*power%MOD;
        }
        long long H[20000+55];
        H[s.size()-1]=(s[s.size()-1]-'a'+1)%MOD;
        for(int i=s.size()-2;i>=0;i--){
            H[i]=H[i+1]*power+s[i]-'a'+1;
            H[i]%=MOD;
        }
        for(int i=0;i+k-1<s.size();i++){
            long long val=H[i];
            if(i+k-1!=s.size()-1){
                val=(val-H[i+k-1+1]*P%MOD)%MOD;
                val=(val+MOD)%MOD;
            }

            if(val==hashValue){
                return s.substr(i,k);
            }
        }
        return "";
    }
};