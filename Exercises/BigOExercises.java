class Exercises {
    public static void main(String[] args) {

    }

    /* 
     * What is the runtime of the below code?
     * Example 1
     */
    public static void foo(int[] array) {
        int sum = 0;
        int product = 1;
        for(int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        for(int i = 0; i < array.length; i++) {
            product *= array[i];
        }
        System.out.println(sum + ", " + product);
    }  

    /*
     * What is the runtime of the below code?
     * Example 2
     */
    public static void printPairs(int[] array) {
        for(int i = 0; i<array.length; i++) {
            for(int j = 0; j<array.length; j++) {
                System.out.println(array[i] + "," + array[j]);
            }
        }
    }

     /*
     * What is the runtime of the below code?
     * Example 3
     */
    public static void printUnorderedPairs(int[] array) {
        for(int i = 0; i < array.length; i++) {
            for(int j = i + 1; j < array.length; j++) {
                System.out.println(array[i] + "," + array[j]);
            }
        }
    }

    /*
     * What is the runtime of the below code?
     * Example 4
     */
    public static void printUnorderedPairs_2(int[] arrayA, int[] arrayB) {
        for(int i = 0; i < arrayA.length; i++) {
            for(int j = 0; j < arrayB.length; j++) {
                System.out.println(arrayA[i] + "," + arrayB[j]);
            }
        }
    }

    /*
     * What is the runtime of the below code?
     * Example 5
     */
    public static void printUnorderedPairs_3(int[] arrayA, int[] arrayB) {
        for(int i = 0; i < arrayA.length; i++) {
            for(int j = 0; j < arrayB.length; j++) {
                for(int k = 0; k<100000; k++) {
                    System.out.println(arrayA[i] + "," + arrayB[j]);
                }
            }
        }
    }
    /*
     * What is the runtime of the below code?
     * Example 6
     */
    public static void reverse(int[] array) {
        for(int i = 0; i<array.length; i++) {
            int other = array.length - i - 1;
            int temp = array[i];
            array[i] = array[other];
            array[other] = temp;
        }
    }

    /*
     * Which of the following are equivilent to O(n)?
     * Example 7
     * 
     * O(N + P), where P < N/2
     * O(2N)
     * O(N + log(N))
     * O(N + M)
     */

    /*
     * What is the runtime fo the below code?
     * Example 9
     */

    // int sum(Node node){
    //     if (!node){
    //         return 0;
    //     }
    //     return sum(node.left) + node.value + sum(node.right);
    // }

    /*
     * What is the runtime of the below code?
     * Example 10
     */
    public static boolean isPrime(int n){
        for(int x = 2; x * x <= n; x++){
            if(n % x == 0){
                return false;
            }
        }
        return true;
    }

    /*
     * What is the runtime of the below code?
     * Example 11
     */

    public static int factorial(int n){
        if(n < 0){
            return -1;
        } else if(n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    /*
     * What is the runtime of the below code?
     * Example 12
     */
    
    public static void permutation(String str) {
        permutation(str, "");
    }
    public static void permutation(String str, String prefix) {
        if(str.length() == 0){
            System.out.println(prefix);
        } else {
            for(int i = 0; i < str.length(); i++){
                String rem = str.substring(0, i) + str.substring(i+1);
                permutation(rem, prefix + str.charAt(i));
            }
        }
    }

     /*
     * What is the runtime of the below code?
     * Example 13
     */
    public static int fib(int n) {
        if(n <= 0) return 0;
        else if(n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }

    /*
     * What is the runtime of the below code?
     * Example 14
     */

    public static void allFib(int n) {
        for(int i = 0; i < n; i++) {
            System.out.println(i + ": " + fib(i)); // Calls the above ^.
        }
    }

    /*
     * What is the runtime of the below code?
     * Example 15
     */

    public static void allFib_2(int n) {
        int[] memo = new int[n+1];
        for(int i = 0; i < n; i++) {
            System.out.println(i + ": " + fib_2(i, memo));
        }
    }
    public static int fib_2(int n, int[] memo) {
        if(n <= 0) return 0;
        else if(n == 1) return 1;
        else if(memo[n] > 0) return memo[n];
        memo[n] = fib_2(n - 1, memo) + fib_2(n - 2, memo);
        return memo[n];
    }

    /*
     * What is the runtime of the below code?
     * Example 16
     */

    public static int powersOf2(int n){
         if(n < 1) {
             return 0;
         } else if(n == 1) {
             System.out.println(1);
             return 1;
         } else {
             int prev = powersOf2(n / 2);
             int curr = prev * 2;
             System.out.println(curr);
             return curr;
         }
     }

    /*
     *ADDITIONAL PROBLEMS
     */

    /*
     * What is the runtime of the below code?
     * Example VI.1
     */
    public static int product(int a, int b) {
        int sum = 0;
        for(int i = 0; i<b; i++){
            sum += a;
        }
        return sum;
    }

    /*
     * What is the runtime of the below code?
     * Example VI.2
     */

    public static int power(int a, int b){

        /* Much easier to understand
            int pow = 1;
            for(int i = 0; i < b && b > 0; i++) pow *= a;
            return pow;
        */
        
        if(b < 0) {
            return 0;
        } else if(b == 1){
            return 1;
        } else {
            return a * power(a, b - 1);
        }
    }

    /*
     * What is the runtime of the below code?
     * Example VI.3
     */

     public static int mod(int a, int b) {
         if( b <= 0) {
             return -1;
         }
         int div = a / b;
         return a - div * b;
     }

     /*
     * What is the runtime of the below code?
     * Example VI.4
     */

    public static int div(int a, int b){
        int count = 0;
        int sum = b;
        while( sum <= a) {
            sum += b;
            count++;
        }
        return count;
    }

     /*
     * What is the runtime of the below code?
     * Example VI.5
     */

     public static int sqrt(int n){
         return sqrt_helper(n, 1, n);
     }

     public static int sqrt_helper(int n, int min, int max){
        if(max < min) return -1;
        int guess = (min + max) / 2;
        if(guess * guess == n){ 
            return guess;
        } else if (guess * guess == n) {
            return sqrt_helper(n, guess + 1, max);
        } else {
            return sqrt_helper(n, min, guess - 1);
        }
     }

    /*
    * What is the runtime of the below code?
    * Example VI.6
    */

    public static int sqrt_2(int n){
        for(int guess = 1; guess * guess <= n; guess++){
            if(guess * guess == n){
                return guess;
            }
        }
        return -1;
    }

    /*
     * Example VI.7
     * IF a binary search tree is not balanced, how long might it take (worst case) to find an element in it?
     */

    /*
     * Example VI.8
     * You are looking for a specific value in a binary tree, but the tree is not a binary search tree. What is the time complexity of this?
     */

    /*
     * Example VI.9
     * The appendToNew method appends a value to an array by creating a new, longer array and returning this longer array. 
     * You've used the appendToNew method to create a copyArray function that repeatedly calls appendToNew. How long does this copying array take?
     * What is the runtime of the below code?
     */

    public static int[] copyArray(int[] array) {
        int[] copy = new int[0];
        for(int value : array){
            copy = appendToNew(copy, value);
        }
        return copy;
    }

    public static int[] appendToNew(int[] array, int value){
        int[] bigger = new int[array.length + 1];
        for(int i = 0; i < array.length; i++){
            bigger[i] = array[i];
        }
        bigger[bigger.length - 1] = value;
        return bigger;
    }

    /*
    * What is the runtime of the below code?
    * Example VI.10
    */

    int sumDigits(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

    /*
    * What is the runtime of the below code?
    * Example VI.11
    */

    static int numChars = 26;

    public static void printSortedStrings(int remaining){
        printSortedStrings(remaining, "");
    }

    public static void printSortedStrings(int remaining, String prefix){
        if(remaining == 0){
            if(isInOrder(prefix)){
                System.out.println(prefix);
            }

        } else {
            for(int i = 0; i < numChars; i++){
                char c = ithLetter(i);
                printSortedStrings(remaining - 1, prefix);
            }
        }
    }

    public static boolean isInOrder(String s){
        for(int i = 1; i < s.length(); i++){
            int prev = ithLetter(s.charAt(i-1));
            int curr = ithLetter(s.charAt(i));
            if(prev > curr){
                return false;
            }
        }
        return true;
    }

    public static char ithLetter(int i){
        return (char) (((int) 'a' + i));
    }
}