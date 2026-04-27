#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;
        }
        else if (mid * mid < n) {
            ans = mid;       // store possible answer
            low = mid + 1;   // move right
        }
        else {
            high = mid - 1;  // move left
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSqrt(n));
    return 0;
}