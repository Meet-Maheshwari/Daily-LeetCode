
static int iter=0;

class Solution {
public:
    int findPeakIdx(int si, int ei, vector<int>& arr) {
        if(si == ei) return si;

        int mid = si + (ei - si)/2;

        if(mid-1 > -1 && arr[mid-1] > arr[mid]) {
            return findPeakIdx(si, mid-1, arr);
        } 
        if(mid + 1 < arr.size() && arr[mid] < arr[mid+1]) {
            return findPeakIdx(mid+1, ei, arr);
        }
        
        return mid;

    }
 
    int peakIndexInMountainArray(vector<int>& arr) {
        int si = 0, ei = arr.size()-1;

        return findPeakIdx(si, ei, arr);
    }
};