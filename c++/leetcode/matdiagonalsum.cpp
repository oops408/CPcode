class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0,n=mat.size(),i=0,j=n-1;
        while(i<n and j>=0){
            sum+=(mat[i][i] + mat[i][j]);
            i++; j--;
        }
        return (n%2) ? sum-mat[n/2][n/2] : sum;
    }
};
