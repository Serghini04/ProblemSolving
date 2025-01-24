import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.util.Arrays;
public class Main
{
	public static void	main(String []arg)
	{
		BigDecimal d = new BigDecimal("0.555");
		System.out.println(d);

		System.out.println("\n======================\n");

		int[] s = new int[2];

		s[0] = 4;
		s[1] = 0;
		Arrays.sort(s);
		System.out.println(s[0] + "<>" + s[1]);
	}
}