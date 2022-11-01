// id:373818642
// runtime:4 ms
// memory:7.5 MB
// title:有效的回文
// translatedTitle:有效的回文
// questionId:1000254
// time:2022-10-17 15:06:49

class Solution {
public:
    bool isPalindrome(string s) {
        string A;
        for(char i:s){
            if(i>='a'&&i<='z')A.push_back(i);
            else if(i>='A'&&i<='Z')A.push_back(i-'A'+'a');
            else if(i>='0'&&i<='9')A.push_back(i);
        }
        int L=0;
        int R=A.size()-1;
        while(L<=R){
            if(A[L]!=A[R])return 0;
            L++;
            R--;
        }
        return 1;
    }
};