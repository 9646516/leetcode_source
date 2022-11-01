// id:373895045
// runtime:4 ms
// memory:9.2 MB
// title:外星语言是否排序
// translatedTitle:外星语言是否排序
// questionId:1000276
// time:2022-10-17 18:31:16

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char mp[255];
        for(int i=0;i<26;i++){
            mp[order[i]]='a'+i;
        }
        for(auto&i:words){
            for(auto&j:i){
                j=mp[j];
            }
        }
        for(int i=1;i<words.size();i++){
            if(words[i]<words[i-1])return 0;
        }
        return 1;
    }
};