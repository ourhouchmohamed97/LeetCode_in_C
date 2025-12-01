class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = 0;
        for(auto el: nums) target = (target + el) % p; // sum % k essentially
        unordered_map<int, int> mp; // Our Hasmap
        mp[0] = -1; // if we are looking for 0, we can take the complete subarray[0...i]
        int cur = 0;
        int ans = 1e9;
        if(!target) return 0;
        for(int i = 0; i<n; i++){
            
            cur = (cur + nums[i]) % p;
            // we need to reach the target, lmao
            int need = (cur - target + p) % p; // This is the element we are looking for
            if(mp.find(need) != mp.end()){
                ans = min(ans, i - mp[need]);
            }
            mp[cur] = i;  // hashing the current occurence as the latest occurence of cur % p
        
        }
        
        if(ans >= n) return -1; // we cannot delethe complete array, hence
        return ans;
    }
};