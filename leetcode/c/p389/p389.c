// Source: https://leetcode.com/problems/find-the-difference/submissions/
// Date: 24.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 5.3 MB

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXWLEN 500

// Leetcode solution starts

char findTheDifference(char *s, char *t) {
	int64_t ans = 0;

	while (*s != '\0') {
		ans -= *(s++) - 'a';
		ans += *(t++) - 'a';
	}
	ans += (*t) - 'a';

	return ans + 'a';
}

// Leetcode solution ends
void makeTest() {
	char s[MAXWLEN], t[MAXWLEN];
	char ans, correctAns;

	scanf("%s", s);
	scanf("%s", t);
	scanf("\n%c", &correctAns);

	ans = findTheDifference(s, t);
	printf("%s", ans == correctAns ? "pass\n" : "fail\n");
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}