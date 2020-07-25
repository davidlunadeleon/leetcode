# leetcode

These are my solutions to some leetcode problems.

## How to use the test cases

The solutions can be directly tested in Leetcode without aditional steps. To test with the included main program, some other steps will be required.

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

## Contributing

Contributions of new test cases or code to receive the input of the test cases are always welcome :) .

## List of problems

| Problem and souce                                                                                                                                 | Problem # | Difficulty | Language                                                                                                          |
| ------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ---------- | ----------------------------------------------------------------------------------------------------------------- |
| [Two Sum](https://leetcode.com/problems/two-sum/)                                                                                                 | 1         | Easy       | [C++](leetcode/cpp/1-TwoSum/1-TwoSum.cpp)                                                                         |
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)                                                                                 | 2         | Medium     | [C++](leetcode/cpp/2-AddTwoNumbers/2-AddTwoNumbers.cpp)                                                           |
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)                   | 3         | Medium     | [C++](leetcode/cpp/3-LongestSubstringWithoutRepeatingCharacters/3-LongestSubstringWithoutRepeatingCharacters.cpp) |
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)                                                     | 5         | Medium     | [C++](leetcode/cpp/5-LongestPalindromicSubstring/5-LongestPalindromicSubstring.cpp)                               |
| [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)                                                                             | 6         | Medium     | [C++](leetcode/cpp/6-ZigZagConversion/6-ZigZagConversion.cpp)                                                     |
| [Reverse Integer](https://leetcode.com/problems/reverse-integer/)                                                                                 | 7         | Easy       | [C++](leetcode/cpp/7-ReverseInteger/7-ReverseInteger.cpp)                                                         |
| [Palindrome Number](https://leetcode.com/problems/palindrome-number/)                                                                             | 9         | Easy       | [C++](leetcode/cpp/9-PalindromeNumber/9-PalindromeNumber.cpp)                                                     |
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)                                                             | 11        | Medium     | [C++](leetcode/cpp/11-ContainerWithMostWater/11-ContainerWithMostWater.cpp)                                       |
| [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)                                                                               | 13        | Easy       | [C++](leetcode/cpp/13-RomanToInteger/13-RomanToInteger.cpp)                                                       |
| [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)                                                                     | 14        | Easy       | [C++](leetcode/cpp/14-LongestCommonPrefix/14-LongestCommonPrefix.cpp)                                             |
| [3 Sum](https://leetcode.com/problems/3sum/)                                                                                                      | 15        | Medium     | [C++](leetcode/cpp/15-3Sum/15-3Sum.cpp)                                                                           |
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)                                     | 17        | Medium     | [C++](leetcode/cpp/17-LetterCombinationsOfAPhoneNumber/17-LetterCombinationsOfAPhoneNumber.cpp)                   |
| [4 Sum](https://leetcode.com/problems/4sum/)                                                                                                      | 18        | Medium     | [C++](leetcode/cpp/18-4Sum/18-4Sum.cpp)                                                                           |
| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)                                               | 19        | Medium     | [C++](leetcode/cpp/19-RemoveNthNodeFromEndOfList/19-RemoveNthNodeFromEndOfList.cpp)                               |
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)                                                                             | 20        | Easy       | [C++](leetcode/cpp/20-ValidParentheses/20-ValidParentheses.cpp)                                                   |
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)                                                                   | 21        | Easy       | [C++](leetcode/cpp/21-MergeTwoSortedLists/21-MergeTwoSortedLists.cpp)                                             |
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)                                         | 26        | Easy       | [C++](leetcode/cpp/26-RemoveDuplicatesFromSortedArray/26-RemoveDuplicatesFromSortedArray.cpp)                     |
| [Remove Element](https://leetcode.com/problems/remove-element/)                                                                                   | 27        | Easy       | [C++](leetcode/cpp/27-RemoveElement/27-RemoveElement.cpp)                                                         |
| [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | 34        | Medium     | [C++](leetcode/cpp/p34/p34.cpp)                                                                                   |
| [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)                                                                           | 74        | Medium     | [C++](leetcode/cpp/74-SearchA2DMatrix/74-SearchA2DMatrix.cpp)                                                     |
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)                                                     | 94        | Medium     | [C++](leetcode/cpp/p94/p94.cpp)                                                                                   |
| [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)                                                         | 98        | Medium     | [C++](leetcode/cpp/98-ValidateBinarySearchTree/98-ValidateBinarySearchTree.cpp)                                   |
| [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)                                                 | 145       | Hard       | [C++](leetcode/cpp/p145/p145.cpp)                                                                                 |
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)                                                 | 215       | Medium     | [C++](leetcode/cpp/215-KthLargestElementInAnArray/215-KthLargestElementInAnArray.cpp)                             |
| [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)                                                     | 230       | Medium     | [C++](leetcode/cpp/p230/p230.cpp)                                                                                 |
| [Burst Balloons](https://leetcode.com/problems/burst-balloons/)                                                                                   | 312       | Hard       | [C++](leetcode/cpp/312-BurstBalloons/312-BurstBalloons.cpp)                                                       |
| [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)                                                                                             | 412       | Easy       | [C++](leetcode/cpp/p412/p412.cpp)                                                                                 |
| [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)                                                                         | 654       | Medium     | [C++](leetcode/cpp/654-MaximumBinaryTree/654-MaximumBinaryTree.cpp)                                               |
| [Partition Labels](https://leetcode.com/problems/partition-labels/)                                                                               | 763       | Medium     | [C++](leetcode/cpp/p763/p763.cpp)                                                                                 |
| [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)                                     | 921       | Medium     | [C++](leetcode/cpp/p921/p921.cpp)                                                                                 |
| [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)                                                                               | 938       | Easy       | [C++](leetcode/cpp/938-RangeSumOfBST/938-RangeSumOfBST.cpp)                                                       |
| [Minumum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)                                                               | 983       | Medium     | [C++](leetcode/cpp/983-MinimumCostForTickets/983-MinimumCostForTickets.cpp)                                       |
| [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)       | 1008      | Medium     | [C++](leetcode/cpp/p1008/p1008.cpp)                                                                               |
| [Recover a Tree From Preorder Traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)                                   | 1028      | Hard       | [C++](leetcode/cpp/1028-RecoverATreeFromPreorderTraversal/1028-RecoverATreeFromPreorderTraversal.cpp)             |
| [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)                                   | 1038      | Medium     | [C++](leetcode/cpp/1038-BinarySearchTreeToGreaterSumTree/1038-BinarySearchTreeToGreaterSumTree.cpp)               |
| [Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)                                                                 | 1108      | Easy       | [C++](leetcode/cpp/p1108/p1108.cpp)                                                                               |
| [Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)                                           | 1130      | Medium     | [C++](leetcode/cpp/1130-MinimumCostTreeFromLeafValues/1130-MinimumCostTreeFromLeafValues.cpp)                     |
| [Split a String in Balanced Strings](https://leetcode.com/problems/split-a-string-in-balanced-strings/)                                           | 1221      | Medium     | [C++](leetcode/cpp/1221-SplitAStringInBalancedStrings/1221-SplitAStringInBalancedStrings.cpp)                     |
| [Convert Binay Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)              | 1290      | Easy       | [C++](leetcode/cpp/p1290/p1290.cpp)                                                                               |
| [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)                                 | 1295      | Easy       | [C++](leetcode/cpp/p1295/p1295.cpp)                                                                               |
| [Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/)                                                                           | 1302      | Medium     | [C++](leetcode/cpp/1302-DeepestLeavesSum/1302-DeepestLeavesSum.cpp)                                               |
| [All elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)                                 | 1305      | Medium     | [C++](leetcode/cpp/p1305/p1305.cpp)                                                                               |
| [Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally/)                                                           | 1329      | Medium     | [C++](cpp/../leetcode/cpp/p1329/p1329.cpp)                                                                        |
| [Reducing Dishes](https://leetcode.com/problems/reducing-dishes/)                                                                                 | 1402      | Hard       | [C++](leetcode/cpp/p1402/p1402.cpp)                                                                               |
| [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)                               | 1431      | Easy       | [C++](leetcode/cpp/p1431/p1431.cpp)                                                                               |
| [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)                                                                             | 1470      | Easy       | [C++](leetcode/cpp/p1470/p1470.cpp)                                                                               |
| [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)                                                                 | 1480      | Easy       | [C++](leetcode/cpp/p1480/p1480.cpp)                                                                               |
| [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)                                                                       | 1512      | Easy       | [C++](leetcode/cpp/1512-NumberOfGoodPairs/1512-NumberOfGoodPairs.cpp)                                             |
