#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

class Solution {
std::vector<std::string> putStringInVector( std::string s) {
        std::vector<std::string> s_vec;
        std::string current_word;
        for (int i = 0; i < s.size(); ++i) {
            if ( s[i] == ' ' && !current_word.empty() ) {
                s_vec.push_back( current_word );
                current_word.clear();
            }
            if ( s[i] == ' ' ) {
                s_vec.push_back( current_word );
                current_word.clear();
            }
            else {
                current_word += s[i];
            }
        }
        s_vec.push_back( current_word );
        return s_vec;
    }
    std::vector<std::string> discardSpaces ( std::vector<std::string> s_vec ) {
        auto noSpacesEnd = std::remove_if(s_vec.begin(), s_vec.end(), [](const std::string& str) { return str.empty(); });
        s_vec.erase(noSpacesEnd, s_vec.end());
        return s_vec;
    }
    std::string createReverseString(std::vector<std::string> s_vec ) {
        std::string result;
        for ( auto word: s_vec) {
            word += ' ';
            result+=word;
        }
        if ( result.back() == ' ' ) {
            result.pop_back();
        }
        return result;
    }
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> words_vector = putStringInVector( s );
        words_vector = discardSpaces(words_vector);
        reverse(words_vector.begin(),words_vector.end());
        std::string result = createReverseString( words_vector );
        return result;
    }
};

int main()
{
    Solution s;
    {
        std::string input = " the sky is   blue";
        std::string result = s.reverseWords(input);
        assert(result == "blue is sky the");
    }

    {
        std::string input = "  hello world  ";
        std::string result = s.reverseWords(input);
        assert(result == "world hello");
    }

    {
        std::string input = "a good   example";
        std::string result = s.reverseWords(input);
        assert(result == "example good a");
    }

    return 0;
}
