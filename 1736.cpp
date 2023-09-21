struct Solution {
    string& maximumTime(string& time) {
        if (time[0] == '?'){
            if (time[1] == '?' || ('0' <= time[1] && time[1] <= '3')){
                time[0] = '2';
            } else {
                time[0] = '1';
            }
        }
        if (time[1] == '?'){
            time[1] = time[0] == '2' ? '3' : '9';
        }
        if (time[3] == '?'){
            time[3] = '5';
        }
        if (time[4] == '?'){
            time[4] = '9';
        }
        return time;
    }
};
