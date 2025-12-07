// Count Odd Numbers in an Interval Range

int countOdds(int low, int high){
    int count = 0;
    for(int i = low; i <= high; i++)
    {
        if(i % 2 != 0)
            count++;
    }
    return count;
}