// Source: https://leetcode.com/problems/fizz-buzz/
// Date: 26.08.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 6.6 MB

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Leetcode solution starts

char **fizzBuzz(int n, int *returnSize) {
	const int fizzbuzzMaxLen = 9; // Len of "FizzBuzz" + '\0' = 9
	int i;
	char **ans;
	char temp[fizzbuzzMaxLen];

	*returnSize = n; // Used by leetcode to iterate through returned array
	ans = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; ++i) {
		strcpy(temp, "");
		if (((i + 1) % 3) == 0) {
			strcat(temp, "Fizz");
		}
		if (((i + 1) % 5) == 0) {
			strcat(temp, "Buzz");
		}
		if (!strcmp(temp, "")) {
			sprintf(temp, "%d", i + 1);
		}
		ans[i] = (char *)malloc(sizeof(temp));
		memcpy(ans[i], temp, sizeof(temp));
	}

	return ans;
}

// Leetcode solution ends

void makeTest() {
	const int fizzbuzzMaxLen = 9;
	int num, returnSize, i;
	char **ans, **correctAns;
	bool check;

	scanf("%d", &num);
	correctAns = (char **)malloc(num * sizeof(char *));
	for (i = 0; i < num; ++i) {
		correctAns[i] = (char *)malloc(fizzbuzzMaxLen * sizeof(char));
		scanf("%s", correctAns[i]);
	}
	ans = fizzBuzz(num, &returnSize);

	check = true;
	for (i = 0; i < num; ++i) {
		if (strcmp(ans[i], correctAns[i])) {
			check = false;
		}
	}

	printf("%s", (check ? "pass\n" : "fail\n"));

	for (i = 0; i < num; ++i) {
		free(ans[i]);
		free(correctAns[i]);
	}
	free(ans);
	free(correctAns);
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}