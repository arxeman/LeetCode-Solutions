class Trie {
private: 
    struct TrieNode{
        unordered_map<char,TrieNode*> children;
        bool is_word;
        TrieNode():is_word(false){}
    };
    TrieNode* root;
    void clear(TrieNode* node){
        for(auto& pair:node->children){
            clear(pair.second);
        }
        delete node;
    }
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(char ch:word){
            if(node->children.find(ch)==node->children.end()){
                node->children[ch]=new TrieNode();
            }
            node=node->children[ch];
        }
        node->is_word=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(char ch:word){
            if(node->children.find(ch)==node->children.end()){
                return false;
            }
            node=node->children[ch];
        }
        return node->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(char ch:prefix){
            if(node->children.find(ch)==node->children.end()){
                return false;
            }
            node=node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */