
void quicksort(vector<int> &arr,int l,int r)
{
    int i=l,j=r,mid=arr[l+((r-l)>>1)];
    while(i<=j)
    {
        while(arr[i] < mid) i++;
        while(arr[j] > mid) j--;
        if(i<=j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(i < r)
        quicksort(arr,i,r);
    if(l<j)
        quicksort(arr,l,j);
}
