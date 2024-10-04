struct Solution {
    using ll = long long;
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if (n == 2){
            return skill[0] * skill[1];
        }
        int m = n >> 1;
        int totalSkill = reduce(skill.begin(), skill.end());
        if (totalSkill % m != 0){
            return -1;
        }
        int gpSum = totalSkill / m;
        ranges::sort(skill);
        ll res = 0;
        for (int i = 0; i < m; ++i){
            if (skill[i] + skill[n - 1 - i] != gpSum){
                return -1;
            }
            res += skill[i] * skill[n - 1 - i];
        }
        return res;
    }
};
