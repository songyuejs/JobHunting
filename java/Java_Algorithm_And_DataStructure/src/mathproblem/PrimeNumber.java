package mathproblem;

import java.util.Scanner;

//�ҳ����е�����
public class PrimeNumber {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Find all prime numbers <=n ,enter n: ");
		int n = input.nextInt();

		final int NUMBER_PER_LINE = 10;
		int count = 0;
		int number = 2;

		System.out.println("The prime number are: ");

		/*while (number <= n) {
			boolean isPrime = true;

			// �ж�һ�����Ƿ�Ϊ�����Ĺ���
			// ʱ�临�Ӷ�ΪO(n^0.5)
			int squareRoot = (int) Math.sqrt(number);
			for (int divisor = 2; divisor <= squareRoot; divisor++) {
				if (number % divisor == 0) {
					isPrime = false;
					break;
				}
			}*/
		int squareRoot = 1;
		while (number <= n) {
			boolean isPrime = true;

			if (squareRoot * squareRoot < number)
				squareRoot++;
			
			for (int divisor = 2; divisor <= squareRoot; divisor++) {
				if (number % divisor == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime) {
				count++;

				if (count % NUMBER_PER_LINE == 0) {
					System.out.printf("%7d\n", number);
				} else
					System.out.printf("%7d", number);
			}
			number++;
		}
		System.out
				.println("\n" + count + " prime(s) less than n equal to " + n);
	}
}
