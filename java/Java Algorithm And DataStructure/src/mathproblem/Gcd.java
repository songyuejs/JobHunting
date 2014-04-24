package mathproblem;

//�����������Լ���ļ��㷽��
public class Gcd {

	public static void main(String[] args) {
		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd : " + gcd(100000000, 500000000));
			}
		}).start();

		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd1 : " + gcd1(100000000, 500000000));
			}
		}).start();

		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd2 : " + gcd2(100000000, 500000000));
			}
		}).start();
		
		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd3 : " + gcd3(100000000, 500000000));
			}
		}).start();
	}

	/**
	 * @author Administrator
	 * @return ����m��n�����Լ�� ʱ�临�Ӷ�Ϊ��m>=n�Ļ���O(n)
	 */
	public static int gcd(int m, int n) {
		int gcd = 1;
		for (int k = 2; k <= m && k <= n; k++) {
			if (m % k == 0 && n % k == 0)
				gcd = k;
		}
		return gcd;
	}

	/**
	 * @author Administrator
	 * @param m
	 * @param n
	 * @return gcd(m,n) ʱ�临�Ӷȷ�������n��ʼѭ��������ҵ����˳�ѭ����������Ȼ��O(n)
	 */
	public static int gcd1(int m, int n) {
		int gcd = 1;
		if (m >= n) {
			for (int k = n; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		} else {
			for (int k = m; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		}
		return gcd;
	}

	/**
	 * @author Administrator
	 * @param m
	 * @param n
	 * @return ʱ�临�Ӷȷ�����m��n�����Լ�������ܴ���n/2��m/2
	 */
	public static int gcd2(int m, int n) {
		int gcd = 1;
		if (m >= n) {
			if (m % n == 0)
				return n;

			for (int k = n / 2; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		} else {
			if (n % m == 0)
				return m;

			for (int k = m / 2; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		}
		return gcd;
	}

	/**
	 * @author Administrator
	 * @param m
	 * @param n
	 * @return ʹ�õݹ���������Լ���ļ���
	 * ʱ�临�Ӷȣ�O(logn)
	 */
	public static int gcd3(int m, int n) {
		if (m % n == 0)
			return n;
		else
			return gcd(n, m % n);
	}

}
