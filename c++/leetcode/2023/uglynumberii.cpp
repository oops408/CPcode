class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;

        for(int i = 1; i < n; i++){
          int multipleOfTwo = dp[ptr1] * 2;
          int multipleOfThree = dp[ptr2] * 3;
          int multipleOfFive = dp[ptr3] * 5;

          dp[i] = min(multipleOfTwo, min(multipleOfThree, multipleOfFive));

          if(multipleOfTwo == dp[i]){
            ptr1++;
          }
          if(multipleOfThree == dp[i]){
            ptr2++;
          }
          if(multipleOfFive == dp[i]){
            ptr3++;
          }
        }

        return dp[n - 1];
    }
};
