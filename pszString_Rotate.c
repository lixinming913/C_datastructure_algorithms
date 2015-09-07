/*字符串左移:比如ABCDEFG,移3位变DEFGABC,要求空间复杂度O(1),时间复杂度O(n)*/
void swap(char *string, int i, int j)
{
    char *tmp = string[i];
    string[i] = string[j];
    string[j] = tmp;
}

void *pszStringRotate(char *pszString, int nCharsRotate)
{
    if(pszString == NULL || nCharsRotate <= 0)
        return NULL;
        
    int len = strlen(pszString);
    for(int i = 0; i < len/2; i++) {
        swap(pszString, i, len-1-i);
    }
    
    nCharsRotate %= len;
    if(nCharsRotate == 0)
        return NULL;
    else
    {
        int pivot = len - nCharsRotate;
        for(int i = 0; i < pivot/2; i++)
            swap(pszString, i, pivot-1-i);
        for(int i = pivot; i < (pivot + len -1)/2; i++)
            swap(pszString, i, len-1-i);
    }
}