// id:374297705
// runtime:44 ms
// memory:25.1 MB
// title:String to URL LCCI
// translatedTitle:URL化
// questionId:100160
// time:2022-10-18 21:22:20

class Solution {
public:
    string replaceSpaces(string S, int length) {
        S.resize(length);
        stringstream ss;
        for(auto i:S){
            if(i==' ')ss<<"%20";
            else ss<<i;
        }
        return ss.str();
    }
};