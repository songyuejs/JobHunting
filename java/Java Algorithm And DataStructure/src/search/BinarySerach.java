package search;

/**
 * @author Administrator
 * �۰���ҵ�ʵ�֣�ʱ�临�Ӷ�O(logn)
 * ����һ��ʵ���ǲ�ֵ���ң�����ÿ�ζ��۰룬
 * �۰�����У�middle = (low + high ) / 2 = low + 1/2 *(high - low)
 * ������Ĺ�ʽ�滻Ϊmiddle = low + (key - a[low]) / (a[high] - a[low]) *(high-low)
 * ������������йؼ��ֲַ��ȽϾ��ȣ�ʹ�ò�ֵ���ұȽ��ʺ�.
 */
public class BinarySerach {

	// suppose input is an ascending sort array.
	// recursion method.
	public static boolean binarySerach(int[] input, int start, int end, int i) {
		boolean flag = false;
		if (end >= start) {
			int middle = (start + end) / 2;
			if (input[middle] > i) {
				flag = binarySerach(input, start, middle - 1, i);
			} else if (input[middle] < i) {
				flag = binarySerach(input, middle + 1, end, i);
			} else {
				flag = true;
			}
		}
		return flag;
	}

	// recursion method.
	public static int binarySerachDestination(int[] input, int start, int end,
			int i) {
		if (end >= start) {
			int middle = (start + end) / 2;
			if (input[middle] > i) {
				return binarySerachDestination(input, start, middle - 1, i);
			} else if (input[middle] < i) {
				return binarySerachDestination(input, middle + 1, end, i);
			} else {
				return middle;
			}
		}
		return -1;
	}

	// non_recursion method.
	public static boolean binarySearch(int[] input, int des) {
		int low = 0;
		int high = input.length - 1;
		boolean flag = false;
		while (low <= high) {
			int middle = low + ((high - low) >> 1);
			if (des == input[middle]) {
				flag = true;
				break;// 找到跳出循环
			} else if (des < input[middle]) {
				high = middle - 1;
			} else {
				low = middle + 1;
			}
		}
		return flag;
	}

	// non_recursion method.
	public static int binarySearchDestination(int[] input, int des) {
		int low = 0;
		int high = input.length - 1;
		while (low <= high) {
			int middle = low + ((high - low) >> 1);
			if (des == input[middle]) {
				return middle;
			} else if (des < input[middle]) {
				high = middle - 1;
			} else {
				low = middle + 1;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		int[] input = { 1, 2, 3, 4, 5, 6, 7, 8, 9, };
		System.out.println(binarySerach(input, 0, input.length - 1, 4));
		System.out.println(binarySerachDestination(input, 0, input.length - 1,
				5));
		System.out.println(binarySearch(input, 4));
		System.out.println(binarySearchDestination(input, 4));
	}
}