import java.util.Scanner;

public class Program
{
	private static int sumOfDigits(int nb)
	{
		int sum = 0;
		while (nb != 0)
		{
			int res = nb % 10;
			sum += res;
			nb /= 10;
		}
		return sum;
	}

	private static boolean isPrime(int nb)
	{
		if (nb <= 1)
			return false;
		int i = 2;
		while (i * i <= nb)
		{
			if (nb % i == 0)
				return false;
			i++;
		}
		return true;
	}

	public static void	main(String arg[])
	{
		Scanner scanner = new Scanner(System.in);
		int count = 0;
		int nb;
		while ((nb = scanner.nextInt()) != 42)
		{
			if (isPrime(sumOfDigits(nb)))
				count++;
		}
		System.out.println(count);
		System.exit(0);
	}
};