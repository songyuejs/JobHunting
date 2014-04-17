// Sort.cpp : �������̨Ӧ�ó������ڵ㡣
// 
#include "stdio.h"
#include "malloc.h"

#define MAXSIZE 10

void swap(int* arr, int i, int j);
void bubbleSort(int* arr, int length);
void selectSort(int* arr, int length);
void insertSort(int* arr,int length);
void shellSort(int* arr,int length);
void heapSort(int* arr, int length);
void mergeSort(int* arr, int length);
void mergeSort2(int* arr, int length);
void quickSort(int *arr, int length);


int main(int argc, char* argv[])
{
	int number[10]={10,2,3,5,7,7,2,1,0,-1};
	const int length = sizeof(number)/sizeof(int); //length������Ϊconst��mergeSortִ�к����1������..
	printf("before sort: ");
	for(int i=0;i<length;i++)
		printf("%d  ",number[i]);
	printf("\n");

	//bubbleSort(number,length);
	//selectSort(number,length);
	//insertSort(number,length);
	//shellSort(number,length);
	//heapSort(number,length);
	mergeSort(number,length);
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
---------------------ð������----------------------------
*ʱ�临�Ӷȣ�O(n^2)
*�ռ临�Ӷȣ�O(1)
*�ȶ�
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
----------------------��ѡ������-----------------------
*ʱ�临�Ӷȣ�O(n^2)
*�ռ临�Ӷȣ�O(1)
*�ȶ�
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
---------------------ֱ�Ӳ�������------------------------
*ʱ�临�Ӷȣ�O(n^2)
*�ռ临�Ӷȣ�O(1)
*�ȶ�
---------------------------------------------------------*/
void insertSort(int* arr,int length)
{
	for(int i=1;i<length;i++)
	{
		if(arr[i]<arr[i-1])
		{
			int temp = arr[i];
			int j;
			for(j=i-1;arr[j]>temp;j--)
				arr[j+1] = arr[j];
			arr[j+1] = temp;
		}
	}
}


/**
----------------------ϣ������---------------------------
*ʱ�临�Ӷȣ�O(nlogn)~O(n^2)
*�ռ临�Ӷȣ�O(1)
*���ȶ�
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
----------------------������------------------------------
*ʱ�临�Ӷȣ�������O(n)���ؽ���O(nlogn)���ܸ��Ӷ�ΪO(nlogn)
*�ռ临�Ӷȣ�O(1)
*���ȶ�
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
��֪arr[s-1..e-1]��arr[s-1]�⣬�����϶ѵĶ��壬
��׼arr[s-1]��ʹarr[s-1..e-1]��Ϊһ���󶥶�
*/
void heapAdjust(int* arr, int s, int e)
{
	int temp = arr[s-1];  //��Ҫ��׼�ĸ��ڵ�
	for(int j=2*s;j<=e;j*=2)
	{
		if(j<e && arr[j-1]<arr[j]) //���Ӻ��Һ����ĸ��ϴ�,�ش�����±Ƚ�
			++j;
		if(temp>=arr[j-1])
			break;
		arr[s-1] = arr[j-1];
		s = j;
	}
	arr[s-1] = temp;
}



/**
*--------------�鲢���򣬵ݹ�ʵ��------------------
*ʱ�临�Ӷȣ�logn�ι鲢��ÿ�ι鲢����n��O(nlogn)
*�ռ临�Ӷ�: �鲢�����еĴ洢�ռ�O(n)+�ݹ����O(logn)
*�ȶ�
**/
void mergeSort(int* arr, int length)
{
	void mSort(int* arr1, int* arr2, int s, int e);

	mSort(arr,arr,0,length-1);
}

//��arr1[s..e]�鲢����Ϊarr2[s..e]
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

//�������arr1[s..m]��arr1[m+1..e]�鲢�������arr2[s..e]
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
*--------------�鲢���򣬷ǵݹ�ʵ��------------------
*ʱ�临�Ӷȣ�O(nlogn)
*�ռ临�Ӷ�: �鲢�����еĴ洢�ռ�O(n)
*�ȶ�
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

//��arr1������Ϊs�������������鲢��arr2��
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
*--------------��������------------------
*ʱ�临�Ӷȣ�ƽ�������O(nlogn)���O(n^2)
*�ռ临�Ӷ�: O(logn)~O(n)
*���ȶ�
**/
void quickSort(int *arr, int length)
{
	void qSort(int *arr, int low, int high);

	qSort(arr, 0, length-1);
}

//�������е�������arr[low..high]����������
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

//�����������ӱ�ļ�¼��ʹ��Ŧ��¼��λ����������λ��
int partition(int *arr, int low, int high)
{
	int pivotkey;
	pivotkey = arr[low];//�������еĵ�һ����¼��Ϊ��Ŧ��¼
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
