#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool k = 0; // 0 for decreasing, 1 for increasing
        int i = 0;

        // Handle edge case: size 0 or 1 is trivially monotonic
        if (nums.size() <= 1) return true;

        while (i < nums.size() - 1) {
            if (nums[i] < nums[i + 1]) {
                k = 1; // found increasing
                break;
            }
            else if (nums[i] > nums[i + 1]) {
                k = 0; // found decreasing
                break;
            }
            else {
                i++;
            }
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (k == 1 && nums[i] > nums[i + 1]) return false;
            if (k == 0 && nums[i] < nums[i + 1]) return false;
        }

        return true;
    }
};

// For testing in VS
int main() {
    Solution sol;
    vector<int> test = {2, 2, 2, 1, 4, 5}; // Change this to test other cases
    cout << (sol.isMonotonic(test) ? "true" : "false") << endl;
    return 0;
}
