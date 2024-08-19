//3_Longest_Substring_Without_Repeating_Characters.cpp
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

#include <cassert>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int s_length = s.length();
        int max_Length = 0;
        std::unordered_set<char> char_Set;

        for (int right = 0, left = 0; right < s_length; right++) {
            if (char_Set.count(s[right]) == 0) {
                char_Set.insert(s[right]);
                max_Length = std::max(max_Length, right - left + 1);
            } else {
                while (char_Set.count(s[right])) {
                    char_Set.erase(s[left]);
                    left++;
                }
                char_Set.insert(s[right]);
            }
        }
        return max_Length;
    }
private:
    void printCurrentCharSet(const std::unordered_set<char>& char_set) {
        std::cout << "current char_set: ";
        for (auto& item: char_set) {
            std::cout << item;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;
    { // test case #1
        std::string input = "abcabcbb";
        std::cout << "test case #1 : " << input;
        int correct_answer = 3;
        assert( s.lengthOfLongestSubstring(input) == correct_answer );
        std::cout << std::endl;
    }

    { // test case #2
        std::string input = "bbbbb";
        std::cout << "test case #2 :" << input;
        int correct_answer = 1;
        assert( s.lengthOfLongestSubstring(input) == correct_answer );
        std::cout << std::endl;
    }

    { // test case #3
        std::string input = "pwwkew";
        std::cout << "test case #3 : " << input;
        int correct_answer = 3;
        assert( s.lengthOfLongestSubstring(input) == correct_answer );
        std::cout << std::endl;
    }
    return 0;
}
