// id:374596513
// runtime:0 ms
// memory:11.3 MB
// title:Bracket LCCI
// translatedTitle:括号
// questionId:100200
// time:2022-10-19 20:01:12

class Solution {
public:
    vector<string>ret;
    string now;
    void dfs(int x,int xs){
        if(x==0){
            if(xs==0)
                ret.push_back(now);
        }else{
            now.push_back('(');
            dfs(x-1,xs+1);
            now.pop_back();
            if(xs>=1){
                now.push_back(')');
                dfs(x-1,xs-1);
                now.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n*2,0);
        return ret;
    }
};