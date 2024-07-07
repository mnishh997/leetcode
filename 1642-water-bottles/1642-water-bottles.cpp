class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int res = 0; int em = 0;
        while(nb!=0){
            res+=nb;
            em = em+nb;
            nb = 0;
            nb = em/ne;
            em = em%ne;
        }
        return res;
    }
};