struct Solution {
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), ptr = 0;
        bool isSingle = false;
        while (ptr < n){
            if (bits[ptr] == 0){
                isSingle = true;
                ++ptr;
            } else {
                isSingle = false;
                ++++ptr;
            }
        }
        return isSingle;
    }
};
