// id:374859390
// runtime:20 ms
// memory:11.8 MB
// title:T9 LCCI
// translatedTitle:T9键盘
// questionId:1000047
// time:2022-10-20 16:29:22

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        set<char>st[10];
        st[2]={'a','b','c'};
        st[3]={'d','e','f'};
        st[4]={'g','h','i'};
        st[5]={'j','k','l'};
        st[6]={'m','n','o'};
        st[7]={'p','q','r','s'};
        st[8]={'t','u','v'};
        st[9]={'w','x','y','z'};
        vector<string>ret;
        auto solve=[&](string&a,string&b)->bool{
            if(a.size()!=b.size())return 0;
            for(int i=0;i<a.size();i++){
                if(st[a[i]-'0'].count(b[i]))continue;
                return 0;
            }
            return 1;
        };
        for(auto&i:words){
            if(solve(num,i)){
                ret.push_back(i);
            }
        }
        return ret;
    }
};