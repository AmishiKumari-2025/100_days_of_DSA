#include <stdio.h>
#include <string.h>

char firstNonRepeating(char s[]) {
    int freq[26] = {0};  // For lowercase letters

    // Step 1: Count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[1000];

    // Input
    scanf("%s", s);

    // Output
    printf("%c\n", firstNonRepeating(s));

    return 0;
}