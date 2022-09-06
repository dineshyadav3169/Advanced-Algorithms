#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <iostream>

using std::vector;
using std::unordered_set;
using std::max;
using std::min;

// Find the length of longest subarray with the same 
// value in each position: O(n)
int longestSubarray(vector<int>& nums) {
    int length = 0;
    int L = 0;

    for (int R = 0; R < nums.size(); R++) {
        if (nums[L] != nums[R]) {
            L = R;
        }
        length = max(length, R - L + 1);
    }
    return length;
}

// Find length of minimum size subarray where the sum is 
// greater than or equal to the target: O(n)
int shortestSubarray(vector<int>& nums, int target) {
    int L = 0, total = 0;
    int length = INT_MAX;

    for (int R = 0; R < nums.size(); R++) {
        total += nums[R];
        while (total >= target) {
            length = min(R - L + 1, length);
            total -= nums[L];
            L++;
        }
    }
    if (length ==  INT_MAX) {
        return 0;
    } 
    return length;
}


int main() {
    vector<int> nums = {2, -1, 4, -7, 4, 3};

// std::cout << bruteForce(nums) << std::endl;
//     std::cout << kadanes(nums) << std::endl;
    
//     for (int n : slidingWindow(nums)) {
//         std::cout << n << std::endl;
//     }
//     return 0;

}