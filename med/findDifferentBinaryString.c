// Find Unique Binary String

char* findDifferentBinaryString(char** nums, int numsSize) 
{
    char* result=(char*)malloc((numsSize+1)*sizeof(char));
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i][i]=='0')
        result[i]='1';
        else
        result[i]='0';
    }
    result[numsSize]='\0';
    return result;
}