// Source: https://leetcode.com/problems/gas-station/
// Date: 23.09.2020
// Solution by: David Luna
// Runtime: 4ms
// Memory usage: 6 MB

#include <stdio.h>
#include <stdlib.h>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
	gasSize = costSize; // remove unused variable warning
	int sum, ans, temp;

	sum = ans = temp = 0;
	for (int i = 0; i < gasSize; i++) {
		sum += gas[i] - cost[i];
		temp += gas[i] - cost[i];
		if (temp < 0) {
			ans = i + 1;
			temp = 0;
		}
	}

	return sum >= 0 ? ans : -1;
}

// Leetcode solution ends

void makeTest() {
	vector *gas, *cost;
	int size, ans, correctAns, temp, i;

	gas = vector_init_empty();
	cost = vector_init_empty();

	scanf("%d", &size);
	for (i = 0; i < size; ++i) {
		scanf("%d", &temp);
		vector_push_back(&gas, temp);
	}
	for (i = 0; i < size; ++i) {
		scanf("%d", &temp);
		vector_push_back(&cost, temp);
	}
	scanf("%d", &correctAns);

	ans = canCompleteCircuit(vector_get_array(gas), vector_get_size(gas),
							 vector_get_array(cost), vector_get_size(cost));
	printf("%s", ans == correctAns ? "pass\n" : "fail\n");

	vector_destructor(gas);
	vector_destructor(cost);
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}
