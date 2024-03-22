struct Solution {
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (auto c : tasks){
            ++freq[c - 'A'];
        }
        sort(freq, freq + 26, std::greater{});
        int chunk = freq[0] - 1;
        int idleCount = chunk * n;
        for (int i = 1; i < 26; ++i){
            if (freq[i] == 0){
                break;
            }
            idleCount -= min(chunk, freq[i]);
            if (idleCount <= 0){
                break;
            }
        }
        return tasks.size() + max(0, idleCount);
    }
};
