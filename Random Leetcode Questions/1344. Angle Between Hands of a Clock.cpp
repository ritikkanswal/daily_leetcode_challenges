class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=hour*5+(5/(double)60)*minutes;
        double y=minutes;
        double exactMin=abs(x-y);
        double degree=exactMin*6;
        return min(degree,360-degree); 
    }
};