#ifndef PATTERNMATCH_H_INCLUDED
#define PATTERNMATCH_H_INCLUDED

int patternmatch(const char *m,const char *str)
{
    int i=0,j=0,k=0;
    int flag=0;
    int len_m=strlen(m);
    int len_str=strlen(str);
    while(i<len_str&&j<len_m)
    {
        if(m[j]==str[i])
        {
            k++;
            i++;
            j++;
            if(k==len_m)
            {
                flag=1;
                break;
            }
        }
        else
        {
            j-=k;
            i=i-k+1;
            k=0;
        }
    }
    return flag;
}
#endif // PATTERNMATCH_H_INCLUDED
