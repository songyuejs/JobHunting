/*!
* 
* 实现各种排序算法:冒泡排序、简单选择排序、直接插入排序、折半插入排序、希尔排序、
* 堆排序、归并排序(递归)、递归排序(非递归)、快速排序
* \author tonywang
* \date 2014/4/16 11:50
*
*/

#include "stdio.h"
#include "malloc.h"

#define MAXSIZE 10

void swap(int* arr, int i, int j);
void bubbleSort(int* arr, int length);
void selectSort(int* arr, int length);
void insertSort(int* arr, int length);
void binaryInsertSort(int* arr, int length); //折半插入排序
void shellSort(int* arr, int length);
void heapSort(int* arr, int length);
void mergeSort(int* arr, int length);
void mergeSort2(int* arr, int length);
void quickSort(int *arr, int length);


int main(int argc, char* argv[])
{
	int number[10]={10,2,3,5,7,7,2,1,0,-1};
	const int length = sizeof(number)/sizeof(int); //length不定义为const，mergeSort执行后会变成1，不解..
	printf("before sort: ");
	for(int i=0;i<length;i++)
		printf("%d  ",number[i]);
	printf("\n");

	//bubbleSort(number,length);
	//selectSort(number,length);
	//insertSort(number,length);
        binaryInsertSort(number,length);
	//shellSort(number,length);
	//heapSort(number,length);
	//mergeSort(number,length);
	//mergeSort2(number,length);
	//quickSort(number,length);

	printf("after  sort: ");

	for(int i=0;i<length;i++)
		printf("%d  ",number[i]);
	
	getchar();
	return 0;
}

void swap(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


/**
---------------------冒泡排序----------------------------
*时间复杂度：O(n^2)
*空间复杂度：O(1)
*稳定
---------------------------------------------------------*/
void bubbleSort(int* arr, int length)
{
	bool flag = true;
	for(int i=0;i<length && flag;i++)
	{
		bool flag = false;
		for(int j=length-1;j>i;j--)
		{
			if(arr[j-1]>arr[j]){
				swap(arr,j-1,j);
				flag = true;
			}
		}
	}
}


/**
----------------------简单选择排序-----------------------
*时间复杂度：O(n^2)
*空间复杂度：O(1)
*稳定
---------------------------------------------------------*/
void selectSort(int* arr, int length)
{
	for(int i=0;i<length;i++)
	{
		int min = i;
		for(int j=i+1;j<length;j++)
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}
		if(min != i)
			swap(arr,i,min);
	}
}


/**
---------------------直接插入排序------------------------
*时间复杂度：O(n^2)
*空间复杂度：O(1)
*稳定
---------------------------------------------------------*/
void insertSort(int* arr,int length)
{
	for(int i=1;i<length;i++)
	{
		if(arr[i]<arr[i-1])
		{
			int temp = arr[i];
			int j;
			for(j=i-1;arr[j]>temp&&j>=0;j--)
				arr[j+1] = arr[j];
			arr[j+1] = temp;
		}
	}
}


/**
--------------------折半插入排序--------------------------
*时间复杂度：O(n^2) 移动记录次数没变，比较次数减少
*空间复杂度：O(1)
*不稳定
---------------------------------------------------------*/
void binaryInsertSort(int* arr, int length)
{
	for(int i=1;i<length;i++)
	{
		if(arr[i]<arr[i-1])
		{
			//从0..i-1之中二分查找插入点
			int temp = arr[i];
			int low = 0, high = i-1;
			while(low<=high)
			{
				int mid = (low+high)/2;
				if(temp<arr[mid])
					high = mid-1;
				else if(temp>arr[mid])
					low = mid+1;
				else
					break;
			}
			int pos = 0;
			if(low<high) 
				pos = (low+high)/2 + 1; 
			else  
				pos = low;
			//插入点之后的记录后移
			for(int m=i-1;m>=pos;m--)
				arr[m+1] = arr[m];
			arr[pos] = temp;
		}
	}
}


/**
----------------------希尔排序---------------------------
*时间复杂度：O(nlogn)~O(n^2)
*空间复杂度：O(1)
*不稳定
---------------------------------------------------------*/
void shellSort(int* arr,int length)
{
	int increment = length;
	while(increment>1){
		increment = increment/3+1;
		//printf("%d\n",increment);
		for(int i=increment;i<length;i++)
		{
			if(arr[i]<arr[i-increment])
			{
				int temp = arr[i];
				int j;
				for(j=i-increment;j>=0&&arr[j]>temp;j-=increment)
					arr[j+increment] = arr[j];
				arr[j+increment] = temp;
			}
		}
	}
}


/**
----------------------堆排序------------------------------
*时间复杂度：构建堆O(n)，重建堆O(nlogn)，总复杂度为O(nlogn)
*空间复杂度：O(1)
*不稳定
---------------------------------------------------------*/
void heapSort(int* arr, int length)
{
	void heapAdjust(int* arr, int s, int e);

	for(int i=length/2;i>0;i--)
		heapAdjust(arr, i, length);
	
	for(int i=length;i>1;i--)
	{
		swap(arr,0,i-1);
		heapAdjust(arr, 1, i-1);
	}
}

/*
已知arr[s-1..e-1]除arr[s-1]外，都符合堆的定义，
调准arr[s-1]，使arr[s-1..e-1]成为一个大顶堆
*/
void heapAdjust(int* arr, int s, int e)
{
	int temp = arr[s-1];  //需要调准的根节点
	for(int j=2*s;j<=e;j*=2)
	{
		if(j<e && arr[j-1]<arr[j]) //左孩子和右孩子哪个较大,沿大的往下比较
			++j;
		if(temp>=arr[j-1])
			break;
		arr[s-1] = arr[j-1];
		s = j;
	}
	arr[s-1] = temp;
}



/**
*--------------归并排序，递归实现------------------
*时间复杂度：logn次归并，每次归并遍历n，O(nlogn)
*空间复杂度: 归并过程中的存储空间O(n)+递归深度O(logn)
*稳定
**/
void mergeSort(int* arr, int length)
{
	void mSort(int* arr1, int* arr2, int s, int e);

	mSort(arr,arr,0,length-1);
}

//将arr1[s..e]归并排序为arr2[s..e]
void mSort(int* arr1, int* arr2, int s, int e)
{
	void merge(int* arr1, int* arr2, int s, int m, int e);

	//int *arr = new int[MAXSIZE];
	int *arr = (int*)malloc(MAXSIZE*sizeof(int));
	if(s == e)
		arr2[s]=arr1[s];
	else
	{
		int m = (s+e)/2;
		mSort(arr1,arr,s,m);
		mSort(arr1,arr,m+1,e);
		merge(arr,arr2,s,m,e);
	}
}

//将有序的arr1[s..m]和arr1[m+1..e]归并到有序的arr2[s..e]
void merge(int* arr1, int* arr2, int s, int m, int e)
{
	int i;
	for(i=s;s<=m&&m+1<=e;i++)
	{
		if(arr1[s]<arr1[m+1])
			arr2[i] = arr1[s++];
		else
		{
			arr2[i] = arr1[m+1];
			m++;
		}
	}
	if(s<=m)
	{
		for(int k=0;k<=m-s;k++)
			arr2[i+k] = arr1[s+k];
	}
	if(m+1<=e)
	{
		for(int k=0;k<=e-m-1;k++)
			arr2[i+k] = arr1[m+1+k];
	}

}


/**
*--------------归并排序，非递归实现------------------
*时间复杂度：O(nlogn)
*空间复杂度: 归并过程中的存储空间O(n)
*稳定
**/
void mergeSort2(int* arr, int length)
{
	void mergePass(int* arr1, int* arr2, int s, int n);

	int* tr = new int[length];
	int k=1;
	while(k<length)
	{
		mergePass(arr,tr,k,length);
		k = 2*k;
		mergePass(tr,arr,k,length);
		k = 2*k;
	}
}

//将arr1中相邻为s的子序列两两归并到arr2中
void mergePass(int* arr1, int* arr2, int s, int n)
{
	int i = 1;
	while(i<=n-2*s+1)
	{
		merge(arr1,arr2,i-1,i+s-1-1,i+2*s-1-1);
		i=i+2*s;
	}
	if(i<n-s+1)
		merge(arr1,arr2,i-1,i+s-1-1,n-1);
	else
		for(int j=i-1;j<n;j++)
			arr2[j] = arr1[j]; 
}

/**
*--------------快速排序------------------
*时间复杂度：平均、最好O(nlogn)，最坏O(n^2)
*空间复杂度: O(logn)~O(n)
*不稳定
**/
void quickSort(int *arr, int length)
{
	void qSort(int *arr, int low, int high);

	qSort(arr, 0, length-1);
}

//对数组中的子序列arr[low..high]作快速排序
void qSort(int *arr, int low, int high)
{
	int partition(int *arr, int low, int high);

	int pivot;
	if(low<high)
	{
		pivot = partition(arr, low, high);
		qSort(arr, low, pivot-1);
		qSort(arr, pivot+1, high);
	}
}

//交换数组中子表的记录，使枢纽记录到位，并返回其位置
int partition(int *arr, int low, int high)
{
	int pivotkey;
	pivotkey = arr[low];//子序列中的第一个记录作为枢纽记录
	while(low<high)
	{
		while(low<high&&arr[high]>pivotkey)
			high--;
		swap(arr,low,high);
		
		while(low<high&&arr[low]<=pivotkey)
			low++;
		swap(arr,low,high);
	}
	return low;
}
