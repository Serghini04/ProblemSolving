import java.util.Scanner;

public class Program
{
	public static void main(String arg[])
	{
		Scanner scanner = new Scanner(System.in);
		int nb;
		int[] minWeeksGrade = new int[18];
		while ((nb = scanner.nextInt()) != 42)
		{
			if (!scanner.hasNextInt()) {
				System.err.println("IllegalArgument");
				scanner.close();
				System.exit(-1);
			  }
		}
		System.exit(0);
	}
}