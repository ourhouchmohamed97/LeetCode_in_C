// Lexicographically Smallest Palindromic Permutation Greater Than Target

class Solution {
public:
    string lexPalindromicPermutation(const string& str, const string& target) {
        int freq[26] = {};
        for (char c : str) freq[c - 'a']++;
        
        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                if (center) return "";
                center = 'a' + i;
                freq[i]--;
            }
        }
        
        int sz = str.size();
        int half = sz / 2;
        
        for (int i = 0; i < half; i++)
            freq[target[i] - 'a'] -= 2;
        
        auto valid = [&]() {
            for (int x : freq)
                if (x < 0) return false;
            return true;
        };
        
        if (valid()) {
            string result;
            result.reserve(sz);
            result.append(target, 0, half);
            if (center) result.push_back(center);
            for (int i = half - 1; i >= 0; i--)
                result.push_back(target[i]);
            if (result > target)
                return result;
        }
        
        for (int i = half - 1; i >= 0; i--) {
            int cur = target[i] - 'a';
            freq[cur] += 2;
            if (!valid()) continue;
            
            for (int j = cur + 1; j < 26; j++) {
                if (freq[j] < 2) continue;
                freq[j] -= 2;
                
                string result;
                result.reserve(sz);
                result.append(target, 0, i);
                result.push_back('a' + j);
                
                for (int k = 0; k < 26; k++) {
                    int cnt = freq[k] / 2;
                    if (cnt > 0)
                        result.append(cnt, 'a' + k);
                }
                
                int headLen = result.size();
                if (center) result.push_back(center);
                result.resize(sz);
                for (int k = 0; k < headLen; k++)
                    result[sz - 1 - k] = result[k];
                
                return result;
            }
        }
        
        return "";
    }
};