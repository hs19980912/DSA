## Simple Trie implementation

Implementing addWords and findWord functionality.

```cpp
// Node class for our N-array tree
class TreeNode {
public:
    bool isEndOfWord;
    std::unordered_map<char, TreeNode*> children;
    
    TreeNode() : isEndOfWord(false) {}
    
    ~TreeNode() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }
};

// N-array tree class (essentially a Trie for this word-finding use case)
class NArrayTree {
private:
    TreeNode* root;
    
public:
    NArrayTree() {
        root = new TreeNode();
    }
    
    ~NArrayTree() {
        delete root;
    }
    
    void addWord(const std::string& word) {
        TreeNode* current = root;
        
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TreeNode();
            }
            
            current = current->children[c];
        }

        current->isEndOfWord = true;
    }
    
    bool findWord(const std::string& word) {
        TreeNode* current = root;
        
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            
            current = current->children[c];
        }
        
        return current->isEndOfWord;
    }
};

int main() {
    NArrayTree wordTree;
    
    wordTree.addWord("hello");
    wordTree.addWord("world");
    wordTree.addWord("help");

    wordTree.findWord("world");
    wordTree.findWord("helmet");
    wordTree.findWord("welcom");
}
```