// Source: https://leetcode.com/problems/length-of-last-word/
// Date: 15.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 5.3 MB

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Leetcode solution starts

int lengthOfLastWord(char *s) {
	int length, prevLength;
	bool lock;

	length = prevLength = lock = 0;
	for (; *s != '\0'; ++s) {
		if (*s == ' ' && !lock) {
			prevLength = length;
			length = 0;
			lock = true;
		} else if (*s != ' ') {
			++length;
			lock = false;
		}
	}

	return length == 0 ? prevLength : length;
}

// Leetcode solution ends

#define MAXWLEN 1000

void makeTest() {
	char c;
	char s[MAXWLEN];
	int ans, correctAns;

	while ((c = getc(stdin)) == ' ' || c == '\n')
		;
	ungetc(c, stdin);

	fgets(s, MAXWLEN, stdin);
	s[strlen(s) - 1] = '\0';
	scanf("%d", &correctAns);

	ans = lengthOfLastWord(s);
	printf("%s", (ans == correctAns ? "pass\n" : "fail\n"));
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}
