// Binary Watch

int countBit(int i)
{
    int count=0;
    while(i)
    {
        count+=(i&1);
        i>>=1;
    }
    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize)
{
    char **retString=(char **)malloc(1000*sizeof(char *));
    *returnSize=0;

    for(int h=0;h<12;h++)
    {
        for(int m=0;m<60;m++)
        {
            if(countBit(h)+countBit(m)==turnedOn)
            {
                retString[*returnSize]=(char*)malloc(6*sizeof(char));
                snprintf(retString[*returnSize],6,"%d:%02d",h,m);
                *returnSize+=1;
            }
        }
    }
    return retString;
}