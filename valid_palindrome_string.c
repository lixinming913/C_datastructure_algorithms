/*
 * Valid Palindrome
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 */ 
bool isPalindrome(char* s) {
    if(s == NULL)
        return true;
    
    int l = 0;
    int r = strlen(s) - 1;
    while(l < r) {
        while(l < r && !isalnum(s[l]))
            l++;
        while(l < r && !isalnum(s[r]))
            r--;
        if(toupper(s[l++]) != toupper(s[r--]))
            return false;
    }
    
    return true;
}

