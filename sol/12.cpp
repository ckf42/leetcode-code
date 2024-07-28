struct Solution {
    constexpr static int card[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    constexpr static char * sym[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
    string intToRoman(int num) {
        string res = "";
        for (short i = 0; i < 13; ++i){
            while (num >= this->card[i]){
                num -= this->card[i];
                res += this->sym[i];
            }
        }
        return res;
    }
};
