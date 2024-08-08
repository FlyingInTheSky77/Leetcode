/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

Topics: Array, Hash Table
*/
#include <vector>
#include <cassert>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> answer;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j)
            if ( (nums[i]+nums[j]) == target ) {
                answer.emplace_back(i);
                answer.emplace_back(j);
                break;
            }
            if (!answer.empty()) {
                break;
            }
        }
        return answer;
    }
};

int main() {

    Solution solution;

    {   // test case #1
        std::vector<int> vec{2,7,11,15};
        std::vector<int> correct_answer{0,1};
        assert((solution.twoSum(vec,9) == correct_answer));
    }

    {   // test case #2
        std::vector<int> vec{3,2,4};
        std::vector<int> correct_answer{1,2};
        assert((solution.twoSum(vec,6) == correct_answer));
    }

    {   // test case #3
        std::vector<int> vec{3,3};
        std::vector<int> correct_answer{0,1};
        assert((solution.twoSum(vec,6) == correct_answer));
    }
}
