//2215. Find the Difference of Two Arrays
// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=study-plan-v2&envId=leetcode-75
/*
Easy
Topics
Companies
Hint
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/

#include <vector>
#include <cassert>
#include <set>
#include <iostream>

using std::vector;

using vec = std::vector<int>;
using vec_vec = std::vector<std::vector<int>>;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vec dif_first_from_second = findHowFirstVectorDifferentFromSecond(nums1, nums2);
        vec dif_second_from_first = findHowFirstVectorDifferentFromSecond(nums2, nums1);
        return {dif_first_from_second, dif_second_from_first};
    }
    void printVecVec(std::vector<std::vector<int>> vec_2_print) {
        std::cout << "{";
        for (const auto& item: vec_2_print) {
            std::cout << "{";
            for (const auto& it: item) {
                 std::cout << it <<' ';
            }
            std::cout << "}";
        }
        std::cout << "}\n";
    }
private:
    vec findHowFirstVectorDifferentFromSecond(vec nums1, vec nums2) {
        vec result;
        std::set<int> set2(nums2.begin(),nums2.end());
        std::set<int> set1(nums1.begin(),nums1.end());
        for (const auto& item: set1) {
            if (set2.find(item) == set2.end()) {
                result.push_back(item);
            }
        }
        return result;
    }
};

int main() {
Solution s;

{ // test case #1
    vec vec_1 = {1,2,3};
    vec vec_2 = {2,4,6};
    vec_vec result = s.findDifference(vec_1, vec_2);
    vec_vec correct_answer{{1,3},{4,6}};
    s.printVecVec(result);
    assert( result == correct_answer );
}

{ // test case #2
    vec vec_1 = {1,2,3,3};
    vec vec_2 = {1,2,2,2};
    vec_vec result = s.findDifference(vec_1, vec_2);
    vec_vec correct_answer{{3},{}};
    s.printVecVec(result);

    assert( result == correct_answer );
}
    return 0;
}
