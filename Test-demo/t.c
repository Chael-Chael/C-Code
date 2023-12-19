#include<stdio.h>

int removeDuplicates(int* nums, int numsSize){
       
        int* str = nums;
        int* stR = str+1;
        int k = 0;                           //k 和 i 是位置加减的变量
        int i = 0;                           
        for(i = 0,k = 0;i<numsSize-1;i++)
        {
            if(*(str+i) != *( str+i+1))      //判断错位 元素是否相等
            {
               *(stR+k) = *(str+i+1); 
               k++;
            }
        }
        return k+1;                          //放回去重完数组的长度
    }

int main()
{
	
	int a[] = {1,2,2,2,2,2,1,4,2,1,4,2,4,3,5,2,3,5,3,2,2,5,3,1,1,1};
    int n = sizeof(a) / sizeof(a[0]);
    int temp,j,i;
    for(i=0;i<n;i++)		//循环判断数组中每一个数
	{
		for(j=i+1;j<n;j++)	//判断a[i]后边的数是否和a[i]相等
		{
			if(a[i]==a[j])
			{
				for(temp = j;temp<n-1;temp++)
					a[temp]=a[temp+1];	//将a[j]后面的元素全往前移一个位置
				j--;	//a[j+1]取代a[j]位置，为使下次从a[j+1]开始查找,j减一(为使j保持不变)
				n--;	//数组长度减一
			}
		}
	}
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
