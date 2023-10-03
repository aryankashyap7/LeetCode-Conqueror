Imagine you have a list of numbers, like this: [2, 3, 2, 1, 3, 2].
​
The goal is to find how many pairs of numbers in this list are the same.
​
Here's the efficient way to do it:
​
You have a special box for each unique number (2, 3, and 1 in our example).
​
You go through the list and put each number into its respective box, and you keep count of how many times each number appears. For example:
​
In the "2" box, you put the numbers 2, 2, and 2. So, there are 3 "2"s.
In the "3" box, you put the numbers 3 and 3. So, there are 2 "3"s.
In the "1" box, you put the number 1. So, there is 1 "1".
Now, you use a simple formula to figure out how many pairs you can make from each box. The formula is (n * (n - 1)) / 2, where "n" is the number of items in the box.
​
You apply this formula to each box and add up all the pairs you can make.
​
So, for our example, you'd calculate it like this:
​
For the "2" box, you have (3 * (3 - 1)) / 2 = 3 pairs.
For the "3" box, you have (2 * (2 - 1)) / 2 = 1 pair.
For the "1" box, you have (1 * (1 - 1)) / 2 = 0 pairs.
Now, you add up all the pairs: 3 + 1 + 0 = 4.
​
So, there are 4 pairs of identical numbers in the list.