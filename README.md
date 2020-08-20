# leetcode

These are my solutions to some leetcode problems.

## About the contents of this repo

This repository contains solutions to the main leetcode problems and some of the challenges.
More info about the challenges can be found [here](leetcode/leetcoding_challenges/README.md)

## How to use the test cases

The solutions can be directly tested in Leetcode without aditional steps. To test with the included main program, some other steps will be required.

<details>
	<summary>Click me!</summary>

For the time being, this process will be a little bit messy until I finish making all libraries and makefiles necessary to compile each program individually.

#### 1. Compile the libraries included in /leetcode/cpp/lib/ with the `make` command

```
$ cd ./leetcode/cpp/lib/
$ make
```

The console terminal should confirm that there are no errors in the compiling process.

#### Using VSCode

2. A `.vscode` directory is located at the root of the project, it includes files to specify the compiling and debugging options to use.

-   To compile simply press `Ctrl + Shift + B`.
-   To debug press `F5`.

#### Compiling yourself

2. Compile the code of the problem you want to test.

If you are using your own code, be sure to include it after the comment that says `//Leetcode solution starts`.
Don't forget to include the `.a` file located in /leetcode/cpp/bin/ if a custom library is used.

```
$ cd ./leetcode/cpp/938-RangeSumOfBST/
$ g++ 938-RangeSumOfBST.cpp ../bin/treeUtils.a -o 938-RangeSumOfBST.bin
```

-   Use of -Wall -Wextra and -pedantic-erros flags is recommended

#### 3. Use the test cases and print the result either to the terminal or to a file

```
$ cat testCases | ./938-RangeSumOfBST.bin
```

Or

```
$ cat testCases | ./938-RangeSumOfBST.bin > results
```

</details>

## Contributing

Contributions of new test cases or code to improve testing of each problem or upgrade functionality of libraries are always welcome.
Better solutions to already solved problems are welcome too.

## List of problems

| Problem # | Problem and souce                                                                                                                                 | Difficulty | Language                                                                                                          |
| --------- | ------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ----------------------------------------------------------------------------------------------------------------- |
| 1         | [Two Sum](https://leetcode.com/problems/two-sum/)                                                                                                 | Easy       | [C++](leetcode/cpp/1-TwoSum/1-TwoSum.cpp)                                                                         |
| 2         | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)                                                                                 | Medium     | [C++](leetcode/cpp/p2/p2.cpp)                                                                                     |
| 3         | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)                   | Medium     | [C++](leetcode/cpp/3-LongestSubstringWithoutRepeatingCharacters/3-LongestSubstringWithoutRepeatingCharacters.cpp) |
| 5         | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)                                                     | Medium     | [C++](leetcode/cpp/5-LongestPalindromicSubstring/5-LongestPalindromicSubstring.cpp)                               |
| 6         | [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)                                                                             | Medium     | [C++](leetcode/cpp/6-ZigZagConversion/6-ZigZagConversion.cpp)                                                     |
| 7         | [Reverse Integer](https://leetcode.com/problems/reverse-integer/)                                                                                 | Easy       | [C++](leetcode/cpp/7-ReverseInteger/7-ReverseInteger.cpp)                                                         |
| 9         | [Palindrome Number](https://leetcode.com/problems/palindrome-number/)                                                                             | Easy       | [C++](leetcode/cpp/9-PalindromeNumber/9-PalindromeNumber.cpp)                                                     |
| 11        | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)                                                             | Medium     | [C++](leetcode/cpp/11-ContainerWithMostWater/11-ContainerWithMostWater.cpp)                                       |
| 13        | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)                                                                               | Easy       | [C++](leetcode/cpp/13-RomanToInteger/13-RomanToInteger.cpp)                                                       |
| 14        | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)                                                                     | Easy       | [C++](leetcode/cpp/14-LongestCommonPrefix/14-LongestCommonPrefix.cpp)                                             |
| 15        | [3 Sum](https://leetcode.com/problems/3sum/)                                                                                                      | Medium     | [C++](leetcode/cpp/15-3Sum/15-3Sum.cpp)                                                                           |
| 17        | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)                                     | Medium     | [C++](leetcode/cpp/17-LetterCombinationsOfAPhoneNumber/17-LetterCombinationsOfAPhoneNumber.cpp)                   |
| 18        | [4 Sum](https://leetcode.com/problems/4sum/)                                                                                                      | Medium     | [C++](leetcode/cpp/18-4Sum/18-4Sum.cpp)                                                                           |
| 19        | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)                                               | Medium     | [C++](leetcode/cpp/19-RemoveNthNodeFromEndOfList/19-RemoveNthNodeFromEndOfList.cpp)                               |
| 20        | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)                                                                             | Easy       | [C++](leetcode/cpp/20-ValidParentheses/20-ValidParentheses.cpp)                                                   |
| 21        | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)                                                                   | Easy       | [C++](leetcode/cpp/21-MergeTwoSortedLists/21-MergeTwoSortedLists.cpp)                                             |
| 26        | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)                                         | Easy       | [C++](leetcode/cpp/26-RemoveDuplicatesFromSortedArray/26-RemoveDuplicatesFromSortedArray.cpp)                     |
| 27        | [Remove Element](https://leetcode.com/problems/remove-element/)                                                                                   | Easy       | [C++](leetcode/cpp/27-RemoveElement/27-RemoveElement.cpp)                                                         |
| 34        | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | Medium     | [C++](leetcode/cpp/p34/p34.cpp)                                                                                   |
| 74        | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)                                                                           | Medium     | [C++](leetcode/cpp/74-SearchA2DMatrix/74-SearchA2DMatrix.cpp)                                                     |
| 82        | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)                                     | Medium     | [C++](leetcode/cpp/p82/p82.cpp)                                                                                   |
| 94        | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)                                                     | Medium     | [C++](leetcode/cpp/p94/p94.cpp)                                                                                   |
| 98        | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)                                                         | Medium     | [C++](leetcode/cpp/98-ValidateBinarySearchTree/98-ValidateBinarySearchTree.cpp)                                   |
| 119       | [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)                                                                        | Easy       | [C++](leetcode/cpp/p119/p119.cpp)                                                                                 |
| 125       | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)                                                                               | Easy       | [C++](leetcode/cpp/p125/p125.cpp)                                                                                 |
| 143       | [Reorder List](https://leetcode.com/problems/reorder-list/)                                                                                       | Medium     | [C++](leetcode/cpp/p143/p143.cpp)                                                                                 |
| 145       | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)                                                 | Hard       | [C++](leetcode/cpp/p145/p145.cpp)                                                                                 |
| 171       | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/)                                                             | Easy       | [C++](leetcode/cpp/p171/p171.cpp)                                                                                 |
| 206       | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)                                                                         | Easy       | [C++](cpp/../leetcode/cpp/p206/p206.cpp)                                                                          |
| 208       | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)                                                         | Medium     | [C++](leetcode/cpp/p208/p208.cpp)                                                                                 |
| 215       | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)                                                 | Medium     | [C++](leetcode/cpp/215-KthLargestElementInAnArray/215-KthLargestElementInAnArray.cpp)                             |
| 230       | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)                                                     | Medium     | [C++](leetcode/cpp/p230/p230.cpp)                                                                                 |
| 274       | [H-Index](https://leetcode.com/problems/h-index/)                                                                                                 | Medium     | [C++](leetcode/cpp/p274/p274.cpp)                                                                                 |
| 312       | [Burst Balloons](https://leetcode.com/problems/burst-balloons/)                                                                                   | Hard       | [C++](leetcode/cpp/312-BurstBalloons/312-BurstBalloons.cpp)                                                       |
| 342       | [Power of Four](https://leetcode.com/problems/power-of-four/)                                                                                     | Easy       | [C++](leetcode/cpp/p342/p342.cpp)                                                                                 |
| 409       | [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)                                                                           | Easy       | [C++](leetcode/cpp/p409/p409.cpp)                                                                                 |
| 412       | [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)                                                                                             | Easy       | [C++](leetcode/cpp/p412/p412.cpp)                                                                                 |
| 435       | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)                                                             | Medium     | [C++](leetcode/cpp/p435/p435.cpp)                                                                                 |
| 437       | [Path Sum III](https://leetcode.com/problems/path-sum-iii/)                                                                                       | Medium     | [C++](leetcode/cpp/p437/p437.cpp)                                                                                 |
| 442       | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)                                                 | Medium     | [C++](leetcode/cpp/p442/p442.cpp)                                                                                 |
| 520       | [Detect Capitals](https://leetcode.com/problems/detect-capital/)                                                                                  | Easy       | [C++](leetcode/cpp/p520/p520.cpp)                                                                                 |
| 654       | [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)                                                                         | Medium     | [C++](leetcode/cpp/654-MaximumBinaryTree/654-MaximumBinaryTree.cpp)                                               |
| 701       | [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)                                               | Medium     | [C++](leetcode/cpp/p701/p701.cpp)                                                                                 |
| 705       | [Design HashSet](https://leetcode.com/problems/design-hashset/)                                                                                   | Easy       | [C++](leetcode/cpp/p705/p705.cpp)                                                                                 |
| 763       | [Partition Labels](https://leetcode.com/problems/partition-labels/)                                                                               | Medium     | [C++](leetcode/cpp/p763/p763.cpp)                                                                                 |
| 771       | [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)                                                                             | Easy       | [C++](leetcode/cpp/p771/p771.cpp)                                                                                 |
| 814       | [Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)                                                                         | Medium     | [C++](leetcode/cpp/p814/p814.cpp)                                                                                 |
| 824       | [Goat Latin](https://leetcode.com/problems/goat-latin/)                                                                                           | Easy       | [C++](leetcode/cpp/p824/p824.cpp)                                                                                 |
| 921       | [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)                                     | Medium     | [C++](leetcode/cpp/p921/p921.cpp)                                                                                 |
| 938       | [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)                                                                               | Easy       | [C++](leetcode/cpp/938-RangeSumOfBST/938-RangeSumOfBST.cpp)                                                       |
| 950       | [Reveal Cards In Increasing Orer](https://leetcode.com/problems/reveal-cards-in-increasing-order/)                                                | Medium     | [C++](leetcode/cpp/p950/p950.cpp)                                                                                 |
| 951       | [Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/)                                                       | Medium     | [C++](leetcode/cpp/p951/p951.cpp)                                                                                 |
| 967       | [Numbers With Same Consecutive Differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)                             | Medium     | [C++](leetcode/cpp/p967/p967.cpp)                                                                                 |
| 983       | [Minumum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)                                                               | Medium     | [C++](leetcode/cpp/983-MinimumCostForTickets/983-MinimumCostForTickets.cpp)                                       |
| 987       | [Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)                             | Medium     | [C++](leetcode/cpp/p987/p987.cpp)                                                                                 |
| 994       | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)                                                                                 | Medium     | [C++](leetcode/cpp/p994/p994.cpp)                                                                                 |
| 1008      | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)       | Medium     | [C++](leetcode/cpp/p1008/p1008.cpp)                                                                               |
| 1028      | [Recover a Tree From Preorder Traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)                                   | Hard       | [C++](leetcode/cpp/1028-RecoverATreeFromPreorderTraversal/1028-RecoverATreeFromPreorderTraversal.cpp)             |
| 1038      | [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)                                   | Medium     | [C++](leetcode/cpp/1038-BinarySearchTreeToGreaterSumTree/1038-BinarySearchTreeToGreaterSumTree.cpp)               |
| 1103      | [Distribute Candies to People](https://leetcode.com/problems/distribute-candies-to-people/)                                                       | Easy       | [C++](leetcode/cpp/p1103/p1103.cpp)                                                                               |
| 1108      | [Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)                                                                 | Easy       | [C++](leetcode/cpp/p1108/p1108.cpp)                                                                               |
| 1130      | [Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)                                           | Medium     | [C++](leetcode/cpp/1130-MinimumCostTreeFromLeafValues/1130-MinimumCostTreeFromLeafValues.cpp)                     |
| 1161      | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)                                           | Medium     | [C++](leetcode/cpp/p1161/p1161.cpp)                                                                               |
| 1221      | [Split a String in Balanced Strings](https://leetcode.com/problems/split-a-string-in-balanced-strings/)                                           | Medium     | [C++](leetcode/cpp/1221-SplitAStringInBalancedStrings/1221-SplitAStringInBalancedStrings.cpp)                     |
| 1286      | [Iterator for Combination](https://leetcode.com/problems/iterator-for-combination/)                                                               | Medium     | [C++](leetcode/cpp/p1286/p1286.cpp)                                                                               |
| 1290      | [Convert Binay Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)              | Easy       | [C++](leetcode/cpp/p1290/p1290.cpp)                                                                               |
| 1295      | [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)                                 | Easy       | [C++](leetcode/cpp/p1295/p1295.cpp)                                                                               |
| 1302      | [Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/)                                                                           | Medium     | [C++](leetcode/cpp/1302-DeepestLeavesSum/1302-DeepestLeavesSum.cpp)                                               |
| 1305      | [All elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)                                 | Medium     | [C++](leetcode/cpp/p1305/p1305.cpp)                                                                               |
| 1325      | [Delete Leaves With a Given Value](https://leetcode.com/problems/delete-leaves-with-a-given-value/)                                               | Medium     | [C++](leetcode/cpp/p1325/p1325.cpp)                                                                               |
| 1329      | [Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally/)                                                           | Medium     | [C++](cpp/../leetcode/cpp/p1329/p1329.cpp)                                                                        |
| 1342      | [Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/)                           | Easy       | [C++](leetcode/cpp/p1342/p1342.cpp)                                                                               |
| 1402      | [Reducing Dishes](https://leetcode.com/problems/reducing-dishes/)                                                                                 | Hard       | [C++](leetcode/cpp/p1402/p1402.cpp)                                                                               |
| 1431      | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)                               | Easy       | [C++](leetcode/cpp/p1431/p1431.cpp)                                                                               |
| 1470      | [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)                                                                             | Easy       | [C++](leetcode/cpp/p1470/p1470.cpp)                                                                               |
| 1480      | [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)                                                                 | Easy       | [C++](leetcode/cpp/p1480/p1480.cpp)                                                                               |
| 1512      | [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)                                                                       | Easy       | [C++](leetcode/cpp/1512-NumberOfGoodPairs/1512-NumberOfGoodPairs.cpp)                                             |
| 1528      | [Shuffle String](https://leetcode.com/problems/shuffle-string/)                                                                                   | Easy       | [C++](leetcode/cpp/p1528/p1528.cpp)                                                                               |
