/*************/
/*  选择排序  */
/************/
#include<stdio.h>
void Selection_Sort(int *a,int n)
{
    for (int i = 0; i < n; i++) // 一次选择
    {
        int min = i;
        for (int j = i; j < n; j++) // 选出最小的一个
        {
            if (a[j] < a[min]) min = j;
        }
        int temp = a[i];           // 交换
        a[i] = a[min];
        a[min] = temp;
    }
}
/*测试*/
int main()
{
    int a[10] = {4,2,1,32,5,23,7,9,10,5};
    Selection_Sort(a,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
