class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);

        int count = 0;
        for(int i = 2; i < n; i++) {
            if(primes[i]) {
                count++;

                for(int j = i*2; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        return count;
    }
};