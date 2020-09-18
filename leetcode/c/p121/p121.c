// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Date: 18.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6.5 MB

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

int maxProfit(int *prices, int pricesSize) {
	int ans, min;

	ans = 0;
	min = INT32_MAX;
	for (int i = 0; i < pricesSize; ++i, ++prices) {
		if (*prices < min) {
			min = *prices;
		} else if (*prices - min > ans) {
			ans = *prices - min;
		}
	}

	return ans;
}

// Leetcode solution ends

void makeTest() {
	int ans, correctAns, pricesSize, temp;
	vector *prices;

	prices = vector_init_empty();
	scanf("%d", &pricesSize);
	for (int i = 0; i < pricesSize; ++i) {
		scanf("%d", &temp);
		vector_push_back(&prices, temp);
	}

	scanf("%d", &correctAns);
	ans = maxProfit(vector_get_array(prices), vector_get_size(prices));

	printf("%s", (ans == correctAns ? "pass\n" : "fail\n"));

	vector_destructor(prices);
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}
