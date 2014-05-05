package string;

/**
 * @description �ַ���ƥ������
 * @author Administrator
 */
public class StringMatcher {

	public static void main(String[] args) {
		String source = "goodgoogle";
		String test = "google";
		System.out.println(index_BF(source, test, 0));
		
	}

	// ��������ַ���ƥ���㷨����ͷ��ʼƥ��.
	public static int index_BF(String s, String t, int pos) {
		char[] source = s.toCharArray();
		char[] test = t.toCharArray();
		int s_Length = source.length;
		int t_Length = test.length;
		int i, j;
		for (i = pos; i <= s_Length - t_Length; i++) {
			j = 0;
			while (j < t_Length && source[i + j] == test[j]) {
				j++;
			}
			if (j == t_Length) {
				return i;
			}
		}
		return -1;
	}
	
	//KMP
	public static int index_KMP(String s,String t,int pos){
		//TODO
		return -1;
	}
}
