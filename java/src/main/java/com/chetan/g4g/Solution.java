package com.chetan.g4g;

/**
 * Created by chetan on 26/8/15.
 */
public class Solution {
    public int lengthOfLastWord(String s) {
        String[] words=s.split(" ");
        int len =words.length;
        return words[len-1].length();
    }

    public static void main(String[] args){

    }
}
