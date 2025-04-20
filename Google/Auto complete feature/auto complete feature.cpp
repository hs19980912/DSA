Link: https://leetcode.com/discuss/post/6659499/google-onsite-round-2-by-anonymous_user-u340/

Auto-complete feature:

a list of known street names.
each street name: a counter for popularity.
the user enters a string, treat it as a prefix of street names.
we return a list of at most K best matched street names.
known street names: [{steven rd, 1}, {stevenson st, 2}, {ford ave, 3}]
user: "ste" => matches: [{steven rd, 1}, {stevenson st, 2}]
K=2 => steven rd, stevenson st (same matches as asked)
K=1 => stevenson st (more matches than asked)
K=3 => steven rd, stevenson st (less matches than asked)

user: "f" or "fo" or "for" or "ford" => ford ave

If there are more than k matches, then return the top k popular streets.


=====================================================================================================

class TrieNode {
    public:
        
        bool is_end_of_street;
        string street_name;
        int popularity;
    
        std::unordered_map<char, TrieNode*> children;
    
        TrieNode() : is_end_of_street(false), popularity(0) {}
    };
    
    class TrieAutocompleter {
    private:
        TrieNode* root;
    
        void insert(const string& street, int popularity) {
            TrieNode* current = root;
            
            for (char c : street) {
                char lower_c = std::tolower(c);
                if (current->children.find(lower_c) == current->children.end()) {
                    current->children[lower_c] = new TrieNode();
                }
                current = current->children[lower_c];
            }
            
            current->is_end_of_street = true;
            current->street_name = street;
            current->popularity = popularity;
        }
    
        void collectMatchesFromNode(TrieNode* node, vector<pair<string, int>>& matches) {
            if (node->is_end_of_street) {
                matches.push_back({node->street_name, node->popularity});
            }
    
            for (const auto& child : node->children) {
                collectMatchesFromNode(child.second, matches);
            }
        }
    
    public:
        TrieAutocompleter(const vector<pair<string, int>>& street_data) {
            root = new TrieNode();
            
            // Insert all streets into the trie
            for (const auto& street_pair : street_data) {
                insert(street_pair.first, street_pair.second);
            }
        }
    
        ~TrieAutocompleter() {
            // Recursive function to delete nodes
            std::function<void(TrieNode*)> deleteNode = [&](TrieNode* node) {
                if (!node) return;
                for (auto& child : node->children) {
                    deleteNode(child.second);
                }
                delete node;
            };
            
            deleteNode(root);
        }
    
        vector<string> autocomplete(const string& prefix, int k) {
            vector<pair<string, int>> matches;
            
            // Navigate to the node representing the prefix
            TrieNode* current = root;
            for (char c : prefix) {
                char lower_c = std::tolower(c);
                if (current->children.find(lower_c) == current->children.end()) {
                    // Prefix not found in trie
                    return {};
                }
                current = current->children[lower_c];
            }
            
            // Collect all streets with the given prefix
            collectMatchesFromNode(current, matches);
            
            // Sort by popularity
            sort(matches.begin(), matches.end(), 
                [](const auto& a, const auto& b) {
                    return a.second > b.second;
                });
            
            // Extract top k street names
            vector<string> result;
            for (int i = 0; i < std::min(k, static_cast<int>(matches.size())); i++) {
                result.push_back(matches[i].first);
            }
            
            return result;
        }
    };
    
    int main() {
        // Input
        vector<pair<string, int>> street_data = {
            {"steven rd", 1},
            {"stevenson st", 2},
            {"ford ave", 3}
        };
    
        TrieAutocompleter trie_autocompleter(street_data);
        
        cout << "User input: 'ste', K=2" << endl;
        auto results3 = trie_autocompleter.autocomplete("ste", 2);
        for (const auto& street : results3) {
            cout << "  " << street << endl;
        }
        
        cout << "User input: 'ford', K=1" << endl;
        auto results4 = trie_autocompleter.autocomplete("ford", 1);
        for (const auto& street : results4) {
            cout << "  " << street << endl;
        }
        
        return 0;
    }