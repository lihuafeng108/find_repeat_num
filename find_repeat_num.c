#include <stdio.h>

static void swap(int *pnum, int i, int j)
{
    int tmp = pnum[i];
    
    pnum[i] = pnum[j];
    pnum[j] = tmp;
}

static int find_repeat(int *pnum, int len)
{
    if(NULL == pnum || len <= 0)
    {
        return -1;
    }
    
    for(int i=0; i<len; i++)
    {
        while(pnum[i] != i)
        {
            if(pnum[i] == pnum[pnum[i]])
            {
                return pnum[i];
            }
            
            swap(pnum, i, pnum[i]);
        }
    }
    
    return -1;
}

int main(void)
{
    int num[6] = {3, 5, 2, 1, 2, 1};
    
    int ret = find_repeat(num, 6);
    if(ret > 0)
    {
        printf("find the repeat num: %d\n", ret);
    }
    else
    {
        printf("don't find the repeat num");
    }
    
    return 0;
}