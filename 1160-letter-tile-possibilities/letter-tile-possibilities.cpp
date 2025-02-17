class Solution {
public:
    std::unordered_set<std::string> all;

    int numTilePossibilities(std::string tiles) {
        std::vector<bool> visited(tiles.size(), false);
        backtrack(tiles, "", visited);
        return all.size();
    }

    void backtrack(std::string& tiles, std::string word, std::vector<bool>& visited) {
        for (int i = 0; i < tiles.size(); i++) {
            if (visited[i]) continue;
            std::string charSequence = word + tiles[i];
            visited[i] = true;
            all.insert(charSequence);
            backtrack(tiles, charSequence, visited);
            visited[i] = false;
        }
    }
};