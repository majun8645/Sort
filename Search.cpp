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


void Merge(int A[], int left, int mid, int right)// �ϲ��������ź��������A[left...mid]��A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // �����ռ�O(n)
    int index = 0;
    int i = left;                   // ǰһ�������ʼԪ��
    int j = mid + 1;                // ��һ�������ʼԪ��
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // ���Ⱥű�֤�鲢������ȶ���
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

/*���鲢�����ʵ�ַ�Ϊ�ݹ�ʵ����ǵݹ�(����)ʵ�֡��ݹ�ʵ�ֵĹ鲢�������㷨����з��β��Եĵ���Ӧ�ã����ǽ�һ��������ָ��С�����
    ������Ȼ��������С����Ĵ���������������⡣�ǵݹ�(����)ʵ�ֵĹ鲢�������Ƚ����������鲢��Ȼ�����Ĺ鲢��Ȼ���ǰ˰˹鲢��һֱ
	��ȥֱ���鲢���������顣
*/
void MergeSortRecursion(int A[], int left, int right)    // �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
{
    if (left == right)    // ������������г���Ϊ1ʱ���ݹ鿪ʼ���ݣ�����merge����
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}
void MergeSortIteration(int A[], int len)    // �ǵݹ�(����)ʵ�ֵĹ鲢����(�Ե�����)
{
    int left, mid, right;// ����������,ǰһ��ΪA[left...mid]����һ��������ΪA[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // ������Ĵ�Сi��ʼΪ1��ÿ�ַ���
    {
        left = 0;
		printf("**********i=%d*************************\n",i);
        while (left + i < len)              // ��һ�����������(��Ҫ�鲢)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// ��һ���������С���ܲ���
            Merge(A, left, mid, right);
			
			for(int k=0;k<len;k++)
			{
				printf("%d ",A[k]);
			}
			printf("\n");
			
            left = right + 1;               // ǰһ����������������ƶ�
        }
    }
}


void  heapAdjust( int a[], int i, int nLength)
{
    int nChild;
    int nTemp;
    for (nTemp = a[i]; 2 * i + 1 < nLength; i = nChild)
    {
        // �ӽ���λ��=2*�������λ�ã�+ 1
        nChild = 2 * i + 1;
        // �õ��ӽ���нϴ�Ľ��
        if ( nChild < nLength-1 && a[nChild + 1] > a[nChild])
            ++nChild;
        // ����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
        if (nTemp < a[nChild])
        {
            a[i] = a[nChild];
            a[nChild]= nTemp;
        }
        else
        // �����˳�ѭ��
            break;
    }
}

// �������㷨
void heap_sort(int a[],int length)
{
    int tmp;
    // �������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
    //length/2-1�ǵ�һ����Ҷ�ڵ㣬�˴�"/"Ϊ����
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
	
    // �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for (int i = length - 1; i > 0; --i)
    {
        // �ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ�����
        // ��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
      ///  Swap(&a[0], &a[i]);
          tmp = a[i];
          a[i] = a[0];
          a[0] = tmp;
        // ������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
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