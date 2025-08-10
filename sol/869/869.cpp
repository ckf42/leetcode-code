#include <unordered_set>

struct Solution {
    static unordered_set<string> us_s_TARGET;

    static inline string to_rep(int n){
        string rep = to_string(n);
        ranges::sort(rep);
        return rep;
    }

    inline void _construct(void){
        for (int i = 0; i < 30; ++i){
            us_s_TARGET.insert(to_rep(1 << i));
        }
    }

    bool reorderedPowerOf2(int n) {
        if (us_s_TARGET.empty()){
            _construct();
        }
        return us_s_TARGET.contains(to_rep(n));
    }
};

unordered_set<string> Solution::us_s_TARGET = unordered_set<string>();
