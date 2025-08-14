class Solution {
public:
    double findPow(double x, long long n) {
        if (n <= 0) {
            return 1;
        }

        if(n % 2 == 0) {
            double halfPow = findPow(x, n/2);
            return (double)halfPow * (double)halfPow;
        } else {
            double halfPow = findPow(x, n/2);
            return x * (double)halfPow * (double)halfPow;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            N = abs(N - 0);
            return 1 / findPow(x, N);
        }

        return findPow(x, N);
    }
};