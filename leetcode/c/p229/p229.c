// Source: https://leetcode.com/problems/majority-element-ii/
// Date: 22.09.2020
// Solution by: David Luna
// Runtime: 8ms
// Memory usage: 7.5 MB

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

int *majorityElement(int *nums, int numsSize, int *returnSize) {
	int *ans;
	int max1, max2, count1, count2, minTimes;

	minTimes = numsSize / 3;
	max1 = max2 = count1 = count2 = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == max1) {
			++count1;
		} else if (nums[i] == max2) {
			++count2;
		} else if (count1 == 0) {
			max1 = nums[i];
			++count1;
		} else if (count2 == 0) {
			max2 = nums[i];
			++count2;
		} else {
			--count1;
			--count2;
		}
	}

	count1 = count2 = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == max1) {
			++count1;
		} else if (nums[i] == max2) {
			++count2;
		}
	}

	if (count1 > minTimes && count2 > minTimes) {
		*returnSize = 2;
		ans = malloc(*returnSize * sizeof(int));
		ans[0] = max1;
		ans[1] = max2;
		return ans;
	}

	if (count1 <= minTimes && count2 <= minTimes) {
		*returnSize = 0;
		ans = malloc(*returnSize * sizeof(int));
		return ans;
	}

	*returnSize = 1;
	ans = malloc(*returnSize * sizeof(int));
	ans[0] = count1 > minTimes ? max1 : max2;
	return ans;
}

// Leetcode solution ends

void makeTest() {
	vector *nums, *correctAns;
	int sizeNums, sizeAns, sizeCorrectAns, i, temp;
	int *ans;
	bool check;

	nums = vector_init_empty();
	correctAns = vector_init_empty();

	scanf("%d", &sizeNums);
	for (i = 0; i < sizeNums; ++i) {
		scanf("%d", &temp);
		vector_push_back(&nums, temp);
	}
	scanf("%d", &sizeCorrectAns);
	for (i = 0; i < sizeCorrectAns; ++i) {
		scanf("%d", &temp);
		vector_push_back(&correctAns, temp);
	}

	sizeAns = 0;
	ans = majorityElement(vector_get_array(nums), vector_get_size(nums),
						  &sizeAns);

	check = true;
	if (sizeAns == sizeCorrectAns) {
		for (i = 0; i < sizeCorrectAns; ++i) {
			if (ans[i] != vector_at(correctAns, i)) {
				check = false;
				break;
			}
		}
	} else {
		check = false;
	}

	printf("%s", check ? "pass\n" : "fail\n");

	vector_destructor(correctAns);
	vector_destructor(nums);
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
