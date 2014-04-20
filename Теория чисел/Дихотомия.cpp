int bin_search(int size,int key)
{
    int first=0,last=size-1,mid;
    if(size==0 || arr[0] > key || arr[size-1] < key)
        return -1;
    while(first < last)
    {
        mid=first + ((last-first)>>1);
        if(arr[mid == key)
            return mid;
        else if(arr[mid] < key)
            first=mid+1;
        else
            last=mid-1;
    }
    if(arr[last] == key)
        return last;
    else
        return -1;
}
