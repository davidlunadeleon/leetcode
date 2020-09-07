// Source:
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Date: 06.09.2020
// Solution by: David Luna
// Runtime: 212ms
// Memory usage: 59.7 MB

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/treeUtils/treeUtils.h"

#define MAXWLEN 12 // INT_MIN = "-2147483648" has strlen of 12

// Leetcode solution starts

int *mergeTwoArrays(int *list1, int size1, int *list2, int size2,
					int *returnSize) {
	int *mergedList;
	int i, j, k;

	*returnSize = size1 + size2;
	mergedList = (int *)malloc(*returnSize * sizeof(int));
	for (i = 0, j = 0, k = 0; i < size1 && j < size2; ++k) {
		mergedList[k] = (list1[i] < list2[j] ? list1[i++] : list2[j++]);
	}
	while (i < size1) {
		mergedList[k++] = list1[i++];
	}
	while (j < size2) {
		mergedList[k++] = list2[j++];
	}

	return mergedList;
}

void makeInorderVector(struct TreeNode *node, int **list, int *lastListIndex,
					   int *listSize) {
	if (node) {
		makeInorderVector(node->left, list, lastListIndex, listSize);

		if (*lastListIndex == *listSize) {
			*listSize *= 2;
			*list = (int *)realloc(*list, *listSize * sizeof(int));
		}

		(*list)[(*lastListIndex)++] = node->val;
		makeInorderVector(node->right, list, lastListIndex, listSize);
	}
}

int *getAllElements(struct TreeNode *root1, struct TreeNode *root2,
					int *returnSize) {
	int *list1, *list2, *ans;
	int lastListIndex1, lastListIndex2, listSize1, listSize2, ansSize;

	lastListIndex1 = 0;
	listSize1 = 50;
	list1 = (int *)malloc(listSize1 * sizeof(int));
	makeInorderVector(root1, &list1, &lastListIndex1, &listSize1);

	lastListIndex2 = 0;
	listSize2 = 50;
	list2 = (int *)malloc(listSize2 * sizeof(int));
	makeInorderVector(root2, &list2, &lastListIndex2, &listSize2);

	ansSize = 0;
	ans =
		mergeTwoArrays(list1, lastListIndex1, list2, lastListIndex2, &ansSize);
	*returnSize = ansSize;

	free(list1);
	free(list2);

	return ans;
}

// Leetcode solution ends

char **makeTreeList(int numNodes) {
	char **treeList;
	int i;

	treeList = (char **)malloc(numNodes * sizeof(char *));
	for (i = 0; i < numNodes; ++i) {
		treeList[i] = (char *)malloc(MAXWLEN * sizeof(char));
		scanf("%s", treeList[i]);
	}
	return treeList;
}

void freeTreeList(char **treeList, int numNodes) {
	int i;

	for (i = 0; i < numNodes; ++i) {
		free(treeList[i]);
	}
	free(treeList);
	treeList = NULL;
}

void makeTest() {
	int numNodes1, numNodes2, numElements, i, returnSize;
	int *ans, *correctAns;
	struct TreeNode *root1, *root2;
	char **treeList1, **treeList2;
	bool check;

	treeList1 = treeList2 = NULL;
	scanf("%d %d", &numNodes1, &numNodes2);
	treeList1 = makeTreeList(numNodes1);
	treeList2 = makeTreeList(numNodes2);

	scanf("%d", &numElements);
	correctAns = (int *)malloc(numElements * sizeof(int));
	for (i = 0; i < numElements; ++i) {
		scanf("%d", &correctAns[i]);
	}

	root1 = root2 = NULL;
	root1 = makeTree(treeList1, numNodes1);
	root2 = makeTree(treeList2, numNodes2);

	ans = getAllElements(root1, root2, &returnSize);

	check = true;
	if (returnSize != numElements) {
		check = false;
	} else {
		for (i = 0; i < numElements; ++i) {
			if (ans[i] != correctAns[i]) {
				check = false;
				break;
			}
		}
	}
	printf("%s", (check ? "pass\n" : "fail\n"));

	deleteTree(root1);
	deleteTree(root2);
	freeTreeList(treeList1, numNodes1);
	freeTreeList(treeList2, numNodes2);
	free(correctAns);
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
