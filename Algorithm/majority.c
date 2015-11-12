int Majority(int num[], int n)// to find the majority of the array
{
    int cand = num[0];
    int mul = 1;
    //first scan delete all the vote except cand
    int i, majority;
    for(i = 1; i < n; i++)
    {
        if(mul == 0)//find the candidate newly
        {
            cand = num[i];
            mul = 1;
        }
        else
        {
            if(cand == num[i])
                mul++;
            else
                mul--;
        }
    }
    //second scan  judge the candidate is majority or not
    if(mul == 0)
        majority = -1;
    else
    {
        int cnt = 0;
        for(i = 0; i < n; ++i)
            if(cand == num[i])
                cnt++;
        if(cnt > n / 2)
            majority = cand;
        else
            majority = -1;
    }
    return majority;
}