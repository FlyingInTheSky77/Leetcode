//g++ 1_Solution_Two_Sum_v1.cpp -o 1_Solution_Two_Sum_v1_tt -lboost_chrono -lboost_system

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

#include "0_helper_1_speed_meter.hpp"

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
    Speed_meter speed_meter;
    std::vector<int> vec_test;
    std::cout << "Max size of vector: " << vec_test.max_size() << std::endl;
    std::cout << "MAX INT" << INT_MAX << std::endl;

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

        vec.clear();
        vec.shrink_to_fit();
    }

    {   // test case #8 // both numbers in the end of the vector of 1 000 002 elements
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

        vec.clear();
        vec.shrink_to_fit();
    }

    {   // test case #9 // both numbers in the MIDDLE of the vector of 1000002 elements
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

        vec.clear();
        vec.shrink_to_fit();
        std::cout << std::endl << "end of test case #9" << std::endl;
    }

    std::cout << "== beetween point ==" << std::endl;

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
Max size of vector: 2305843009213693951
test case 1: Time taken: 3.406 microseconds
test case 2: Time taken: 1.025 microseconds
test case 3: Time taken: 0.625 microseconds
test case 4: Time taken: 1.216 microseconds
test case 5: Time taken: 9.333 microseconds
test case 6: Time taken: 3048.29 microseconds
test case 7: Time taken: 753.235 microseconds
test case 8: 200 002 vec sieze int the END of the vectorTime taken: 1.29159e+08 microseconds
test case 9: 200 002 vec size in the MIDDLE of the vector: Time taken: 3.10632e+07 microseconds

about test case 10 more that 20 minutes ... I interrupted the program


one more try:
/Leetcode/Algorithms$ ./1_Solution_Two_Sum_v1_tt
Max size of vector: 2305843009213693951
MAX INT2147483647
test case 1: Time taken: 3.285 microseconds
test case 2: Time taken: 0.897 microseconds
test case 3: Time taken: 0.646 microseconds
test case 4: Time taken: 1.169 microseconds
test case 5: Time taken: 9.036 microseconds
test case 6: Time taken: 3090.69 microseconds
test case 7: Time taken: 760.622 microseconds
test case 8: 200 002 vec sieze int the END of the vectorTime taken: 1.32486e+08 microseconds
test case 9: 200 002 vec size in the MIDDLE of the vector: Time taken: 3.2615e+07 microseconds

end of test case #9
== beetween point ==
test case 10: 1 000 002 vec size in the END of the vector: Time taken: 3.33354e+09 microseconds
test case 11: 1 000 002 vec size in the MIDDLE of the vector: Time taken: 8.26328e+08 microseconds

My calculation: 3333.54(test case 10) seconds and 826.328 seconds (test case 11)
*/

