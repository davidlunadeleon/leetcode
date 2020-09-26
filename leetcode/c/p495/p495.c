// Source: https://leetcode.com/problems/teemo-attacking/
// Date: 26.09.2020
// Solution by: David Luna
// Runtime: 32ms
// Memory usage: 7.4 MB

#include <stdio.h>
#include <stdlib.h>

#include "../lib/vectorUtils/vectorUtils.h"

// Leetcode solution starts

int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration) {
	if (timeSeriesSize == 0) {
		return 0;
	}

	int poisonedTime = duration;
	for (timeSeries++; timeSeriesSize > 1; timeSeriesSize--, timeSeries++) {
		poisonedTime += (duration < *timeSeries - *(timeSeries - 1))
							? (duration)
							: (*timeSeries - *(timeSeries - 1));
	}
	return poisonedTime;
}

// Leetcode solution ends

void makeTest() {
	int timeSeriesSize, ans, correctAns, duration, temp;
	vector *timeSeries;

	timeSeries = vector_init_empty();

	scanf("%d", &timeSeriesSize);
	for (int i = 0; i < timeSeriesSize; ++i) {
		scanf("%d", &temp);
		vector_push_back(&timeSeries, temp);
	}
	scanf("%d", &duration);
	scanf("%d", &correctAns);

	ans = findPoisonedDuration(vector_get_array(timeSeries),
							   vector_get_size(timeSeries), duration);
	printf("%s", (ans == correctAns ? "pass\n" : "fail\n"));

	vector_destructor(timeSeries);
}

int main() {
	int numTests, i;

	scanf("%d", &numTests);
	for (i = 0; i < numTests; ++i) {
		makeTest();
	}

	return 0;
}
