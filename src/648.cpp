// id:373990905
// runtime:76 ms
// memory:34.2 MB
// title:Replace Words
// translatedTitle:单词替换
// questionId:648
// time:2022-10-17 22:42:02

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<uint64_t,string>mp;
        for(auto&i:dictionary){
            uint64_t H=0;
            for(auto j:i)H=H*233+j;
            mp[H]=i;
        }
        stringstream ss(sentence);
        string sb;
        string ans;
        while(ss>>sb){
            uint64_t H=0;
            bool ok=0;
            for(auto i:sb){
                H=H*233+i;
                if(mp.count(H)){
                    ans.append(mp[H]);
                    ok=1;
                    break;
                }
            }
            if(!ok){
                ans.append(sb);
            }
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};