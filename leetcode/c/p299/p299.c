// Source: https://leetcode.com/problems/bulls-and-cows/
// Date: 10.09.2020
// Solution by: David Luna
// Runtime:
// Memory usage:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Leetcode solution starts

#define NUM_ELEMENTS 10	   // From 0 to 9
#define MAX_STRING_SIZE 12 // strlen of -2147483648 is 12

char *getHint(char *secret, char *guess) {
	int bulls, cows, i;
	int times[NUM_ELEMENTS] = {0}, check[NUM_ELEMENTS] = {0};
	char *ans;

	bulls = cows = 0;
	for (i = 0; secret[i] != '\0'; ++i) {
		if (secret[i] == guess[i]) {
			++bulls;
		} else {
			check[secret[i] - '0']++;
			times[guess[i] - '0']++;
		}
	}
	for (i = 0; i < NUM_ELEMENTS; ++i) {
		cows += (check[i] > times[i] ? times[i] : check[i]);
	}

	ans = malloc((MAX_STRING_SIZE * 2 + 2) * sizeof(char));
	sprintf(ans, "%dA%dB", bulls, cows);

	return ans;
}

// Leetcode solution ends

void makeTest() {
	const int maxStringLen = 100;
	char secret[maxStringLen], guess[maxStringLen],
		correctAns[MAX_STRING_SIZE * 2 + 2];
	char *ans;

	scanf("%s %s %s", secret, guess, correctAns);
	ans = getHint(secret, guess);
	printf("%s", (strcmp(ans, correctAns) ? "fail\n" : "pass\n"));

	free(ans);
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}
