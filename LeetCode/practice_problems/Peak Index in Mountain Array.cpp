class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int middle;

        while(left <= right){
            middle = (right - left) / 2 + left;

            if(!middle)
                return 1;

            if(arr[middle] - arr[middle - 1] > 0 && arr[middle + 1] - arr[middle] < 0){
                return middle;
            } else {
                if(arr[middle] - arr[middle - 1] > 0){
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return middle;
    }
};