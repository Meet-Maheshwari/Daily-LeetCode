class TrieNode {
public:
    TrieNode* children[26] = {};
    vector<string> suggestions;
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new TrieNode();
            node = node->children[i];
            if (node->suggestions.size() < 3)
                node->suggestions.push_back(word);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); 

        for (string& product : products)
            insert(product); 

        vector<vector<string>> result;
        TrieNode* node = root;

        for (char c : searchWord) {
            if (node)
                node = node->children[c - 'a'];
            if (node)
                result.push_back(node->suggestions);
            else
                result.push_back({});
        }

        return result;
    }
};
