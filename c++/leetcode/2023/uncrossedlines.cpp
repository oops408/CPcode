class Solution {
public:
    vector<vector<int>>dp;
    int helper(int i,int j,vector<int>&nums1,vector<int>&nums2){
        if(i==-1||j==-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(nums1[i]==nums2[j])return dp[i][j]=1+helper(i-1,j-1,nums1,nums2);
        return dp[i][j]=max(helper(i-1,j,nums1,nums2),helper(i,j-1,nums1,nums2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        dp.resize(n1,vector<int>(n2,-1));
        return helper(n1-1,n2-1,nums1,nums2);
    }
};
