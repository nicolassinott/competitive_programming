class Solution {
public:
    
    int binarySearch(vector<int>& arr, int target){
        int left = 0;
        int right = arr.size() - 1;
        int middle;

        while(left <= right){
            middle = (right - left) / 2 + left;
            if(arr[middle] == target){
                return 0;
            }
            else if (arr[middle] > target){
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        int r = INT_MAX;
        int l = INT_MAX;

        if(right >= 0 && right < arr.size()){
            r = arr[right];
        }

        if(left >=0 && left < arr.size()){
            l = arr[left];
        }

        return min(abs((long) r - target), abs((long) l - target));
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        
        for(int target : arr1)
            if(binarySearch(arr2, target) <= d){
                count++;
            }
        return arr1.size() - count;
    }
};