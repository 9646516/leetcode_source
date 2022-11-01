// id:326148458
// runtime:12 ms
// memory:7.7 MB
// title:Basic Calculator II
// translatedTitle:基本计算器 II
// questionId:227
// time:2022-06-17 09:48:41

class Solution {
public:
    using ll=long long;
    int calculate(string s) {
        deque<ll>val;
        deque<char>op;
        ll now=0;
        for(char i:s){
            if(i==' ')continue;
            else if(isdigit(i)){
                now=now*10+i-'0';
            }else if(i=='+'||i=='-'){
                val.push_back(now);
                now=0;
                while(!op.empty()){
                    auto op1=op.back();
                    op.pop_back();
                    ll b=val.back();
                    val.pop_back();
                    ll a=val.back();
                    val.pop_back();
                    if(op1=='+'){
                        val.push_back(a+b);
                    }
                    if(op1=='-'){
                        val.push_back(a-b);
                    }
                    if(op1=='*'){
                        val.push_back(a*b);
                    }
                    if(op1=='/'){
                        val.push_back(a/b);
                    }
                }
                op.push_back(i);
            }else if(i=='*'||i=='/'){
                val.push_back(now);
                now=0;
                while(!op.empty()&&(op.back()=='*'||op.back()=='/')){
                    auto op1=op.back();
                    op.pop_back();
                    int b=val.back();
                    val.pop_back();
                    int a=val.back();
                    val.pop_back();
                    if(op1=='*'){
                        val.push_back(a*b);
                    }
                    if(op1=='/'){
                        val.push_back(a/b);
                    }
                }
                op.push_back(i);
            }
        }
        val.push_back(now);
        now=0;

        while(!op.empty()){

            auto op1=op.back();
            op.pop_back();
            ll b=val.back();
            val.pop_back();
            ll a=val.back();
            val.pop_back();
            if(op1=='+'){
                val.push_back(a+b);
            }
            if(op1=='-'){
                val.push_back(a-b);
            }
            if(op1=='*'){
                val.push_back(a*b);
            }
            if(op1=='/'){
                val.push_back(a/b);
            }
        }
        return val.back();
    }
};