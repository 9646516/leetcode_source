// id:373896387
// runtime:4 ms
// memory:11.7 MB
// title:后缀表达式
// translatedTitle:后缀表达式
// questionId:1000279
// time:2022-10-17 18:37:44

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(auto&i:tokens){
            if(i=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
            }else if(i=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }else if(i=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a*b);
            }else if(i=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }else{
                st.push(stoll(i));
            }
        }
        return st.top();
    }
};