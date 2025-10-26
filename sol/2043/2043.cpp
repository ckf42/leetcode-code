class Bank {
private:
    vector<long long> balance;
public:
    Bank(vector<long long>& balance): balance(balance) {}
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 >= 1 && account1 <= this->balance.size()
                && account2 >= 1 && account2 <= this->balance.size()
                && this->balance[account1 - 1] >= money
                && money >= 0) {
            this->balance[account1 - 1] -= money;
            this->balance[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account >= 1 && account <= this->balance.size()
                && money >= 0) {
            this->balance[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (account >= 1 && account <= this->balance.size()
                && money >= 0
                && money <= this->balance[account - 1]) {
            this->balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
