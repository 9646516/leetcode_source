// id:374831194
// runtime:16 ms
// memory:12.8 MB
// title:Operations LCCI
// translatedTitle:运算
// questionId:100350
// time:2022-10-20 15:23:10

class Operations {
public:
    Operations() {

    }
    
    int minus(int a, int b) {
        return a-b;
    }
    
    int multiply(int _a, int _b) {
        //a+a...a 
        int pos=1;
        if(_a<0){
            _a*=-1;
            pos^=1;
        }
        if(_b<0){
            _b*=-1;
            pos^=1;
        }
        long long ret=0,a=_a,b=_b;
        while(b){
            if(b&1)ret=ret+a;
            a=a+a;
            b>>=1;
        }
        if(!pos)ret=-ret;
        return ret;
    }
    
    int divide(int a, int b) {
        return a/b;
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */