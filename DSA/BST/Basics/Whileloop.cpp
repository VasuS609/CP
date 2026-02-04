class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;

        while(low<=high){
            int mid = (int)(low + high) / 2;
            if(target == nums[mid]) return mid;
            else if( target < nums[mid]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};