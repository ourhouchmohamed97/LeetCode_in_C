// Angle Between Hands of a Clock

#include <math.h>

double angleClock(int hour,int minutes) {
    double min_angle=minutes*6.0;
    double hr_angle=(hour%12)*30.0+minutes*0.5;

    double diff=fabs(hr_angle-min_angle);

    return fmin(diff,360.0-diff);
}