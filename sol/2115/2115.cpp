#include <unordered_map>
#include <unordered_set>

struct Solution {
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> suppSet(supplies.begin(), supplies.end());
        vector<int> indeg(n, 0), canMake;
        unordered_map<string, vector<int>> leadsTo;
        for (int i = 0; i < n; ++i){
            for (auto &ing : ingredients[i]){
                if (suppSet.contains(ing)){
                    continue;
                }
                ++indeg[i];
                leadsTo[ing].push_back(i);
            }
            if (indeg[i] == 0){
                canMake.push_back(i);
            }
        }
        vector<string> products;
        while (!canMake.empty()){
            string &target = recipes[canMake.back()];
            canMake.pop_back();
            products.push_back(target);
            for (int idx : leadsTo[target]){
                if (--indeg[idx] == 0){
                    canMake.push_back(idx);
                }
            }
        }
        return products;
    }
};
