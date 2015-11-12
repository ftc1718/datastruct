void delSpace(char *s)
{
    int cnt = 0;
    int space = 1;
    int len = strlen(s);
    int i;
    for(i = 0; i < len; i++)
    {
        if(s[i] != ' ')
        {
            s[cnt++] = s[i];
            space = 0;
        }
        else
        {
            if(!space)
            {
                s[cnt++] = s[i];
                space = 1;
            }
        }
    }
    if(cnt >= 1 && s[cnt - 1] == ' ')
        s[cnt - 1] = '\0';
    else
        s[cnt] = '\0';
}