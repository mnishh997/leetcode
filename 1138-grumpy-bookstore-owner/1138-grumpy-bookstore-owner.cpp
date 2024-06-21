class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> corrPreSum;
        int ssum = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ssum+=customers[i];
            }
            corrPreSum.push_back(ssum);
        }
        int i=0, j = minutes-1;
        int res = 0;
        int temp = 0;
        for(int p=0;p<=j;p++){
            temp+=customers[p];
        }
        while(j<n){
            int aux= temp;
            if(i!=0){
                aux+=corrPreSum[i-1];
            }
            aux+=corrPreSum[n-1]-corrPreSum[j];
            res=max(res, aux);
            j++;
            temp=temp-customers[i];
            i++;
            if(j<n){
                temp+=customers[j];
            }
        }
        return res;
        
    }
};