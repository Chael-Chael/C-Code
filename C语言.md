# C语言汇总

## 质数判断

```c
int isPrimeNumber(int x)
{
    int i;
    if (x < 2)
    {
        return 0;
    } 
    for (i = 2; i * i <= x; i ++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}  
```

## 质因数分解

```c
void printPrimeFactors(int x)
{
    int i;
    printf("%d = ", x);

    //
    for (i = 2; i <= x; i ++)
    {
        while (x % i == 0)
        {
            printf("%d", i);
            x /= i;

            if (x != 1)
            {
                printf("*");
            }
        }
    }

    printf("\n");
}
```

## 排序函数

### 共性
* 总比较轮次都是n-1
* 
### 冒泡排序
从 i = 1 开始，记录次数  
从后向前缩短
```c
void sortArrayBubble( int x[], int xSize )
{
    int i = 0, j = 0;
    int hold, isSwapped;

    for ( i = 1 ; i < xSize ; i ++ ) //比较轮次
    {
        isSwapped = 0;

        for ( j = 0; j < xSize - i ; j ++ ) //j+1 = n-i-1
        {
            if ( x[j] > x [j+1])
            {
                hold = x[j];
                x[j] = x[j+1];
                x[j+1] = hold;

                isSwapped ++ ;
            }
        } // end of inner for loop

        if ( isSwapped == 0 )
        {
            break;
        } // terminate the loop when sorted

    }// end of outer for loop
}
```

### 选择排序  
从 i = 0 开始，记录下标  
从前向后缩短
```c
void sortArraySelect( int x[], int xSize )
{
    int i, j;
    int min_index, min_value;

    for ( i = 0; i < xSize - 1; i ++)
    {
        min_index = i; //从已经排序的序列结尾

        for ( j = i + 1; j < xSize; j ++ )
        {
            if ( x[min_index] > x[j] )
            {
                min_index = j;
            }
        }// end of inner for loop

        //找到更小
        if ( min_index != i )
        {
            min_value = x[min_index];
            x[min_index] = x[i];
            x[i] = min_value;
        }
    }// end of outer for loop
}
```

### 插入排序
#### 数组移动
将insert_value插入原moving_start位置
```c
for (j = moving_end; j >= moving_start; j --)
{
    a[j+1] = a[j];
}
a[j+1] = insert_value //j+1 = moving_start_origin
```
#### 排序
从 i = 1 开始，统计轮次  
从前向后缩短
```c
void sortArrayInsert( int x[], int xSize )
{
    int i, j, insert_value;

    for ( i = 1; i < xSize; i ++ )
    {
        insert_value = x[i]; //从已经排序的序列结尾后面一个数

        //x[j] <= insert_value，插入j+1位置
        for ( j = i - 1; ( j >= 0 ) && ( x[j] > insert_value ); j -- )
        {
            x[j + 1] = x[j];
        }

        if ( j != i - 1 )
        {
            x[j+1] = insert_value;
        }

    }
}
```
## 排名函数
**对于相同的排名，如2，2，算作两个，所以是1，2，2，4**  
```c
void getOneRoundRanks( const int oneVotes[], int oneRanks[], const int numPlayers)
{
    int i, j;

    for (i = 0; i < numPlayers; i++)
    {
        oneRanks[i] = 1; //每个初始值为1

        //compare the votes of each player，有大的就加1
        for (j = 0; j < numPlayers; j++)
        {
            if (oneVotes[j] > oneVotes[i])
            {
                oneRanks[i]++;
            }
        }
    }
}
```
## 查找函数
```c
int searchArray_binary( const int x[], int key, int xSize )
{
    int middle;
    int low = 0, high = xSize - 1;

    while ( low <= high )
    {
        middle = ( low + high ) / 2;

        if ( 1 )
        {
            printf("Binary search: low = %d, high = %d, middle = %d, ",
                   low, high, middle );
            printf(" x[%d] = %d \n", middle, x[middle] );
        }

        if ( key == x[middle] )
        {
            return middle;
        }
        else if ( key < x[middle] )
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return -1 ;
}
```
## 内存分配
返回的是地址，参数加上sizeof(类型)
无初始化，任意值
`int* ptr = (int*) malloc( sizeof(int) * SIZE )`
分配内存，但内存置0
`int* ptr = (int*) calloc( sizeof(int) , SIZE )`
重新分配大小，无法在远处连续扩大缩小，返回指针值为NULL，故应该加if指针为NULL报错
`int* ptr = (int*) realloc( ptr , sizeof(int) * SIZE )`
free以后ptr指针仍然指向原区域，应该置NULL
`free(ptr)`
`ptr = NULL`

## 指针有关概念
### 指针的数组
`int* ptr[4];`
### 数组的指针
`int (*ptr)[4];`
### 结构体的指针
`struct student *ptr;`
### 指针与函数
`定义一个int fun(var1, var2)`
`int (*ptr)(var1, var2)`
`(*ptr)('a', 10010)`调用
## 随机数生成
```c
#include <stdlib.h>
#include <time.h>

srand(time(NULL));
x = rand() % range (0到range-1) + start;
```
## 统计数组元素频次
### 统计频率
* 首先我们声明一个大小和inputArray一样的数组countryArray，并将每个元素值初始化为-1，用来存储每个元素的频率。这需要一些技巧来达到和HashMap一样的效果却也不损失太多性能。
* if countArray[i] == -1，表示我们还没有统计inputArray[i]这个元素的频率； if countArray[i] == 0，表示我们已经统计过元素inputArray[i]的频率了。
* 用循环遍历InputArray，from 0 到 N-1，统计每个元素的频率。
* 对于当前元素inputArray[i]，if countArray[i] == -1，我们就保存这个元素的频率到countArray[i]；否则，不保存，因为之前已经统计过它了。

![示例](https://img-blog.csdn.net/20180529234553824)
```c
for(i = 0; i < elementCount; i++) {  
    //开始统计inputArray[i]这个元素的出现频率
    //至少出现1次
    count = 1;  

    // 值为0表示该数字已经被统计过
    if (countArray[i] == 0) {continue;} 
    for(j = i+1; j < elementCount; j++) {  
        if(inputArray[i]==inputArray[j]) {
            countArray[j] = 0;    
            count++;
        }  
    }  
    //记录inputArray[i]出现的频率
    countArray[i] = count;
}  

/* Print count of each element */   
for(i = 0; i<elementCount; i++) {  
    if(countArray[i] != 0) {  
        printf("Element %d : Count %d\n", inputArray[i], countArray[i]);  
    }  
}
```
原文链接：https://blog.csdn.net/lx1848/article/details/52817802
### 统计唯一值
上文为1的值
### 去重
* 使用上文统计频率的算法，所有为0的数均是重复的元素
* 排序后双指针  

![示例](https://img-blog.csdnimg.cn/184caa0f81694d8294bbfd63fe0fb224.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBATVRfMTI1,size_20,color_FFFFFF,t_70,g_se,x_16)
```c
int removeDuplicates(int* nums, int numsSize)
{
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
```
* 没排序
```c
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
```
### 数组大小
`int size = sizeof(arr) / sizeof(arr[0]);`
### 寻找最大值
```c
int findMax(int arr[], int size) {
    // 假设数组至少包含一个元素
    int max = arr[0];

    // 遍历数组，更新最大值
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}
```

## 字符串数组

## 最大公约数、最小公倍数
```c
// 辗转相除法求最大公因数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 求最小公倍数
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
```
## 转换符

## 结构体
```c
typedef struct (tag){
...
} NewName

NewName struct_name = ...
```
## 二进制转换十进制
### 移位法
![1702975149638](image/C语言/1702975149638.png)
### 幂次
```c
int binaryToDecimal(int binaryNumber) {
    int decimalNumber = 0;
    int base = 1; // 2^0

    while (binaryNumber > 0) {
        int remainder = binaryNumber % 10;
        decimalNumber += remainder * base;
        binaryNumber /= 10;
        base *= 2;
    }

    return decimalNumber;
}
```
```c
#include <stdio.h>
#include <math.h>  // 调用pow函数 需要用include 包含math.h这个头文件
int main()
{
   int n,i,j,sum=0;char c[1000]; //使用字符数组记录n个数；
   scanf("%d",&n)
   getchar(); //  消去'\n'一个；
   for(i=0;i<n;i++){
   	scanf("%c",&c[i]); //遍历数组 记录n个数；
   }
   for(j=0;j<n;j++){  //遍历数组，当c[j]为'1'时，用计算它的值；
   	if(c[j]=='1')
   	sum+=pow(2,i-1); //pow函数用于计算乘方，相当于2的i-1次方；
   	i--;     //每次让i--；使2的乘方少乘一次；
   }
   printf("%d\n",sum);
 return 0;
```
## 十进制转换二进制
```c
long decimalToBinary(int decimalNumber) {
    long binaryNumber = 0;
    long base = 1;

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;
        binaryNumber += remainder * base;
        decimalNumber /= 2;
        base *= 10;
    }

    return binaryNumber;
}
```
## ifdef的使用

## 字符串交并集