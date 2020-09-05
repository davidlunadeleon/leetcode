// Source: https://leetcode.com/problems/partition-labels/
// Date: 04.09.2020
// Solution by: David Luna
// Runtime: 0ms
// Memory usage: 5.5 MB

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Leetcode solution starts

int *partitionLabels(char *S, int *returnSize) {
	int lastPos[26] = {-1};
	int i, j, size, max;
	int *ans;

	ans = malloc(26 * sizeof(int));
	for (i = 0; S[i] != '\0'; ++i) {
		lastPos[S[i] - 'a'] = i;
	}
	for (i = 0, size = 0; S[i] != '\0'; ++i) {
		max = lastPos[S[i] - 'a'];
		for (j = i; j < max; ++j) {
			if (lastPos[S[j] - 'a'] > max && j < max) {
				max = lastPos[S[j] - 'a'];
			}
		}
		ans[size++] = max - i + 1;
		i = j;
	}

	ans = realloc(ans, size * sizeof(int));
	*returnSize = size;
	return ans;
}

// Leetcode solution ends

void makeTest() {
	char s[500];
	int returnSize, numElemens, i;
	int *ans, *correctAns;
	bool check;

	check = true;
	scanf("%s %d", s, &numElemens);
	ans = partitionLabels(s, &returnSize);

	if (returnSize == numElemens) {
		correctAns = malloc(numElemens * sizeof(int));
		for (i = 0; i < numElemens; ++i) {
			scanf("%d", &correctAns[i]);
		}
		for (i = 0; i < numElemens; ++i) {
			if (ans[i] != correctAns[i]) {
				check = false;
				break;
			}
		}
	} else {
		check = false;
	}

	printf("%s", (check ? "pass\n" : "fail\n"));

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