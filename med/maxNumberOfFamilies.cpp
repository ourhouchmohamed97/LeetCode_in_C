// Cinema Seat Allocation

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        
        for (const auto& seat : reservedSeats) {
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMask[seat[0]] |= (1 << (col - 2));
            }
        }
        
        int ans = (n - rowMask.size()) * 2;
        
        const int LEFT   = 0b00001111;
        const int MIDDLE = 0b00111100;
        const int RIGHT  = 0b11110000;
        
        for (const auto& [row, mask] : rowMask) {
            bool canLeft   = (mask & LEFT) == 0;
            bool canMiddle = (mask & MIDDLE) == 0;
            bool canRight  = (mask & RIGHT) == 0;
            
            ans += (canLeft && canRight) ? 2 : (canLeft || canMiddle || canRight) ? 1 : 0;
        }
        
        return ans;
    }
};