// id:374195946
// runtime:0 ms
// memory:11.4 MB
// title:生成匹配的括号
// translatedTitle:生成匹配的括号
// questionId:1000238
// time:2022-10-18 16:25:19

class Solution {
public:
    vector<string>ret;
    string now;
    void dfs(int n,int xs){
        if(n==0){
            if(xs==0){
                ret.push_back(now);
            }
            return;
        }

        now.push_back('(');
        dfs(n-1,xs+1);
        now.pop_back();

        if(xs>0){
            now.push_back(')');
            dfs(n-1,xs-1);
            now.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(2*n,0);
        return ret;
    }
};