class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);

        for (int i = 0; i < word.size(); i++) {
            int position = word[i] - 'a' + 1;
            v[position - 1]++;
        }

        sort(v.begin(), v.end(), greater<int>());

        int cost = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) break;

            int aux = i / 8;
            cost += v[i] * (aux + 1);
        }

        return cost;
    }
};