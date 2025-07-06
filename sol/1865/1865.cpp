#include <unordered_map>

struct FindSumPairs {
    unordered_map<int, int> m_freq1, m_freq2;
    vector<int> m_n2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2):
        m_n2(nums2) {
        for (int x : nums1){
            ++m_freq1[x];
        }
        for (int x : nums2){
            ++m_freq2[x];
        }
    }
    
    void add(int index, int val) {
        int v = m_n2[index];
        m_n2[index] += val;
        --m_freq2[v];
        v += val;
        ++m_freq2[v];
    }
    
    int count(int tot) {
        int res = 0;
        for (auto [k, freq] : m_freq1){
            res += freq * m_freq2[tot - k];
        }
        return res;
    }
};

