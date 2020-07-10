# leetcode

These are my solutions to some leetcode problems

## How to use the test cases

Each problem includes a file with some test cases. Although these do not cover all possible cases, it should be enough to test each problem.

Just compile the `.cpp` file with and paste the contents of the `testCases` file in the terminal. Feel free to use these test cases or the main program and functions for your own solutions. New test cases are welcome :) .

If you want to get fancy, I recommend you use the following commands:

1. First, cd into the directory of the problem and compile to make a bin file with:

```
cd leectode/cpp/1-TwoSum
g++ 1-TwoSum.cpp -o 1-TwoSum.bin
```

2. Generate a results file or print the results of the tests. If you want to just print in the console, ignore the results part.

```
cat testCases | ./1-TwoSum.bin > results
```

- Note: leetcode uses `clang` 9 to compile the code, with the latest C++ 17 standard.

## List of problems

| Problem and souce                                                                                                               | Problem # | Difficulty | Language                                                                                                          |
| ------------------------------------------------------------------------------------------------------------------------------- | --------- | ---------- | ----------------------------------------------------------------------------------------------------------------- |
| [Two Sum](https://leetcode.com/problems/two-sum/)                                                                               | 1         | Easy       | [C++](leetcode/cpp/1-TwoSum/1-TwoSum.cpp)                                                                         |
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)                                                               | 2         | Medium     | [C++](leetcode/cpp/2-AddTwoNumbers/2-AddTwoNumbers.cpp)                                                           |
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | 3         | Medium     | [C++](leetcode/cpp/3-LongestSubstringWithoutRepeatingCharacters/3-LongestSubstringWithoutRepeatingCharacters.cpp) |
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)                                   | 5         | Medium     | [C++](leetcode/cpp/5-LongestPalindromicSubstring/5-LongestPalindromicSubstring.cpp)                               |
| [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)                                                           | 6         | Medium     | [C++](leetcode/cpp/6-ZigZagConversion/6-ZigZagConversion.cpp)                                                     |
| [Reverse Integer](https://leetcode.com/problems/reverse-integer/)                                                               | 7         | Easy       | [C++](leetcode/cpp/7-ReverseInteger/7-ReverseInteger.cpp)                                                         |
| [Palindrome Number](https://leetcode.com/problems/palindrome-number/submissions/)                                               | 9         | Easy       | [C++](leetcode/cpp/9-PalindromeNumber/9-PalindromeNumber.cpp)                                                     |
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/submissions/)                               | 11        | Medium     | [C++](leetcode/cpp/11-ContainerWithMostWater/11-ContainerWithMostWater.cpp)                                       |
| [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)                                                             | 13        | Easy       | [C++](leetcode/cpp/13-RomanToInteger/13-RomanToInteger.cpp)                                                       |
| [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)                                                   | 14        | Easy       | [C++](leetcode/cpp/14-LongestCommonPrefix/14-LongestCommonPrefix.cpp)                                             |
| [3 Sum](https://leetcode.com/problems/3sum/)                                                                                    | 15        | Medium     | [C++](leetcode/cpp/15-3Sum/15-3Sum.cpp)                                                                           |
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)                   | 17        | Medium     | [C++](leetcode/cpp/17-LetterCombinationsOfAPhoneNumber/17-LetterCombinationsOfAPhoneNumber.cpp)                   |
| [4 Sum](https://leetcode.com/problems/4sum/)                                                                                    | 18        | Medium     | [C++](leetcode/cpp/18-4Sum/18-4Sum.cpp)                                                                           |
| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)                             | 19        | Medium     | [C++](leetcode/cpp/19-RemoveNthNodeFromEndOfList/19-RemoveNthNodeFromEndOfList.cpp)                               |
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)                                                           | 20        | Easy       | [C++](leetcode/cpp/20-ValidParentheses/20-ValidParentheses.cpp)                                                   |
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)                                                 | 21        | Easy       | [C++](leetcode/cpp/21-MergeTwoSortedLists/21-MergeTwoSortedLists.cpp)                                             |
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)                       | 26        | Easy       | [C++](leetcode/cpp/26-RemoveDuplicatesFromSortedArray/26-RemoveDuplicatesFromSortedArray.cpp)                     |
| [Remove Element](https://leetcode.com/problems/remove-element/)                                                                 | 27        | Easy       | [C++](leetcode/cpp/27-RemoveElement/27-RemoveElement.cpp)                                                         |
| [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)                                                         | 74        | Medium     | [C++](leetcode/cpp/74-SearchA2DMatrix/74-SearchA2DMatrix.cpp)                                                     |
| [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)                                       | 98        | Medium     | [C++](leetcode/cpp/98-ValidateBinarySearchTree/98-ValidateBinarySearchTree.cpp)                                   |
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/)                   | 215       | Medium     | [C++](leetcode/cpp/215-KthLargestElementInAnArray/215-KthLargestElementInAnArray.cpp)                             |
| [Burst Balloons](https://leetcode.com/problems/burst-balloons/submissions/)                                                     | 312       | Hard       | [C++](leetcode/cpp/312-BurstBalloons/312-BurstBalloons.cpp)                                                       |
| [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)                                                             | 938       | Easy       | [C++](leetcode/cpp/938-RangeSumOfBST/938-RangeSumOfBST.cpp)                                                       |
| [Minumum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)                                             | 983       | Medium     | [C++](leetcode/cpp/983-MinimumCostForTickets/983-MinimumCostForTickets.cpp)                                       |
| [Recover a Tree From Preorder Traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)                 | 1028      | Hard       | [C++](leetcode/cpp/1028-RecoverATreeFromPreorderTraversal/1028-RecoverATreeFromPreorderTraversal.cpp)             |
| [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)                 | 1038      | Medium     | [C++](leetcode/cpp/1038-BinarySearchTreeToGreaterSumTree/1038-BinarySearchTreeToGreaterSumTree.cpp)               |
| [Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)                         | 1130      | Medium     | [C++](leetcode/cpp/1130-MinimumCostTreeFromLeafValues/1130-MinimumCostTreeFromLeafValues.cpp)                     |
| [Split a String in Balanced Strings](https://leetcode.com/problems/split-a-string-in-balanced-strings/)                         | 1221      | Medium     | [C++](leetcode/cpp/1221-SplitAStringInBalancedStrings/1221-SplitAStringInBalancedStrings.cpp)                     |
