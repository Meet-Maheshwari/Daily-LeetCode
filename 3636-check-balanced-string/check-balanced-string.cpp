class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size(), evenSum = 0, oddSum = 0;

        for(int i = 0; i < n; i=i+2) {
            evenSum += num[i] - '0';
        }
        for(int i = 1; i < n; i=i+2) {
            oddSum += num[i] - '0';
        }

        cout << oddSum << " "<< evenSum;

        return evenSum == oddSum;
    }
};