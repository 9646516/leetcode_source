// id:374853247
// runtime:4 ms
// memory:6.2 MB
// title:Pattern Matching LCCI
// translatedTitle:模式匹配
// questionId:1000004
// time:2022-10-20 16:15:05

uint64_t POW[1005];
uint64_t H[1005];
uint64_t get_hash(int l,int r){
    if(l>r)return 0;
    uint64_t ret=H[r];
    if(l)ret-=H[l-1]*POW[r-l+1];
    return ret;
}
class Solution {
public:
    bool patternMatching(string pattern, string value) {
        auto solve=[&](int len1,int len2)->bool{
            int vis1=0,vis2=0;
            uint64_t h1=0,h2=0;
            int pos=0;
            for(char i:pattern){
                if(i=='a'){
                    int pos2=pos+len1;
                    if(vis1){
                        if(get_hash(pos,pos2-1)!=h1)return 0;
                    }else{
                        h1=get_hash(pos,pos2-1);
                        vis1=1;
                    }
                    pos=pos2;
                }else{
                    int pos2=pos+len2;
                    if(vis2){
                        if(get_hash(pos,pos2-1)!=h2)return 0;
                    }else{
                        h2=get_hash(pos,pos2-1);
                        vis2=1;
                    }
                    pos=pos2;
                }
            }
            if(vis1&&vis2&&h1==h2)return 0;
            return 1;
        };

        POW[0]=1;
        for(int i=1;i<=value.size();i++)POW[i]=POW[i-1]*233;
        H[0]=value[0];
        for(int i=1;i<value.size();i++)H[i]=H[i-1]*233+value[i];
        int s0=0,s1=0;
        for(char i:pattern){
            if(i=='a')s0++;
            else s1++;
        }
        if(s0&&s1){
            for(int i=0;i<=value.size();i++){
                int len1=i*s0;
                if(len1>value.size())break;
                int len2=value.size()-len1;
                if(len2%s1)continue;
                int j=len2/s1;
                if(solve(i,j))return 1;
            }
            return 0;
        }else if(s0){
            if(value.size()%s0)return 0;
            int i=value.size()/s0;
            return solve(i,0);
        }else if(s1){
            if(value.size()%s1)return 0;
            int j=value.size()/s1;
            return solve(0,j);
        }else{
            return 0;
        }
    }
};