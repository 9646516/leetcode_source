// id:374642124
// runtime:244 ms
// memory:90.5 MB
// title:Words Frequency LCCI
// translatedTitle:单词频率
// questionId:100259
// time:2022-10-19 22:02:05

class WordsFrequency {
public:
    unordered_map<string,int>mp;
    WordsFrequency(vector<string>& book) {
        for(auto&i:book)mp[i]++;
    }
    
    int get(string word) {
        if(mp.count(word))return mp[word];
        return 0;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */