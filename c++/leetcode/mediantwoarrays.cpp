class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int left = 0, right = m, half = (m + n + 1) / 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums1[mid] < nums2[half - mid - 1]) left = mid + 1;
            else right = mid;
        }
        int i = left;
        int j = half - i;
        int num1 = max(i > 0 ? nums1[i - 1] : INT_MIN, j > 0 ? nums2[j - 1] : INT_MIN);
        
        if ((m + n) % 2 == 1) return num1;
        
        int num2 = min(i < m ? nums1[i] : INT_MAX, j < n ? nums2[j] : INT_MAX);
        return (num1 + num2) / 2.0;
    }
};
