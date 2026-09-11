// Unique 3-Digit Even Numbers

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int d : digits) freq[d]++;
        
        int count = 0;
        for (int hundreds = 1; hundreds <= 9; ++hundreds) {
            if (freq[hundreds] == 0) continue;
            freq[hundreds]--;
            
            for (int tens = 0; tens <= 9; ++tens) {
                if (freq[tens] == 0) continue;
                freq[tens]--;
                
                for (int units = 0; units <= 8; units += 2) {
                    if (freq[units] > 0) ++count;
                }
                freq[tens]++;
            }
            freq[hundreds]++;
        }
        return count;
    }
};