class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>primes(n, true);
        int sz = primes.size();
        vector<int>realPrimes;

        for(int i = 2; i*i < sz; i++) {
            if(primes[i]) {    
                for(int j = i*i; j < sz; j=j+i) {
                    primes[j] = false;
                }
            }
        }

        for(int i = 2; i < sz; i++) {
            if(primes[i]) realPrimes.push_back(i);
        }

        vector<vector<int>> ans;
        int m = realPrimes.size();
        for(int i = 2; i <= n/2; i++) {
            if(primes[i] && primes[n-i]) {
                ans.push_back({i, n-i});
            }
        }

        return ans;
    }
};