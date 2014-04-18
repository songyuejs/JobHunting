package sort;

import java.util.Arrays;

import static net.mindview.util.Print.*;

public class AllSortMethod {

	public static void main(String[] args) {
		int[] n = { 9, 1, 5, 8, };
		System.out.println(Arrays.toString(n));

//		BubbleSortMethod.bubbleSort0(n);
//		SelectSortMethod.selectSort(n);
//		InsertSortMethod.insertSort(n);
//		ShellSortMethod.shellSort(n);
//		MergeSortMethod.mergerSort(n);
		HeapSortMethod.heapSort(n);
	}
}

class SortUtils {
	public static void swap(int[] n, int i, int j) {
		int temp = n[i];
		n[i] = n[j];
		n[j] = temp;
	}
}

// ð������
class BubbleSortMethod {
	// first bubbleSort()
	public static void bubbleSort0(int[] n) {
		for (int i = 0; i < n.length; i++) {
			for (int j = i + 1; j < n.length; j++) {
				if (n[i] > n[j]) {
					SortUtils.swap(n, i, j);
				}
			}
		}
		System.out.println(Arrays.toString(n));
	}

	// second bubbleSort(),���ڵ�ð�������㷨
	public static void bubbleSort1(int[] n) {
		for (int i = 0; i < n.length; i++) {
			for (int j = n.length - 2; j >= i; j--) {
				if (n[j] > n[j + 1]) {
					SortUtils.swap(n, j, j + 1);
				}
			}
		}
		System.out.println(Arrays.toString(n));
	}

	// third bubbleSort(),ð��������Ż�
	public static void bubbleSort2(int[] n) {
		boolean flag = true;
		for (int i = 0; i < n.length && flag; i++) {
			flag = false;
			for (int j = n.length - 2; j >= i; j--) {
				if (n[j] > n[j + 1]) {
					SortUtils.swap(n, j, j + 1);
					flag = true;
				}
			}
		}
		System.out.println(Arrays.toString(n));
	}
}

// ��ѡ������
class SelectSortMethod {
	/*
	 * �㷨ʱ�临�Ӷȷ�������������û���������������бȽϵĴ�������һ���ģ�һ����Ҫ���бȽϴ�����1+2+3+...+(n-1)=n*(n-1)/2
	 * ������������õ������0�Σ���������n-1�ˣ������յ�����ʱ���ǱȽϴ������Ͻ����������ܺ������ʱ�临�Ӷ���O(n^2)
	 */
	public static void selectSort(int[] n) {
		int min;
		for (int i = 0; i < n.length; i++) {
			min = i;
			for (int j = i + 1; j < n.length; j++) {
				if (n[min] > n[j]) {
					min = j;
				}
			}
			if (i != min) {
				SortUtils.swap(n, i, min);
			}
		}
		System.out.println(Arrays.toString(n));
	}
}

// ֱ�Ӳ�������
class InsertSortMethod {
	public static void insertSort(int[] n) {
		int i, j, key;
		for (i = 1; i < n.length; i++) {
			if (n[i] < n[i - 1]) {
				key = n[i];
				for (j = i - 1; j > 0 && n[j] > key; j--) {
					n[j + 1] = n[j];
				}
				n[j + 1] = key;
			}
		}
		System.out.println(Arrays.toString(n));
	}
}

// shell����
class ShellSortMethod {
	public static void shellSort(int[] n) {
		int increment = n.length;
		int i, j;
		int key;
		do {
			// �ؼ�������������е�ѡȡ����
			increment = increment / 3 + 1;
			for (i = increment; i < n.length; i++) {
				if (n[i] < n[i - increment]) {
					key = n[i];
					for (j = i - increment; j >= 0 && key < n[j]; j -= increment) {
						n[j + increment] = n[j];
					}
					n[j + increment] = key;
				}
			}
		} while (increment > 1);
		System.out.println(Arrays.toString(n));
	}
}

// ������
class HeapSortMethod {
	private static void heapAdjust(int[] n, int i, int size) {
		// �ѵ���
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int max = i;
		if (i <= size / 2 - 1) {
			if (lchild < size && n[lchild] > n[max]) {
				max = lchild;
			}
			if (rchild < size && n[rchild] > n[max]) {
				max = rchild;
			}
			if (max != i) {
				SortUtils.swap(n, i, max);
				heapAdjust(n, max, size);
			}
		}
	}

	private static void buildHeap(int[] n, int size) {
		for (int i = size / 2 - 1; i >= 0; i--) {
			heapAdjust(n, i, size);
		}
	}

	public static void heapSort(int[] n) {
		int size = n.length;
		buildHeap(n, size);

		print("-----------��ʼ����---------------");
		print(Arrays.toString(n));
		print("-------------------------------");

		for (int i = size - 1; i > 0; i--) {
			SortUtils.swap(n, 0, i);
			print(Arrays.toString(n));
			heapAdjust(n, 0, i);

			print(Arrays.toString(n));
			print("-------------------------------");

		}
		System.out.println(Arrays.toString(n));
	}
}

// �鲢����
class MergeSortMethod {
	private static void partition(int[] array, int from, int end) {
		if (from < end) {
			int mid = (from + end) / 2;
			partition(array, from, mid);
			partition(array, mid + 1, end);
			merge(array, from, end, mid);
		}
	}

	private static void merge(int[] array, int from, int end, int mid) {
		int[] tmpArray = new int[10];
		int tmpArrayIndex = 0;
		int part1ArrayIndex = from;
		int part2ArrayIndex = mid + 1;
		while ((part1ArrayIndex <= mid) && (part2ArrayIndex <= end)) {
			if (array[part1ArrayIndex] < array[part2ArrayIndex]) {
				tmpArray[tmpArrayIndex++] = array[part1ArrayIndex++];
			} else {
				tmpArray[tmpArrayIndex++] = array[part2ArrayIndex++];
			}
		}
		while (part1ArrayIndex <= mid) {
			tmpArray[tmpArrayIndex++] = array[part1ArrayIndex++];
		}
		while (part2ArrayIndex <= end) {
			tmpArray[tmpArrayIndex++] = array[part2ArrayIndex++];
		}
		System.arraycopy(tmpArray, 0, array, from, end - from + 1);
	}

	public static void mergerSort(int[] n) {
		partition(n, 0, n.length - 1);
		System.out.println(Arrays.toString(n));
	}
}

// ��������
class QuickSortMethod {
	public static void quickSort(int[] n) {
		qSort(n, 0, n.length - 1);
		System.out.println(Arrays.toString(n));
	}

	private static void qSort(int[] n, int low, int high) {
		int pivot;
		if (low < high) {
			pivot = quickSortPartition(n, low, high);
			qSort(n, low, pivot - 1);
			qSort(n, pivot + 1, high);
		}
	}

	private static int quickSortPartition(int[] n, int low, int high) {
		int pivotkey;
		pivotkey = n[low];
		while (low < high) {
			while (low < high && n[high] >= pivotkey) {
				high--;
			}
			SortUtils.swap(n, low, high);
			while (low < high && n[low] <= pivotkey) {
				low++;
			}
			SortUtils.swap(n, low, high);
		}
		return low;
	}
}