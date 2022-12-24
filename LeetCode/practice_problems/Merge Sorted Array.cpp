class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1;
        int idx2 = n - 1;
        
        for(int i = m + n - 1; i >= 0; i--){
            if(idx1 >= 0 && (n == 0 || idx2 < 0 || nums1.at(idx1) > nums2.at(idx2))){
                nums1.at(i) = nums1.at(idx1);
                idx1--;
            } else {
                nums1.at(i) = nums2.at(idx2);
                idx2--;
            }
        }

        return;
    }
};