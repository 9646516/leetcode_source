// id:373924288
// runtime:4 ms
// memory:9 MB
// title:Verifying an Alien Dictionary
// translatedTitle:验证外星语词典
// questionId:990
// time:2022-10-17 20:05:00

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