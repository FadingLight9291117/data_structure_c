/*************/
/*  归并排序  */
/************/
#include<stdio.h>
#include<stdlib.h>
/*核心算法，有序子列的归并*/
void merge(int *a,int *tempA, int left, int right, int rightEnd)
{
    int leftEnd = right - 1;    // 左子列末位置
    int num = rightEnd - left + 1;  // 待排序总数
    int temp = left;   // 存放结果的临时数组的初始位置
    while (left <= leftEnd && right <= rightEnd)
    {
        if (a[left] <= a[right]) 
        {
            tempA[temp++] = a[left++];
        }
        else    
        {
            tempA[temp++] = a[right++];
        }
    }  
    while (left <= leftEnd) 
    {
        tempA[temp++] = a[left++];  // 若左子列有剩余
    }
    while (right <= rightEnd)   
    {
        tempA[temp++] = a[right++]; // 若右子列有剩余
    }
    /*将临时数组tempA，复制到原数组a*/
    /*从右向前复制*/
    for (int i = 0; i < num; i++, rightEnd--)   
    {
        a[rightEnd] = tempA[rightEnd];
    }
}
/*递归算法*/
void MSort(int *a, int *tempA, int left, int rightEnd)
{
    int center;
    if (left < rightEnd)
    {
        center = (left + rightEnd) / 2;
        MSort(a, tempA, left, center);
        MSort(a, tempA, center + 1, rightEnd);
        merge(a, tempA, left, center + 1, rightEnd);
    }
}
/*统一接口，递归算法*/
void Merge_Sort(int *a,int n)
{
    int *tempA = (int *)malloc(n*sizeof(int));
    if (tempA != NULL)
    {
        MSort(a, tempA, 0, n-1);
    }
    free(tempA);
}

/*非递归算法*/
void Merge_Pass(int *a, int *tempA, int n, int len)
{
    int i;
    for (i = 0; i + 2*len <= n; i += 2*len)
    {
        merge(a, tempA, i, i + len, i + 2*len - 1);
    }
    if (i + len < n)
    {
        merge(a, tempA, i, i + len, n - 1);
    }
    else
    {
        while (i < n)
        {
            tempA[i] = a[i];
            i++;
        }
    }
}
void Merge_Pass_Sort(int *a, int n)
{
    int *tempA = (int *)malloc(sizeof(int)*n);
    int i = 1;
    while (i < n)
    {
        Merge_Pass(a, tempA, n, i);
        i *= 2;
        Merge_Pass(tempA, a, n, i);
        i *= 2;
    }
}
int main()
{
    int a[10] = {11,10,82,56,12,16,2,3,4,67};
    Merge_Pass_Sort(a,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}