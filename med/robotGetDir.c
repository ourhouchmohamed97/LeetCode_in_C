// Walking Robot Simulation II

#include <stdbool.h>

typedef struct {
    int w, h, per, pos;
    bool moved;
} Robot;

Robot* robotCreate(int width, int height) {
    Robot* obj = (Robot*)malloc(sizeof(Robot));
    obj->w = width;
    obj->h = height;
    obj->per = 2 * (width + height - 2);
    obj->pos = 0;
    obj->moved = false;
    return obj;
}

void robotStep(Robot* obj, int num) {
    obj->moved = true;
    obj->pos = (obj->pos + num) % obj->per;
}

int* robotGetPos(Robot* obj, int* retSize) {
    *retSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    int p = obj->pos;
    if (p < obj->w) {
        res[0] = p; 
        res[1] = 0;
    } else if (p < obj->w + obj->h - 1) {
        res[0] = obj->w - 1; \
        res[1] = p - (obj->w - 1);
    } else if (p < 2 * obj->w + obj->h - 2) {
        res[0] = (obj->w - 1) - (p - (obj->w + obj->h - 2)); 
        res[1] = obj->h - 1;
    } else {
        res[0] = 0; res[1] = obj->per - p;
    }
    return res;
}

char* robotGetDir(Robot* obj) {
    int p = obj->pos;
    if (p == 0) 
        return obj->moved ? "South" : "East";
    if (p < obj->w) 
        return "East";
    if (p < obj->w + obj->h - 1) 
        return "North";
    if (p < 2 * obj->w + obj->h - 2) 
        return "West";
    return "South";
}

void robotFree(Robot* obj) {
    free(obj);
}

/**
 * Your Robot struct will be instantiated and called as such:
 * Robot* obj = robotCreate(width, height);
 * robotStep(obj, num);
 
 * int* param_2 = robotGetPos(obj, retSize);
 
 * char* param_3 = robotGetDir(obj);
 
 * robotFree(obj);
*/