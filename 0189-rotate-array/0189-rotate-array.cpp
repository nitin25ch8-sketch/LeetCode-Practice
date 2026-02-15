class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
        k = k % n;
        if (k == 0) return;
        vector<int> v;
        for(int j=nums.size()-k;j<nums.size();j++){
            v.push_back(nums[j]);
        }
        for(int l=nums.size()-1; l>=k;l--){
            nums[l]=nums[l-k];
        }
        for(int m=0; m<k;m++){
            nums[m]=v[m];
        }
    }
};