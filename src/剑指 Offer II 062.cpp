// id:373974459
// runtime:52 ms
// memory:43.9 MB
// title:实现前缀树
// translatedTitle:实现前缀树
// questionId:1000325
// time:2022-10-17 22:00:29

struct node{
    node* next[26];
    int end;
    node(){
        for(int i=0;i<26;i++)next[i]=nullptr;
        end=0;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    node*root;
    Trie() {
        root=new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node*now=root;
        for(char i:word){
            if(!now->next[i-'a']){
                now->next[i-'a']=new node();
            }
            now=now->next[i-'a'];
        }
        now->end++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node*now=root;
        for(char i:word){
            if(!now->next[i-'a']){
                return 0;
            }
            now=now->next[i-'a'];
        }
        return now->end>0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        node*now=root;  
        for(char i:word){
            if(!now->next[i-'a']){
                return 0;
            }
            now=now->next[i-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */