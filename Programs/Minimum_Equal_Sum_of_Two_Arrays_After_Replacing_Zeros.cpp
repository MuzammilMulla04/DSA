class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        
        long long sum1 = 0, sum2 = 0;
        int zero1= 0, zero2= 0;
        for(int i=0; i<m; ++i) {
            if(nums1[i] == 0) ++zero1;
            else sum1 += nums1[i];
        }
        for(int i=0; i<n; ++i) {
            if(nums2[i] == 0) ++zero2;
            else sum2 += nums2[i];
        }

        if(sum1 + zero1 > sum2 + zero2) {
            if(zero2 == 0) return -1;
        } else if(sum1 + zero1 < sum2 + zero2) {
            if(zero1 == 0) return -1;
        }

        long long ans= max(sum1 + zero1, sum2 + zero2);
        return ans;
    }
};