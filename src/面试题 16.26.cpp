// id:374886961
// runtime:16 ms
// memory:7.7 MB
// title:Calculator LCCI
// translatedTitle:计算器
// questionId:1000027
// time:2022-10-20 17:37:12

class Solution {
public:
    int calculate(string s) {
        stack<char>op;
        stack<int>val;
        int now=0;
        for(char i:s){
            if(isdigit(i)){
                now=now*10-'0'+i;
            }else if(i==' ')continue;
            else{
                val.push(now);
                now=0;
                if(i=='+'||i=='-'){
                    while(!op.empty()){
                        int b=val.top();
                        val.pop();
                        int a=val.top();
                        val.pop();
                        char opt=op.top();
                        op.pop();
                        if(opt=='+'){
                            val.push(a+b);
                        }
                        if(opt=='-'){
                            val.push(a-b);
                        }
                        if(opt=='*'){
                            val.push(a*b);
                        }
                        if(opt=='/'){
                            val.push(a/b);
                        }
                    }
                }else{
                    while(!op.empty()&&(op.top()=='*'||op.top()=='/')){
                        int b=val.top();
                        val.pop();
                        int a=val.top();
                        val.pop();
                        char opt=op.top();
                        op.pop();
                        if(opt=='*'){
                            val.push(a*b);
                        }
                        if(opt=='/'){
                            val.push(a/b);
                        }
                    }
                }
                op.push(i);
            }
        }
        val.push(now);
        while(!op.empty()){
            int b=val.top();
            val.pop();
            int a=val.top();
            val.pop();
            char opt=op.top();
            op.pop();
            if(opt=='+'){
                val.push(a+b);
            }
            if(opt=='-'){
                val.push(a-b);
            }
            if(opt=='*'){
                val.push(a*b);
            }
            if(opt=='/'){
                val.push(a/b);
            }
        }
        return val.top();
    }
};