class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
    unordered_map<string, vector<string>> graph;
    unordered_set<string> available(supplies.begin(), supplies.end());
    
    // Initialize in-degree for recipes and build dependency graph
    for (int i = 0; i < recipes.size(); i++) {
        inDegree[recipes[i]] = ingredients[i].size();  // Number of ingredients needed
        for (const string& ing : ingredients[i]) {
            graph[ing].push_back(recipes[i]);  // Ingredient -> dependent recipes
        }
    }

    queue<string> q;
    
    // Add all supplies to the queue (they can be used immediately)
    for (const string& sup : supplies) {
        q.push(sup);
    }

    vector<string> result;
    
    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        // If the current ingredient is a recipe, add it to the result
        if (inDegree.find(curr) != inDegree.end()) {
            result.push_back(curr);
        }

        // Process all recipes dependent on the current ingredient
        for (const string& dependent : graph[curr]) {
            inDegree[dependent]--;  // One less dependency
            if (inDegree[dependent] == 0) {
                q.push(dependent);  // All dependencies met, add to queue
            }
        }
    }
    
    return result;
    }
};