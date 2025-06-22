class Solution {
public:
    int decToBin(int n) {
        if(n == 1 || n == 0) return n;
        int bin = 0;
        long long pow = 1;
        int count = 0;

        while(n > 0) {
            int rem = n % 2;
            if(rem == 1) count++;
            bin += rem * pow;
            pow = pow * 10;
            n = n/2;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i <= n; i++){
            ans[i] = decToBin(i);
        }

        return ans;
    }
};