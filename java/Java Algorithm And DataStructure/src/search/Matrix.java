package search;

import static net.mindview.util.Print.*;

public class Matrix {

	public static void main(String[] args) {
		int[][] n = {{1,2,8,9,},{2,4,9,12,},{4,7,10,13,},{6,8,11,15,},};
		print(find(n, 15));
	}

	//�ڶ�ά�����в���ĳ��Ԫ��
	//�Ⱦ���������ά�����ÿ�д������������У�û�д��ϵ�����������.
	//���ҹ����У�ÿ�������Ͻǵ�������num���бȽϣ�������ȥ�����У���С��ȥ������.
	public static boolean find(int[][] n, int num) {
		boolean found = false;
		int rows = n.length;
		int columns = n[0].length;

		if (n != null && rows > 0 && columns > 0) {
			int row = 0;
			int column = columns - 1;
			while (row < rows && column < columns) {
				if (n[row][column] == num) {
					found = true;
					print("�ҵ������ڵ�" + (row+1) + "�У���" + (column+1) + "��");
					break;
				} else if (n[row][column] > num)
					--column;
				else
					++row;
			}
		}
		return found;
	}

}
