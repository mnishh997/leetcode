class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        for(char c: moves) {
            if(c == 'R') h++;
            else if(c == 'L') h--;
            else if(c == 'U') v++;
            else v--;
        }
        return (h==0) && (v==0);
    }
};