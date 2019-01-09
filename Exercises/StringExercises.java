import java.util.Arrays;

class StringExcercises {
    public static void main(String[] args) {
        
    }

    /*
     * Interview Question 1.1
     * Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures.
     */

    public static boolean isUniqueChars(String str){
        /*
         * The easiest solution (Although not performant) is to compare each in O(n^2).
         * This is without the use of any extra Data Structure.
         * 
            for(int i = 0; i < str.length(); i++){
                for(int j = i+1; j < str.length(); j++){
                    if(str.charAt(i) == str.charAt(j)) return false;
                }
            }
        */

        /*
         * This is the most performant solution to this problem, running in O(n).
         * The theory behind my solution is to utilize the theory behind hashtables in attempts to store a point of truth for each value
         * in the string and wether it exists. 
         */
        boolean[] char_set = new boolean[26]; //Creating a 'Hashtable' of sorts.
        //Luckily, ASCII a-z is 97-122 so if we do 97, 98 ... 122 % 26 there are no collisions in our table that are untrue. 

        for(int i = 0; i < str.length(); i++){
            int val = (String.valueOf(str.charAt(i)).toLowerCase()).charAt(0);  //Will yeild the lowercase ASCII value of the character in a janky fashion lmao.
            if(char_set[val%26]) return false;
            else char_set[val%26] = true;
        }
        return true;
    }

    /*
     * Interview Question 1.2
     * Given two strings, write a method to decide if one is a permutation of the other.
     * 
     * We can assume that it is NOT case sensitive. 'God' is a permutation of 'dog'.
     */

    public static boolean checkPermutation(String a, String b){
        if(a.length() != b.length()) return false; //If two strings are permuations, then we can make the absolute that they will be the same length with our assumption above ^.
        /*
         * Solution #1: Sort the strings and compare them at the end.
         * Using some java utilties like Arrays we can sort the Strings as char[]s and then compare them at the end.
         * 

            char[] aChar = a.toCharArray();
            char[] bChar = b.toCharArray();
            java.util.Arrays.sort(aChar);
            java.util.Arrays.sort(bChar);
            return(aChar.equals(bChar));
        */

         /*
         * Solution #2: Check if two strings have identical character counts.
         * Idea is the same as the isUniqueCharacter(), Im going to make a hashmap of counts to balance the total number of possible maps, ultimately determining wether a set of string are permutations or not.
         */

        int[] counts = new int[26];
        for(int i = 0; i < a.length(); i++){
            int valA = (String.valueOf(a.charAt(i)).toLowerCase()).charAt(0);
            int valB = (String.valueOf(b.charAt(i)).toLowerCase()).charAt(0);
            counts[valA%26]++;
            counts[valB%26]--;
        }
        for(int i = 0; i < 26; i++){
            if(counts[i] != 0) return false;
        }
        return true;
    }

    /*
     * Interview Question 1.3
     * Write a method to replace all spaces in a string with '%20'. 
     * You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
     * Note: If implementing in Java, please use a character array so that you can perform this operation in place.
     */

    public static String replaceSpaces(char[] str, int trueLength){ // Pretty much the single most useless function of all time because of javas 'immutable' strings.
        int spaces = 0;
        for(int i = 0; i < trueLength; i++){
            if(str[i] == ' ') spaces++;
        }
        int index = trueLength + spaces*2;
        if(str.length != index) return new String(str);
        System.out.println(str.length);
        for(int i = trueLength - 1; i >= 0; i--){
            if(str[i] == ' '){
                str[index - 1] = '0';
                str[index - 2] = '2';
                str[index - 3] = '%';
                index -= 3;
            } else {
                str[index - 1] = str[i];
                index--;
            }
        }
        return new String(str);

    }

    /*
     * Interview Question 1.4
     * Palindrone permutation: Given a string, write a function to check if it is a permutation of a palin-drone.
     * A palindrone is a word or phrase that is the same forwards and backwards. A permutation is a rearrangment of letters.
     * The palindrone does not need to be limited to just dictationary words.
     */

    public static boolean palindronePermutation(String str){
        
        /*
         * Solution #1:
         * In my mind, we should first understand what this function does.
         * This function is supposed to take a string, and return if it is a permutation of a palindrone. 
         * We have to work backwards to get a palindrone, and then compare it to the original string to see if it is a permutation.
         */

        /*
         * First, lets figure out if its a palindrone.
         * Im thinking that, a palindrone, has to have an even amount of leters in order to be "symetrical" (Which is what a palindrone is).
         * With this in mind, we can utilize two things here: A hashmap and a 
         * If the string we have is a palindrone, then the fact that it is a permutation is irrelivant.
         */
        boolean[] charMap = new boolean[26];
        int asciiSum = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) != ' ') {
                int val = (String.valueOf(str.charAt(i)).toLowerCase()).charAt(0);
                if(val > 123 || val < 97) return false; //If the string has any symbols.
                if(charMap[val%26]){
                    asciiSum -= val;
                    charMap[val%26] = false;
                } else {
                    asciiSum += val;
                    charMap[val%26] = true;
                }
            }
        }
        if(asciiSum != 0){
            int outstandingVals = 0;
            for(int i = 0; i < 26; i++){
                if(charMap[i]) outstandingVals++;
                if(outstandingVals > 1) return false;
            }
        }
        return true;
    }

    /*
     * Interview Question 1.5
     * One Away: There are three types of edits that can be performed on strings: Insert a character, remove a character, or replace a character. 
     * Given two strings, write a function to check if they are one eidt (or zero edits) away.
     */

    public static boolean OneAway(String a, String b){

        //INCOMPLETE
        // int numEdits = 0;
        // for(int i = 0; i < (a.length()>=b.length()?a:b).length(); i++){
        //     if(i+1 > (a.length()<=b.length()?a:b).length())
        //     if(a.charAt(i) != b.charAt(i)){
        //         if(
        //             a.substring(i) == b.substring(i+1) ||
        //             a.substring(i+1) == b.substring(i)
        //         ){
        //             numEdits++;
        //         } else {

        //         }
                
        //     }
        //     if(numEdits > 1) return false;
        // }
        return false;
    }

    /*
     * Interview Question 1.6
     * String compression: Implement a method to perform basic string compression using the couints of repaeated characters.
     * For example: The string aabcccccaaa would become a2b1c5a3. If the 'compressed' string would not become smaller than the original string, your method should return the original string. 
     * You can assume that the string has only uppercase and lowercase letters (a-z).
     * 
     */

    public static String stringCompression(String str){
        /*
         * Solution #1:
         * We want to look at this problem in compoenents, by seperating 'instrucutions' on what we should do when we reach a new character or if we reach a character that isnt new.
         * To do this, we want to keep track of a few things. First of all, we want to store our new 'string' as a character array. This will allow up to remove the need to store data in two places (like an int array and a char array).
         * As we traverse the string, we want to keep track of the index that we are storing data, this is 'index' and stores the maximum Out of bounds index for our charArray of data.
         * Furthermore, as we traverse, we want to compare a counter to a current value of the string, this is what currentChar is, it keeps track of the most recent char to identify if we are at a new value or not.
         * As we traverse further we want to add our counts for how ofter a letter apears at [index-1] and the actual char at [index-2].
         */
        int index = 0;
        char[] strCompressed = new char[str.length()*2];
        char currentChar = ' ';
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == currentChar){
                int count = strCompressed[index-1];
                count++;
                strCompressed[index-1] = (char) count;
            } else {
                index += 2;
                currentChar = str.charAt(i);
                strCompressed[index-2] = currentChar;
                strCompressed[index-1] = '1';
            }
        }
        return new String(strCompressed).substring(0, index);
    }

    /*
     * Interview Question 1.9
     * Assume you have a method isSubstring which cheks if one word is a substring of another. 
     * Given two strings, s1 and s2, write code to check is s2 is a rotation of s1 using only one call to isSubstring.
     * (e.g. "waterbottle" is a rotation of "erbottlewat")
     */

    public static boolean isSubstring(String s1, String s2){
        /*
         * Solution 1: 
         * Find a point of matching values within the string, in the example above 'w' will be our reference. 
         * Find that same 'w' in the second string. Once we have that, we will add two substrings, the indicies of the matching value and the rest of the string. 
         * If it does not equal the reference string then they cannot be shifts of one another; false.
         */

        if(s1.length() != s2.length()) return false;

        for(int i = 0; i < s2.length(); i++){
            if(s1.charAt(0) == s2.charAt(i)){
                String compare = s2.substring(i) + s2.substring(0, i);
                if(s1.equals(compare)) return true; 
            }
        }
         return false;
        
    }
}