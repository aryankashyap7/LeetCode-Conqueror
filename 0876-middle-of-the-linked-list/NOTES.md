1. While slow moves one step forward, fast moves two steps forward.
2. Finally, when fast reaches the end, slow happens to be in the middle of the linked list.
3. For example, head = [1, 2, 3, 4, 5], I bolded the slow and fast in the list.
* step 0: slow: [1, 2, 3, 4, 5], fast: [1, 2, 3, 4, 5]
* step 1: slow: [1, 2, 3, 4, 5], fast: [1, 2, 3, 4, 5]
* step 2: slow: [1, 2, 3, 4, 5], fast: [1, 2, 3, 4, 5]
* end because fast cannot move forward anymore and return [3, 4, 5]