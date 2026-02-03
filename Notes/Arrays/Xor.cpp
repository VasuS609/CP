#include <iostream>
#include <vector>
using namespace std;

int findSingleNumber(const vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // XOR accumulates
    }
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    
    // Step-by-step XOR trace:
    // result = 0
    // 0 ^ 4 = 4
    // 4 ^ 1 = 5
    // 5 ^ 2 = 7
    // 7 ^ 1 = 6
    // 6 ^ 2 = 4  ← Final answer
    
    cout << "Single number: " << findSingleNumber(nums) << endl; // Output: 4
    return 0;
}