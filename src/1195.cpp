// id:376086314
// runtime:20 ms
// memory:6.7 MB
// title:Fizz Buzz Multithreaded
// translatedTitle:交替打印字符串
// questionId:1316
// time:2022-10-24 19:56:35

int now;
mutex m;
condition_variable cv;
class FizzBuzz {
private:
    int n;
public:
    FizzBuzz(int n) {
        this->n = n;
        now=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(1){
            unique_lock lk(m);
            while(!(now%3==0&&now%5!=0)){
                if(now>n)break;
                cv.wait(lk);
            }
            if(now>n)break;
            printFizz(),now++;
            cv.notify_all();
        }
        cv.notify_all();
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(1){
            unique_lock lk(m);
            while(!(now%3!=0&&now%5==0)){
                if(now>n)break;
                cv.wait(lk);
            }
            if(now>n)break;
            printBuzz(),now++;
            cv.notify_one();
        }
        cv.notify_all();
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(1){
            unique_lock lk(m);
            while(!(now%3==0&&now%5==0)){
                if(now>n)break;
                cv.wait(lk);
            }
            if(now>n)break;
            printFizzBuzz(),now++;
            cv.notify_all();
        }
        cv.notify_all();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(1){
            unique_lock lk(m);
            while(!(now%3!=0&&now%5!=0)){
                if(now>n)break;
                cv.wait(lk);
            }
            if(now>n)break;
            printNumber(now),now++;
            cv.notify_all();
        }
        cv.notify_all();
    }

};