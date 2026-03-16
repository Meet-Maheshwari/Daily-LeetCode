class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> primes(101, true);
        int n = primes.size();

        for(int i = 2; i < n; i++) {
            if(primes[i]) {
                for(int j = i*i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        unordered_set<int> s;
        for(int i = 2; i < n; i++) {
            if(primes[i]) {
                s.insert(i);
            }
        }

        vector<int> freq(101, 0);
        n = nums.size();

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }      
        for(int i = 0; i < 101; i++) {
            if(s.count(freq[i])) {
                return true;
            }
        }

        return false;
    }
};