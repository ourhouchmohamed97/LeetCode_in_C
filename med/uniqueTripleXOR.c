int uniqueXorTriplets(int* nums, int numsSize) {
    const int max_xor = 2048;
    
    // Using int arrays initialized to 0 to mimic vector<bool> behavior
    int pair_xor[2048] = {0};
    int triplet_xor[2048] = {0};

    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            pair_xor[nums[i] ^ nums[j]] = 1;
        }
    }

    for (int x = 0; x < max_xor; x++) {
        if (!pair_xor[x]) continue;
        
        // C doesn't have range-based for loops, so we use an index
        for (int k = 0; k < numsSize; k++) {
            triplet_xor[x ^ nums[k]] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < max_xor; i++) {
        if (triplet_xor[i]) count++;
    }

    return count;
}