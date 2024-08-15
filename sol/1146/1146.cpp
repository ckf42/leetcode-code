#include <unordered_map>
#include <algorithm>

struct SnapshotArray {
    struct Edit {
        int id;
        int val;
    };

    int currId;
    unordered_map<int, vector<Edit>> history;

    SnapshotArray(int length): currId(0) {}
    
    void set(int index, int val) {
        Edit e{currId, val};
        if (!history.contains(index)){
            history.insert({index, vector<Edit>{e}});
        } else {
            Edit& lastE = history[index].back();
            if (lastE.val != e.val){
                if (lastE.id != currId){
                    history[index].push_back(e);
                } else {
                    lastE = e;
                }
            }
        }
    }
    
    int snap() {
        return currId++;
    }
    
    int get(int index, int snap_id) {
        if (!history.contains(index)){
            return 0;
        } else {
            vector<Edit>& vec = history[index];
            auto it = lower_bound(
                vec.begin(), vec.end(), 
                snap_id, [](Edit x, int y){return x.id <= y;});
            if (it == vec.begin()){
                return 0;
            } else {
                return (it - 1)->val;
            }
        }
    }
};

