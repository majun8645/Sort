#include<iostream>
using namespace std;
void BubleSort(int *a,int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len -i - 1;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void SelectSort(int *a,int len)
{
	int minIndex = 0;
	for(int i=0;i<len-1;i++)
	{ 
		minIndex = i;	
		for(int j=i+1;j<len;j++)
		{
			if(a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		int tmp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = tmp;
	}
}
void  InsertSort (int *a,int len)
{
	int i,j,v;
	for(i=1;i<len;i++)
	{
		for(v=a[i],j=i-1;j>=0&&v<a[j];j--)
		{
			a[j+1] = a[j];
		}
		a[j+1]= v;
	}
}
void  InsertSort01 (int *a,int len)
{
		int i,j,tmp;
		for(i=1;i<len;i++)
		{
			tmp= a[i];
			
			for(j=i-1;j>=0;j--)
			{
				if(a[j] > tmp )a[j+1] = a[j];
				else break;
			}
			a[j+1] = tmp;	
		}
}
void  InsertSort02 (int *a,int len)
{
	int tmp ,i,j;
	for(i=1;i<len;i++)
	{
		tmp = a[i];
		j = i-1;
		while(j>=0 && a[j] > tmp)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
		for(int i= 0;i<len;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}

void  ShellSort(int *a,int len)
{
	int i,j,gap,tmp;
	gap = len/2;
	printf("gap=%d,len=%d\n",gap,len);
	
	while(gap > 0)
	{
		printf("\n**************gap=%d*********************\n",gap);
		for(i= gap;i<len;i++)
		{
			tmp = a[i];
			j = i-gap;
			while(j>=0&&tmp<a[j])
			{
				a[j+gap] = a[j];
				j -= gap;
			}
			a[j+gap] = tmp;
			
			for(int i= 0;i<len;i++)
			{
				printf("%d ",a[i]);
			}
			printf("\n");
		}
		gap = gap/2;
	}		
}
void Merge(int*a1,int len1,int*a2,int len2,int*a3,int len3)
{
	if(len1+len2!=len3)return;
	int i=0,j=0,k=0;
	while(i<len1&&j<len2)
	{
		if(a1[i]<a2[j])
		{
			a3[k++] = a1[i++];
		}
		else
		{
			a3[k++] = a2[j++];
		}
	}
	if(i!=len1)
	{
		for(int n=i;n<len1;n++)
		{
			a3[k++]=a1[i];
		}
	}
	if(j!=len2)
	{
		for(int n=j;n<len2;n++)
		{
			a3[k++]=a2[j];
		}
	}
}


void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
}

/*　归并排序的实现分为递归实现与非递归(迭代)实现。递归实现的归并排序是算法设计中分治策略的典型应用，我们将一个大问题分割成小问题分
    别解决，然后用所有小问题的答案来解决整个大问题。非递归(迭代)实现的归并排序首先进行是两两归并，然后四四归并，然后是八八归并，一直
	下去直到归并了整个数组。
*/
void MergeSortRecursion(int A[], int left, int right)    // 递归实现的归并排序(自顶向下)
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}
void MergeSortIteration(int A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
{
    int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
    {
        left = 0;
		printf("**********i=%d*************************\n",i);
        while (left + i < len)              // 后一个子数组存在(需要归并)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
            Merge(A, left, mid, right);
			
			for(int k=0;k<len;k++)
			{
				printf("%d ",A[k]);
			}
			printf("\n");
			
            left = right + 1;               // 前一个子数组索引向后移动
        }
    }
}


void  heapAdjust( int a[], int i, int nLength)
{
    int nChild;
    int nTemp;
    for (nTemp = a[i]; 2 * i + 1 < nLength; i = nChild)
    {
        // 子结点的位置=2*（父结点位置）+ 1
        nChild = 2 * i + 1;
        // 得到子结点中较大的结点
        if ( nChild < nLength-1 && a[nChild + 1] > a[nChild])
            ++nChild;
        // 如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if (nTemp < a[nChild])
        {
            a[i] = a[nChild];
            a[nChild]= nTemp;
        }
        else
        // 否则退出循环
            break;
    }
}

// 堆排序算法
void heap_sort(int a[],int length)
{
    int tmp;
    // 调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是第一个非叶节点，此处"/"为整除
	printf("length / 2 - 1=%d\n",length / 2 - 1);
    for (int i = length / 2 - 1; i >= 0; --i)
	{
		heapAdjust(a, i, length);
	}
	for(int k= 0;k<length;k++)
	{
		printf("%d ",a[k]);
	}
	printf("\n");
	
    // 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (int i = length - 1; i > 0; --i)
    {
        // 把第一个元素和当前的最后一个元素交换，
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
      ///  Swap(&a[0], &a[i]);
          tmp = a[i];
          a[i] = a[0];
          a[0] = tmp;
        // 不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        heapAdjust(a, 0, i);
    }
}
void Part(int *a,int left,int right)
{
	int i=left,j=right;
	int tmp = a[i];
	while(i<j)
	{
		while(tmp < a[j]&&i<j)j--;
		if(i<j)a[i++] = a[j];

		while(tmp > a[i]&&i<j)i++;
		if(i<j)a[j--] = a[i];
	}
	printf("i=%d,j=%d\n",i,j);
	a[i] = tmp;
}

void Part01(int *a,int left,int right)
{
	int pivot = left;
	int index = pivot+1;
	int tmp = 0;
	for(int i = index;i<=right;i++)
	{
		if(a[i]<a[pivot])
		{
			tmp = a[i];
			a[i]=a[index] ;
			a[index++] = tmp;
		}
	}
	tmp = a[pivot];
	a[pivot] = a[index-1];
	a[index-1] = tmp;
}

int main(int argc,char*argv[])
{
	int a[15] = {8,6,7,5,3,10,9,1,2,4,6,5,4,3,2};
	//BubleSort(a,sizeof(a)/sizeof(int));
	//SelectSort(a,sizeof(a)/sizeof(int));
	//InsertSort(a,sizeof(a)/sizeof(int));
	//InsertSort01(a,sizeof(a)/sizeof(int));
	printf("original:\n");
	for(int i= 0;i<sizeof(a)/sizeof(int);i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	//InsertSort02(a,sizeof(a)/sizeof(int));
	//ShellSort(a,sizeof(a)/sizeof(int));
	/*
	for(int i= 0;i<sizeof(a)/sizeof(int);i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	*/
	
	/*
	int a1[8] = {2,3,3,5,6,8,9,10};
	int a2[4] = {1,3,5,7};
	int a3[12];
	printf("************Merge*****************\n");
	Merge(a1,sizeof(a1)/sizeof(int),a2,sizeof(a2)/sizeof(int),a3,sizeof(a3)/sizeof(int));
	for(int i= 0;i<sizeof(a3)/sizeof(int);i++)
	{
		printf("%d ",a3[i]);
	}
	printf("\n");
	*/
	 //MergeSortIteration(a,sizeof(a)/sizeof(int));
	// heap_sort(a,sizeof(a)/sizeof(int));
	int b[8] = {3,1,9,8,5,6,7,2};
	Part(b,0,sizeof(b)/sizeof(int)-1);
	 for(int i= 0;i<sizeof(b)/sizeof(int);i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	
	int c[8] = {3,1,9,8,5,6,7,2};
	Part01(c,0,sizeof(c)/sizeof(int)-1);
	 for(int i= 0;i<sizeof(c)/sizeof(int);i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");
	 
	
}