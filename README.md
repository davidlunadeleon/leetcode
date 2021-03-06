# leetcode

These are my solutions to some leetcode problems.

## About the contents of this repo

This repository contains solutions to some leetcode problems.

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

| Problem # | Problem and source                                                                                                                                | Difficulty | Language                                                                                                          |
| --------- | ------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- | ----------------------------------------------------------------------------------------------------------------- |
| 1         | [Two Sum](https://leetcode.com/problems/two-sum/)                                                                                                 | Easy       | [C++](leetcode/cpp/1-TwoSum/1-TwoSum.cpp)                                                                         |
| 2         | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)                                                                                 | Medium     | [C++](leetcode/cpp/p2/p2.cpp) / [C](leetcode/c/p2/p2.c)                                                           |
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
| 35        | [Search Insert Position](https://leetcode.com/problems/search-insert-position/)                                                                   | Easy       | [C++](leetcode/cpp/p35/p35.cpp)                                                                                   |
| 41        | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)                                                                   | Hard       | [C++](leetcode/cpp/p41/p41.cpp)                                                                                   |
| 57        | [Insert Interval](https://leetcode.com/problems/insert-interval/)                                                                                 | Hard       | [C++](leetcode/cpp/p57/p57.cpp)                                                                                   |
| 58        | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/)                                                                         | Easy       | [C++](leetcode/cpp/p58/p58.cpp) / [C](leetcode/c/p58/p58.c)                                                       |
| 74        | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)                                                                           | Medium     | [C++](leetcode/cpp/74-SearchA2DMatrix/74-SearchA2DMatrix.cpp)                                                     |
| 82        | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)                                     | Medium     | [C++](leetcode/cpp/p82/p82.cpp)                                                                                   |
| 94        | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)                                                     | Medium     | [C++](leetcode/cpp/p94/p94.cpp)                                                                                   |
| 98        | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)                                                         | Medium     | [C++](leetcode/cpp/98-ValidateBinarySearchTree/98-ValidateBinarySearchTree.cpp)                                   |
| 119       | [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)                                                                        | Easy       | [C++](leetcode/cpp/p119/p119.cpp)                                                                                 |
| 121       | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)                                                 | Easy       | [C++](leetcode/cpp/p121/p121.cpp) / [C](leetcode/c/p121/p121.c)                                                   |
| 125       | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)                                                                               | Easy       | [C++](leetcode/cpp/p125/p125.cpp)                                                                                 |
| 134       | [Gas Station](https://leetcode.com/problems/gas-station/)                                                                                         | Medium     | [C++](leetcode/cpp/p134/p134.cpp) / [C](leetcode/c/p134/p134.c)                                                   |
| 139       | [Word Break](https://leetcode.com/problems/word-break/)                                                                                           | Medium     | [C++](leetcode/cpp/p139/p139.cpp)                                                                                 |
| 143       | [Reorder List](https://leetcode.com/problems/reorder-list/)                                                                                       | Medium     | [C++](leetcode/cpp/p143/p143.cpp)                                                                                 |
| 145       | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)                                                 | Hard       | [C++](leetcode/cpp/p145/p145.cpp)                                                                                 |
| 152       | [Maximum Produc Subarray](https://leetcode.com/problems/maximum-product-subarray/)                                                                | Medium     | [C++](leetcode/cpp/p152/p152.cpp)                                                                                 |
| 165       | [Compare Version Number](https://leetcode.com/problems/compare-version-numbers/)                                                                  | Medium     | [C++](leetcode/cpp/p165/p165.cpp)                                                                                 |
| 171       | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/)                                                             | Easy       | [C++](leetcode/cpp/p171/p171.cpp)                                                                                 |
| 179       | [Largest Number](https://leetcode.com/problems/largest-number/)                                                                                   | Medium     | [C++](leetcode/cpp/p179/p179.cpp)                                                                                 |
| 198       | [House Robber](https://leetcode.com/problems/house-robber/)                                                                                       | Easy       | [C++](leetcode/cpp/p198/p198.cpp)                                                                                 |
| 206       | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)                                                                         | Easy       | [C++](leetcode/cpp/p206/p206.cpp)                                                                                 |
| 208       | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)                                                         | Medium     | [C++](leetcode/cpp/p208/p208.cpp)                                                                                 |
| 215       | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)                                                 | Medium     | [C++](leetcode/cpp/215-KthLargestElementInAnArray/215-KthLargestElementInAnArray.cpp)                             |
| 216       | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)                                                                         | Medium     | [C++](leetcode/cpp/p216/p216.cpp)                                                                                 |
| 220       | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/)                                                                   | Medium     | [C++](leetcode/cpp/p220/p220.cpp)                                                                                 |
| 229       | [Majority Element II](https://leetcode.com/problems/majority-element-ii/)                                                                         | Medium     | [C++](leetcode/cpp/p229/p229.cpp) / [C](leetcode/c/p299/p299.c)                                                   |
| 230       | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)                                                     | Medium     | [C++](leetcode/cpp/p230/p230.cpp)                                                                                 |
| 274       | [H-Index](https://leetcode.com/problems/h-index/)                                                                                                 | Medium     | [C++](leetcode/cpp/p274/p274.cpp)                                                                                 |
| 290       | [Word Pattern](https://leetcode.com/problems/word-pattern/)                                                                                       | Easy       | [C++](leetcode/cpp/p290/p290.cpp)                                                                                 |
| 299       | [Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/)                                                                                   | Easy       | [C++](leetcode/cpp/p299/p299.cpp) / [C](leetcode/c/p299/p299.c)                                                   |
| 312       | [Burst Balloons](https://leetcode.com/problems/burst-balloons/)                                                                                   | Hard       | [C++](leetcode/cpp/312-BurstBalloons/312-BurstBalloons.cpp)                                                       |
| 342       | [Power of Four](https://leetcode.com/problems/power-of-four/)                                                                                     | Easy       | [C++](leetcode/cpp/p342/p342.cpp)                                                                                 |
| 389       | [Find the Difference](https://leetcode.com/problems/find-the-difference/)                                                                         | Easy       | [C++](leetcode/cpp/p389/p389.cpp) / [C](leetcode/c/p389/p389.c)                                                   |
| 399       | [Evaluate Division](https://leetcode.com/problems/evaluate-division/)                                                                             | Medium     | [C++](leetcode/cpp/p399/p399.cpp)                                                                                 |
| 404       | [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)                                                                           | Easy       | [C++](leetcode/cpp/p404/p404.cpp)                                                                                 |
| 409       | [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)                                                                           | Easy       | [C++](leetcode/cpp/p409/p409.cpp)                                                                                 |
| 412       | [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)                                                                                             | Easy       | [C++](leetcode/cpp/p412/p412.cpp) / [C](leetcode/c/p412/p412.c)                                                   |
| 414       | [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)                                                                       | Easy       | [C++](leetcode/cpp/p414/p414.cpp)                                                                                 |
| 435       | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)                                                             | Medium     | [C++](leetcode/cpp/p435/p435.cpp)                                                                                 |
| 436       | [Find Right Interval](https://leetcode.com/problems/find-right-interval/)                                                                         | Medium     | [C++](leetcode/cpp/p436/p436.cpp)                                                                                 |
| 437       | [Path Sum III](https://leetcode.com/problems/path-sum-iii/)                                                                                       | Medium     | [C++](leetcode/cpp/p437/p437.cpp)                                                                                 |
| 442       | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)                                                 | Medium     | [C++](leetcode/cpp/p442/p442.cpp)                                                                                 |
| 450       | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)                                                                       | Medium     | [C++](leetcode/cpp/p450/p450.cpp)                                                                                 |
| 459       | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/)                                                           | Easy       | [C++](leetcode/cpp/p459/p459.cpp)                                                                                 |
| 470       | [Implement Rand10() Using Rand7()](https://leetcode.com/problems/implement-rand10-using-rand7/)                                                   | Medium     | [C++](leetcode/cpp/p470/p470.cpp)                                                                                 |
| 495       | [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/)                                                                                 | Medium     | [C++](leetcode/cpp/p495/p495.cpp) / [C](leetcode/c/p495/p495.c)                                                   |
| 497       | [Random Point in Non-overlapping Rectangles](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/)                           | Medium     | [C++](leetcode/cpp/p497/p497.cpp)                                                                                 |
| 520       | [Detect Capitals](https://leetcode.com/problems/detect-capital/)                                                                                  | Easy       | [C++](leetcode/cpp/p520/p520.cpp)                                                                                 |
| 654       | [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)                                                                         | Medium     | [C++](leetcode/cpp/654-MaximumBinaryTree/654-MaximumBinaryTree.cpp)                                               |
| 701       | [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)                                               | Medium     | [C++](leetcode/cpp/p701/p701.cpp)                                                                                 |
| 705       | [Design HashSet](https://leetcode.com/problems/design-hashset/)                                                                                   | Easy       | [C++](leetcode/cpp/p705/p705.cpp)                                                                                 |
| 713       | [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)                                                       | Medium     | [C++](leetcode/cpp/p713/p713.cpp)                                                                                 |
| 763       | [Partition Labels](https://leetcode.com/problems/partition-labels/)                                                                               | Medium     | [C++](leetcode/cpp/p763/p763.cpp) / [C](leetcode/c/p763/p763.c)                                                   |
| 771       | [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)                                                                             | Easy       | [C++](leetcode/cpp/p771/p771.cpp)                                                                                 |
| 814       | [Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)                                                                         | Medium     | [C++](leetcode/cpp/p814/p814.cpp)                                                                                 |
| 824       | [Goat Latin](https://leetcode.com/problems/goat-latin/)                                                                                           | Easy       | [C++](leetcode/cpp/p824/p824.cpp)                                                                                 |
| 835       | [Image Overlap](https://leetcode.com/problems/image-overlap/)                                                                                     | Medium     | [C++](leetcode/cpp/p835/p835.cpp)                                                                                 |
| 905       | [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)                                                                       | Easy       | [C++](leetcode/cpp/p905/p905.cpp)                                                                                 |
| 921       | [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)                                     | Medium     | [C++](leetcode/cpp/p921/p921.cpp)                                                                                 |
| 933       | [Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/)                                                                   | Easy       | [C++](leetcode/cpp/p933/p933.cpp)                                                                                 |
| 938       | [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)                                                                               | Easy       | [C++](leetcode/cpp/938-RangeSumOfBST/938-RangeSumOfBST.cpp)                                                       |
| 949       | [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/)                                                     | Easy       | [C++](leetcode/cpp/p949/p949.cpp)                                                                                 |
| 950       | [Reveal Cards In Increasing Orer](https://leetcode.com/problems/reveal-cards-in-increasing-order/)                                                | Medium     | [C++](leetcode/cpp/p950/p950.cpp)                                                                                 |
| 951       | [Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/)                                                       | Medium     | [C++](leetcode/cpp/p951/p951.cpp)                                                                                 |
| 967       | [Numbers With Same Consecutive Differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)                             | Medium     | [C++](leetcode/cpp/p967/p967.cpp)                                                                                 |
| 983       | [Minumum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)                                                               | Medium     | [C++](leetcode/cpp/983-MinimumCostForTickets/983-MinimumCostForTickets.cpp)                                       |
| 987       | [Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)                             | Medium     | [C++](leetcode/cpp/p987/p987.cpp)                                                                                 |
| 994       | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)                                                                                 | Medium     | [C++](leetcode/cpp/p994/p994.cpp)                                                                                 |
| 1008      | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)       | Medium     | [C++](leetcode/cpp/p1008/p1008.cpp)                                                                               |
| 1022      | [Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)                                           | Easy       | [C++](leetcode/cpp/p1022/p1022.cpp)                                                                               |
| 1028      | [Recover a Tree From Preorder Traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)                                   | Hard       | [C++](leetcode/cpp/1028-RecoverATreeFromPreorderTraversal/1028-RecoverATreeFromPreorderTraversal.cpp)             |
| 1038      | [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)                                   | Medium     | [C++](leetcode/cpp/1038-BinarySearchTreeToGreaterSumTree/1038-BinarySearchTreeToGreaterSumTree.cpp)               |
| 1041      | [Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/)                                                                 | Medium     | [C++](leetcode/cpp/p1041/p1041.cpp)                                                                               |
| 1094      | [Car Pooling](https://leetcode.com/problems/car-pooling/)                                                                                         | Medium     | [C++](leetcode/cpp/p1094/p1094.cpp)                                                                               |
| 1103      | [Distribute Candies to People](https://leetcode.com/problems/distribute-candies-to-people/)                                                       | Easy       | [C++](leetcode/cpp/p1103/p1103.cpp)                                                                               |
| 1108      | [Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)                                                                 | Easy       | [C++](leetcode/cpp/p1108/p1108.cpp)                                                                               |
| 1130      | [Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)                                           | Medium     | [C++](leetcode/cpp/1130-MinimumCostTreeFromLeafValues/1130-MinimumCostTreeFromLeafValues.cpp)                     |
| 1161      | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)                                           | Medium     | [C++](leetcode/cpp/p1161/p1161.cpp)                                                                               |
| 1221      | [Split a String in Balanced Strings](https://leetcode.com/problems/split-a-string-in-balanced-strings/)                                           | Medium     | [C++](leetcode/cpp/1221-SplitAStringInBalancedStrings/1221-SplitAStringInBalancedStrings.cpp)                     |
| 1281      | [Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)       | Easy       | [C++](leetcode/cpp/p1281/p1281.cpp)                                                                               |
| 1286      | [Iterator for Combination](https://leetcode.com/problems/iterator-for-combination/)                                                               | Medium     | [C++](leetcode/cpp/p1286/p1286.cpp)                                                                               |
| 1290      | [Convert Binay Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)              | Easy       | [C++](leetcode/cpp/p1290/p1290.cpp)                                                                               |
| 1291      | [Sequential Digits](https://leetcode.com/problems/sequential-digits/)                                                                             | Medium     | [C++](leetcode/cpp/p1291/p1291.cpp)                                                                               |
| 1295      | [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)                                 | Easy       | [C++](leetcode/cpp/p1295/p1295.cpp)                                                                               |
| 1302      | [Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/)                                                                           | Medium     | [C++](leetcode/cpp/1302-DeepestLeavesSum/1302-DeepestLeavesSum.cpp)                                               |
| 1305      | [All elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)                                 | Medium     | [C++](leetcode/cpp/p1305/p1305.cpp) / [C](leetcode/c/p1305/p1305.c)                                               |
| 1325      | [Delete Leaves With a Given Value](https://leetcode.com/problems/delete-leaves-with-a-given-value/)                                               | Medium     | [C++](leetcode/cpp/p1325/p1325.cpp)                                                                               |
| 1329      | [Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally/)                                                           | Medium     | [C++](leetcode/cpp/p1329/p1329.cpp)                                                                               |
| 1342      | [Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/)                           | Easy       | [C++](leetcode/cpp/p1342/p1342.cpp)                                                                               |
| 1365      | [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)       | Easy       | [C++](leetcode/cpp/p1365/p1365.cpp)                                                                               |
| 1402      | [Reducing Dishes](https://leetcode.com/problems/reducing-dishes/)                                                                                 | Hard       | [C++](leetcode/cpp/p1402/p1402.cpp)                                                                               |
| 1431      | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)                               | Easy       | [C++](leetcode/cpp/p1431/p1431.cpp)                                                                               |
| 1470      | [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)                                                                             | Easy       | [C++](leetcode/cpp/p1470/p1470.cpp)                                                                               |
| 1480      | [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)                                                                 | Easy       | [C++](leetcode/cpp/p1480/p1480.cpp)                                                                               |
| 1512      | [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)                                                                       | Easy       | [C++](leetcode/cpp/1512-NumberOfGoodPairs/1512-NumberOfGoodPairs.cpp)                                             |
| 1528      | [Shuffle String](https://leetcode.com/problems/shuffle-string/)                                                                                   | Easy       | [C++](leetcode/cpp/p1528/p1528.cpp)                                                                               |
