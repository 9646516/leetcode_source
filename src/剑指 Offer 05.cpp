// id:373272416
// runtime:4 ms
// memory:6.1 MB
// title:替换空格 LCOF
// translatedTitle:替换空格
// questionId:100280
// time:2022-10-15 19:07:24

class Solution {
public:
    string replaceSpace(string s) {
        string sb;
        for(char i:s){
            if(i==' '){
                sb.push_back('%');
                sb.push_back('2');
                sb.push_back('0');
            }else{
                sb.push_back(i);
            }
        }
        return sb;
    }
};