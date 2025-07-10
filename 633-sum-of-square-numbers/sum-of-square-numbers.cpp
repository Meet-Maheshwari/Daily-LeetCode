class Solution {
public:
    bool judgeSquareSum(int c) {
        int end = int(sqrt(c));
        int start = 0;

        while(start <= end) {
            long long value = 1LL * start * start + 1LL * end * end;
            cout << value;
            if(value == c) {
                return true;
            } else if(value > c) {
                end--;
            } else {
                start++;
            }
        }

        return false;
    }
};