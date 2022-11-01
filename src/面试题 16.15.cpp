// id:374841442
// runtime:0 ms
// memory:5.9 MB
// title:Master Mind LCCI
// translatedTitle:珠玑妙算
// questionId:100355
// time:2022-10-20 15:47:21

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int s1=0,s2=0;
        multiset<char>a,b;
        for(int i=0;i<4;i++){
            if(solution[i]==guess[i]){
                s1++;
            }else{
                a.insert(solution[i]);
                b.insert(guess[i]);
            }
        }
        for(char i:b){
            if(a.count(i)){
                a.erase(a.lower_bound(i));
                s2++;
            }
        }
        return {s1,s2};
    }
};