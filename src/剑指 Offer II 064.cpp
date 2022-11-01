// id:373994655
// runtime:144 ms
// memory:17.1 MB
// title:神奇的字典
// translatedTitle:神奇的字典
// questionId:1000328
// time:2022-10-17 22:51:51

uint64_t POW[105];
uint64_t H1[105];
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_set<uint64_t>st;

    MagicDictionary() {
        POW[0]=1;
        for(int i=1;i<=100;i++){
            POW[i]=POW[i-1]*233;
        }
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto&i:dictionary){
            uint64_t H=0;
            for(auto j:i){
                H=H*233+j;
            }
            st.insert(H);
        }
    }
    bool search(string s) {
        H1[0]=s[0];
        for(int i=1;i<s.size();i++){
            H1[i]=H1[i-1]*233+s[i];
        }
        for(int i=0;i<s.size();i++){
            for(int j='a';j<='z';j++){
                if(s[i]==j)continue;
                uint64_t H2=0;
                if(i)H2=H1[i-1]*POW[s.size()-1-i+1];
                H2+=j*POW[s.size()-1-i];
                H2+=H1[s.size()-1]-H1[i]*POW[s.size()-1-i];
                if(st.count(H2))return 1;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */