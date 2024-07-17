struct Robot {
    constexpr static char * const dirstr[4] = {"East", "North", "West", "South"};
    int w, h, d, x, y, count, circum;
    bool moved;
    Robot(int width, int height):
        w(width), h(height),
        d(0), x(0), y(0),
        count(0), circum((width + height - 2) * 2),
        moved(false) {}
    
    inline void step(int num) {
        this->count += num;
        this->moved |= (this->count != 0);
        if (!this->moved){
            return;
        }
        this->count %= this->circum;
        if (this->count == 0){
            this->d = 3;
            this->x = 0;
            this->y = 0;
        } else if (this->count < this->w){
            this->d = 0;
            this->x = this->count;
            this->y = 0;
        } else if (this->count < this->w + this->h - 1){
            this->d = 1;
            this->x = this->w - 1;
            this->y = this->count - this->w + 1;
        } else if (this->count < this-> w * 2 + this->h - 2){
            this->d = 2;
            this->x = this->w * 2 + this->h - this->count - 3;
            this->y = this->h - 1;
        } else {
            this->d = 3;
            this->x = 0;
            this->y = (this->w + this->h) * 2 - this->count - 4;
        }
    }
    
    inline vector<int> getPos() {
        return {this->x, this->y};
    }
    
    inline string getDir() {
        return this->dirstr[this->d];
    }
};

