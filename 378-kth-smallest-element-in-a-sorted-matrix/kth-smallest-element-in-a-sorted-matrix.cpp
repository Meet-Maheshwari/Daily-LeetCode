class Solution {
public:
    int countLessThanMid(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int col = 0, row = n-1, count = 0;

        while(row >= 0 && col < n) {
            if(matrix[row][col] <= mid) {
                count += (row+1);
                col++;
            } else {
                row--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int si = matrix[0][0], ei = matrix[n-1][n-1];

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            int count = countLessThanMid(matrix, mid);

            if(count < k) {
                si = mid+1;
            } else {
                ei = mid-1;
            }
        }

        return si;
    }
};