// id:377095613
// runtime:0 ms
// memory:6.2 MB
// title:Guess Numbers
// translatedTitle:猜数字
// questionId:100107
// time:2022-10-27 22:25:08

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans=0;
        for(int i=0;i<guess.size();i++)ans+=guess[i]==answer[i];
        return ans;
    }
};