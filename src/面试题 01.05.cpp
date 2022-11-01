// id:374299951
// runtime:4 ms
// memory:6.1 MB
// title:One Away LCCI
// translatedTitle:一次编辑
// questionId:1000006
// time:2022-10-18 21:27:52

class Solution {
public:
    bool oneEditAway(string a, string b) {
        if(a.size()>b.size())swap(a,b);
        if(a.size()==b.size()){
            int cnt=0;
            for(int i=0;i<a.size();i++)if(a[i]!=b[i])cnt++;
            return cnt<=1;
        }else if(a.size()+1==b.size()){
            int P=0,S=0;
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i])break;
                P++;
            }
            for(int i=0;i<a.size();i++){
                if(a[(int)a.size()-1-i]!=b[(int)b.size()-1-i])break;
                S++;
            }
            return P+S>=b.size()-1;
        }else{
            return 0;
        }
    }
};