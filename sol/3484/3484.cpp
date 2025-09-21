#include <unordered_map>
#include <ranges>

struct Spreadsheet {
    unordered_map<string, int> m_val;

    Spreadsheet(int rows) {}
    
    void setCell(string cell, int value) {
        this->m_val[cell] = value;
    }
    
    void resetCell(string cell) {
        if (this->m_val.contains(cell)){
            this->m_val.erase(cell);
        }
    }
    
    int _get(string cell) {
        if (cell[0] > '9'){
            return this->m_val[cell];
        }
        return std::stoi(cell);
    }

    int getValue(string formula) {
        int res = 0;
        for (string part : formula
            | ranges::views::drop(1)
            | ranges::views::split('+')
            | ranges::views::transform([](auto rg){return string(rg.data(), rg.size());})){
                res += this->_get(part);
            }
        return res;
    }
};

