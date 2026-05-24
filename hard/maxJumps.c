// Jump Game V

int maxJumps(int* arr, int arrSize, int d) {
    int n = arrSize;
    int* steps = (int*)malloc(sizeof(int) * n);
    int* stack = (int*)malloc(sizeof(int) * n);

    int* pop_indices = (int*)malloc(sizeof(int) * n);
    int top = 0;
    
    for (int i = 0; i < n; i++) {
        steps[i] = 1;
    }
    
    for (int i = 0; i <= n; i++) {
        while (top > 0 && (i == n || arr[stack[top - 1]] < arr[i])) {
            int popSize = 0;
            pop_indices[popSize++] = stack[--top];
            
            while (top > 0 && arr[stack[top - 1]] == arr[pop_indices[0]]) {
                pop_indices[popSize++] = stack[--top];
            }
            
            for (int p = 0; p < popSize; p++) {
                int j = pop_indices[p];
                
                if (i < n && i - j <= d) {
                    int val = steps[j] + 1;
                    if (val > steps[i])
                        steps[i] = val;
                }
            
                if (top > 0 && j - stack[top - 1] <= d) {
                    int leftIdx = stack[top - 1];
                    int val = steps[j] + 1;
                    if (val > steps[leftIdx])
                        steps[leftIdx] = val;
                }
            }
        }
        if (i < n) {
            stack[top++] = i;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (steps[i] > ans)
            ans = steps[i];
    }
    
    free(steps);
    free(stack);
    free(pop_indices);
    return ans;
}