// Robot Collisions

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int pos;
    int health;
    char dir;
    int original_idx;
} Robot;

int compareRobots(const void* a, const void* b) {
    return ((Robot*)a)->pos - ((Robot*)b)->pos;
}

int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char* directions, int* returnSize) {
    int n = positionsSize;
    Robot* robots = (Robot*)malloc(n * sizeof(Robot));
    
    for (int i = 0; i < n; i++) {
        robots[i].pos = positions[i];
        robots[i].health = healths[i];
        robots[i].dir = directions[i];
        robots[i].original_idx = i;
    }

    qsort(robots, n, sizeof(Robot), compareRobots);

    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (robots[i].dir == 'R') {
            stack[++top] = i;
        } else {
            while (top >= 0 && robots[i].health > 0) {
                int r_idx = stack[top];
                
                if (robots[r_idx].health < robots[i].health) {
                    robots[r_idx].health = 0;
                    robots[i].health -= 1;
                    top--;
                } else if (robots[r_idx].health > robots[i].health) {
                    robots[r_idx].health -= 1;
                    robots[i].health = 0;
                } else {
                    robots[r_idx].health = 0;
                    robots[i].health = 0;
                    top--;
                }
            }
        }
    }

    int* final_healths = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        final_healths[robots[i].original_idx] = robots[i].health;
    }

    int* result = (int*)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (final_healths[i] > 0) {
            result[count++] = final_healths[i];
        }
    }

    *returnSize = count;

    free(robots);
    free(stack);
    free(final_healths);
    
    return result;
}