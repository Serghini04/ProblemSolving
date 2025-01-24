import java.util.Scanner;

public class Program
{
	public static void main(String args[])	
	{
		Scanner scanner = new Scanner(System.in);
		int nb = scanner.nextInt();
		scanner.close();
		if (nb <= 1)
		{
			System.err.println("IllegalArgument");
			System.exit(-1);
		}
		int i = 2;
		while (i * i <= nb)
		{
			if (nb % i == 0)
			{
				System.out.println("false " + (i - 1));
				System.exit(-1);
			}
			i++;
		}
		System.out.println("true " + (i - 1));
		System.exit(0);
	}
}
