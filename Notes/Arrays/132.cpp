class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return false; 

        vector<int> memo(n, INT_MAX);
        memo[1] = nums[0];

        for (int i = 1; i <= n - 1; ++i) {
            memo[i] = min(memo[i - 1], nums[i - 1]);
        }

        vector<int> stk;

        for (int i = n - 1; i >= 0; --i) {
            int curr = nums[i];
            
            while (!stk.empty() && curr > stk.back() ) {
                if (memo[i] < stk.back()) return true;
                stk.pop_back();
            }

            stk.push_back(curr);
        }
        return false;
    }
};