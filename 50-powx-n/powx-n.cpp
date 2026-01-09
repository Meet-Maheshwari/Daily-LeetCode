class Solution {
public:
    double findPow(double x, long long n) {
        if(n == 0) return 1;

        double halfPow = 0;
        if(n % 2 == 0) {
            halfPow = findPow(x, n/2);
            return halfPow * halfPow;
        } 
        
        halfPow = findPow(x, n/2);
        return x * halfPow * halfPow;
    }

    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            long long N = -(long long)n;
            return 1/(findPow(x, N));
        }
        return findPow(x, n);
    }
};