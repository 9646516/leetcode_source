// id:376111292
// runtime:32 ms
// memory:6.8 MB
// title:Print Zero Even Odd
// translatedTitle:打印零与奇偶数
// questionId:1216
// time:2022-10-24 20:59:07

mutex m;
condition_variable cv;
condition_variable cv2;
bool has0;
int now;
class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        now=1;
        has0=0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(1){
            {
                unique_lock lk(m);
                if(now>n)break;
                while(has0){
                    cv2.wait(lk);
                }
                if(now>n)break;
                has0=1;
                printNumber(0);
            }
            cv2.notify_one();
        }
    }

    void even(function<void(int)> printNumber) {
        while(1){
            {
                unique_lock lk(m);
                if(now>n)break;
                while(now%2==1){
                    cv.wait(lk);
                }
                if(now>n)break;
                while(!has0){
                    cv2.wait(lk);
                }
                has0=0;
                printNumber(now);
                now++;
            }   
            cv.notify_one();
            cv2.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(1){
            {
                unique_lock lk(m);
                if(now>n)break;
                while(now%2==0){
                    cv.wait(lk);
                }
                if(now>n)break;
                while(!has0){
                    cv2.wait(lk);
                }
                has0=0;
                printNumber(now);
                now++;
            }
            cv.notify_one();
            cv2.notify_one();
        }
    }
};