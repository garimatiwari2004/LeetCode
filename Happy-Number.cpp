class Solution {
public:
    int calculateSquare(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = calculateSquare(slow);
            fast = calculateSquare(calculateSquare(fast));
        } while (slow != fast);

        return slow == 1;
    }
};
