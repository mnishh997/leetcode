class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
       
        int n = positions.size();
        map<int, pair<int, int>> m;
        for(int i=0;i<n;i++) {
            m[positions[i]] = make_pair(healths[i], 1);
            if(directions[i] == 'L') {
                m[positions[i]].second *= -1;
            }
        }

        stack<pair<int, pair<int, int>>> st; // pos, health, direction

        for(auto it = m.begin(); it != m.end();it++) {
            if(!st.empty() && st.top().second.second > it->second.second) {
                // this means they will collide
                if(st.top().second.first > it->second.first) {
                    st.top().second.first -= 1;
                }
                else if(st.top().second.first < it->second.first) {
                    st.pop();
                    it->second.first -= 1;
                    it--;
                }
                else {
                    st.pop();
                }
            }
            else {
                // they will not collide 
                st.push(make_pair(it->first, make_pair(it->second.first, it->second.second)));
            }
        }
        map<int, int> gg;
        while(!st.empty()) {
            gg[st.top().first] = st.top().second.first;
            st.pop();
        }
        vector<int> res;
        for(auto it: positions) {
            if(gg.find(it) != gg.end()) {
                res.push_back(gg[it]);
            }
        }
        return res;
    }
};