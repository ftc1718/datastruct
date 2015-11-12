int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int **arr = (int**)malloc(sizeof(int*) * (len1 + 1));
    int i, j;
    for(i = 0; i <= len1; i++)
        arr[i] = (int*)malloc(sizeof(int) * (len2 + 1));
    for(i = 0; i <= len1; i++)
        arr[i][0] = i;
    for(j = 1; j <= len2; j++)
        arr[0][j] = j;
    for(i = 1; i <= len1; i++)
        for(j = 1; j <= len2; j++)
        {
            int tmp;
            if(word1[i - 1] == word2[j - 1])
                tmp = arr[i - 1][j - 1];
            else
                tmp = arr[i - 1][j - 1] + 1;
            arr[i][j] = min(arr[i - 1][j] + 1, arr[i][j - 1] + 1, tmp);
        } 
    return arr[len1][len2];
}