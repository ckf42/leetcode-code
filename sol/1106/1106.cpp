struct Solution {
    bool evalExpr(string &expr, int &ptr){
        char &c = expr[ptr];
        bool res;
        switch (c){
            case 't':
            case 'f':
                ++ptr;
                return c == 't';
            case '!':
                ptr += 2;
                res = !this->evalExpr(expr, ptr);
                ++ptr;
                return res;
            case '&':
                res = true;
                ++ptr;
                while (expr[ptr] != ')'){
                    res &= this->evalExpr(expr, ++ptr);
                }
                ++ptr;
                return res;
            case '|':
                res = false;
                ++ptr;
                while (expr[ptr] != ')'){
                    res |= this->evalExpr(expr, ++ptr);
                }
                ++ptr;
                return res;
        }
        return false;  // unreachable
    }
    bool parseBoolExpr(string &expression) {
        int ptr = 0;
        return this->evalExpr(expression, ptr);
    }
};
