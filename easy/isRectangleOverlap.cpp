// Rectangle Overlap

class Solution {
public:
    bool isRectangleOverlap(const vector<int>& rec1, const vector<int>& rec2) {
        if (rec1[2] <= rec2[0] || rec1[0] >= rec2[2]) return false;
        if (rec1[3] <= rec2[1] || rec1[1] >= rec2[3]) return false;
        return true;
    }
};