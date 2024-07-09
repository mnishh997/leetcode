class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int total_time = 0;
        double res = 0;
        for(auto it: customers){
            int arrival = it[0];
            int order_time = it[1];
            int wait = max(0, total_time - arrival);
            total_time += max(0, arrival- total_time);
            total_time+= order_time;
            res+=wait + order_time;
        }
        return res/(customers.size());
    }
};