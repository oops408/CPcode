class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(-1);
        v.push_back(-1);
        int st=0;int end=nums.size()-1;
        while(st<=end){
           int mid=(st+end)/2;
           if(nums[mid]==target){
               v[0]=mid;
               end=mid-1;
           }else if(nums[mid]<target){
               st=mid+1;
           }else{
               end=mid-1;
           }
          
        }
         st=0;end=nums.size()-1;
         while(st<=end){
           int mid=(st+end)/2;
           if(nums[mid]==target){
               v[1]=mid;
               st=mid+1;
           }else if(nums[mid]<target){
               st=mid+1;
           }else{
               end=mid-1;
           }
        }
        return v;
    }
};
