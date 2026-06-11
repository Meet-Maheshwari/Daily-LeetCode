class Solution {
public:
    bool isPerfectSquare(int num) {
        long long si = 1, ei = num;

        while(si <= ei) {
            long long mid = si + (ei-si)/2;
            long long square = mid*mid; 

            if(square == num) {
                return true;
            }
            if(square < num) {
                si = mid + 1;
            } else {
                ei = mid - 1;
            }
        }

        return false;
    }
};