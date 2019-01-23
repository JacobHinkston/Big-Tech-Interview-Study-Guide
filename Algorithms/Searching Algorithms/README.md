<h1>> Searching Algorithms</h1>
<p>
When we think of searching algorithms, we generally think of binary search. Indeed, this is a very useful algorithm to study.
In binary search, we look for an element x in a sorted array by first comparing x to the midpoint of the array. If x is less than the midpoint, then we search the left half of the array. If x is greater than the midpoint, then we search the right half of the array. We then repeat this process, treating the left and right halves as subar- rays. Again, we compare x to the midpoint of this sub-array and then search either its left or right side. We repeat this process until we either find x or the sub-array has size O.
Note that although the concept is fairly simple, getting all the details right is far more difficult than you might think. As you study the code below, pay attention to the plus ones and minus ones.
</p>

<p>
Potential ways to search a data structure extend beyond binary search, and you would do best not to limit yourself to just this option. You might, for example, search for a node by leveraging a binary tree, or by using a hash table. Think beyond binary search!
</p>