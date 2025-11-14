// Increment Submatrices by One

int** rangeAddQueries(int n, int** queries, int q, int* queriesColSize, int* returnSize, int** returnColumnSizes)
{
    int i,j;
    int** ret=(int**)malloc(sizeof(int*)*n);
    *returnSize=n;
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        ret[i]=(int*)calloc(n,sizeof(int));
        (*returnColumnSizes)[i]=n;
    }
    for(i=0;i<q;i++)
    {
        ret[queries[i][0]][queries[i][1]]++;
        if(queries[i][2]+1<n)
        {
            ret[queries[i][2]+1][queries[i][1]]--;
        }
        if(queries[i][3]+1<n)
        {
            ret[queries[i][0]][queries[i][3]+1]--;
        }
        if(queries[i][2]+1<n&&queries[i][3]+1<n)
        {
            ret[queries[i][2]+1][queries[i][3]+1]++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            ret[i][j]=ret[i][j-1]+ret[i][j];
        }
    }
    for(j=0;j<n;j++)
    {
        for(i=1;i<n;i++)
        {
            ret[i][j]=ret[i][j]+ret[i-1][j];
        }
    }
    return ret;
}