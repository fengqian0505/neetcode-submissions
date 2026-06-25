class Solution {
public:
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;  // 只跳过非字母数字
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(static_cast<unsigned char>(s[i])) !=
                tolower(static_cast<unsigned char>(s[j]))) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};