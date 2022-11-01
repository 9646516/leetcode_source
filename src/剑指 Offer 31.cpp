// id:373301105
// runtime:0 ms
// memory:15 MB
// title:栈的压入、弹出序列 LCOF
// translatedTitle:栈的压入、弹出序列
// questionId:100306
// time:2022-10-15 20:59:07

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int p1=0,p2=0;
        while(p1<pushed.size()){
            while(!s.empty()&&p2<popped.size()&&s.top()==popped[p2]){
                s.pop();
                p2++;
            }
            s.push(pushed[p1]);
            p1++;
        }
        while(!s.empty()&&p2<popped.size()&&s.top()==popped[p2]){
            s.pop();
            p2++;
        }
        return p2==popped.size();
    }
};