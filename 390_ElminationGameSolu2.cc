class Solution {
public:
    int lastRemaining(int n) {
        bool fromLeft = true;
        int remaining = n;
        int step = 1;
        int head = 1;
        while(remaining > 1){
            if(fromLeft || remaining & 1){
                head += step;
            }
            remaining /= 2;
            step *= 2;
            fromLeft = !fromLeft;
        }
        return head;
    }
};
