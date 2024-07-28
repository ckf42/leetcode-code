#include <stack>

struct Solution {
    vector<int> exclusiveTime(int n, const vector<string>& logs) {
        vector<int> exclTime(n, 0);
        stack<pair<int, int>> st;
        size_t colPos;
        int fid, timestamp, threadTime;
        bool isStart;
        for (const string& log: logs){
            colPos = log.find(':');
            fid = stoi(log.substr(0, colPos));
            isStart = log[colPos + 1] == 's';
            colPos = log.find(':', colPos + 1);
            timestamp = stoi(log.substr(colPos + 1));
            if (isStart){
                st.push(make_pair(fid, timestamp));
            } else {
                threadTime = timestamp - st.top().second + 1;
                exclTime[fid] += threadTime;
                st.pop();
                if (!st.empty()){
                    exclTime[st.top().first] -= threadTime;
                }
            }
        }
        return exclTime;
    }
};
