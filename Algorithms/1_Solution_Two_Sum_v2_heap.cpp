//g++ 1_Solution_Two_Sum_v2_heap.cpp -o 1_Solution_Two_Sum_v2_heap -lboost_chrono -lboost_system

//Two Sum_version#2
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
#include <unordered_map>

#include "0_helper_1_speed_meter.hpp"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;
        int vec_size = nums.size();

        // Build the hash table
        for (int i = 0; i < vec_size; i++) {
            nums_map[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < vec_size; i++) {
            int complement = target - nums[i];
            if (nums_map.count(complement) && nums_map[complement] != i) {
                return {i, nums_map[complement]};
            }
        }

        return {};
    }
};

int main() {    Solution solution;
    Speed_meter speed_meter;

    {   // test case #1
        std::cout << "test case 1: ";

        std::vector<int> vec{2,7,11,15};
        std::vector<int> correct_answer{0,1};

        speed_meter.start();
        assert(solution.twoSum(vec,9) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #2
        std::cout << "test case 2: ";

    
        std::vector<int> vec{3,2,4};
        std::vector<int> correct_answer{1,2};

        speed_meter.restart();
        assert(solution.twoSum(vec,6) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #3
        std::cout << "test case 3: ";

        std::vector<int> vec{3,3};
        std::vector<int> correct_answer{0,1};

        speed_meter.restart();
        assert(solution.twoSum(vec,6) == correct_answer);
        speed_meter.stop();
    }

    // my tests:
    {   // test case #4
        std::cout << "test case 4: ";

        std::vector<int> vec{3,4,15,25,-80,54,1054,34,-2000,-6,67,88};
        const int target = -946;
        std::vector<int> correct_answer{6,8};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #5 more elements in the vector
        std::cout << "test case 5: ";

    
        std::vector<int> vec{3,4,15,25,-80,54,1054,34,-2000,-6,67,88,-2001, -2005, -2002, -2003, -2004, -2006, -2007, -2008, -2009, 16, 17, 18, 19, 20, 21, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012, 3013, 3014, 3015, 3016, 3017, 3018, 4062, 4063, 4064, 4065, 466, 467, 6005, 10777};
        const int target = 16782;
        std::vector<int> correct_answer{47,48};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #6 // both numbers in the end of the vector of 1002 elements
        std::cout << "test case 6: ";


        const int vec_size = 1000;
        std::vector<int> vec;
        for (int i = 0; i < vec_size; ++i) {
            vec.emplace_back(i);
        }
        vec.emplace_back(-200);
        vec.emplace_back(-300);
        const int target = -500;
        std::vector<int> correct_answer{1000,1001};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #7 // both numbers in the MIDDLE of the vector of 1002 elements
        std::cout << "test case 7: ";
        
        const int vec_size = 1000;
        std::vector<int> vec;
        int i;
        for (i = 0; i < vec_size/2; ++i) {
            vec.emplace_back(i);
        }
        int index_first = i++;
        vec.emplace_back(-200);
        int index_second = i++;
        vec.emplace_back(-300);
        for (; i < vec_size/2; ++i) {
            vec.emplace_back(i);
        }
        const int target = -500;
        std::vector<int> correct_answer{index_first,index_second};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #8 // both numbers in the end of the vector of 200 002 elements
        std::cout << "test case 8: 200 002 vec sieze int the END of the vector";

        const int vec_size = 200000;
        std::vector<int> vec;
        int i;
        for (i = 0; i < vec_size; ++i) {
            vec.emplace_back(i);
        }
        int index_first = i++;
        vec.emplace_back(-200);
        int index_second = i++;
        vec.emplace_back(-300);
        const int target = -500;
        std::vector<int> correct_answer{index_first,index_second};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #9 // both numbers in the MIDDLE of the vector of 200002 elements
        std::cout << "test case 9: 200 002 vec size in the MIDDLE of the vector: ";
    
        const int vec_size = 200000;
        std::vector<int> vec;
        int i;
        for (i = 0; i < vec_size/2; ++i) {
            vec.emplace_back(i);
        }
        int index_first = i++;
        vec.emplace_back(-200);
        int index_second = i++;
        vec.emplace_back(-300);
        for (; i < vec_size/2; ++i) {
            vec.emplace_back(i);
        }
        const int target = -500;
        std::vector<int> correct_answer{index_first,index_second};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #10 // both numbers in the end of the vector of 1 000 002 elements
        std::cout << "test case 10: 1 000 002 vec size in the END of the vector: ";

        const int vec_size = 1000000;
        std::vector<int> vec;
        int i;
        for (i = 0; i < vec_size; ++i) {
            vec.emplace_back(i);
        }
        int index_first = i++;
        vec.emplace_back(-200);
        int index_second = i++;
        vec.emplace_back(-300);
        const int target = -500;
        std::vector<int> correct_answer{index_first,index_second};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }

    {   // test case #11 // both numbers in the MIDDLE of the vector of 1000002 elements
        std::cout << "test case 11: 1 000 002 vec size in the MIDDLE of the vector: ";
    
        const int vec_size = 1000000;
        std::vector<int> vec;
        int i;
        for (i = 0; i < vec_size/2; ++i) {
            vec.emplace_back(i);
        }
        int index_first = i++;
        vec.emplace_back(-200);
        int index_second = i++;
        vec.emplace_back(-300);
        for (; i < vec_size/2; ++i) {
            vec.emplace_back(i);
        }
        const int target = -500;
        std::vector<int> correct_answer{index_first,index_second};

        speed_meter.restart();
        assert(solution.twoSum(vec,target) == correct_answer);
        speed_meter.stop();
    }
}

/*
test case 1: Time taken: 6.966 microseconds
test case 2: Time taken: 2.628 microseconds
test case 3: Time taken: 1.257 microseconds
test case 4: Time taken: 5.408 microseconds
test case 5: Time taken: 20.006 microseconds
test case 6: Time taken: 349.234 microseconds
test case 7: Time taken: 169.352 microseconds
test case 8: 200 002 vec sieze int the END of the vectorTime taken: 81994.5 microseconds
test case 9: 200 002 vec size in the MIDDLE of the vector: Time taken: 38572.5 microseconds
test case 10: 1 000 002 vec size in the END of the vector: Time taken: 411441 microseconds
test case 11: 1 000 002 vec size in the MIDDLE of the vector: Time taken: 185866 microseconds
*/
