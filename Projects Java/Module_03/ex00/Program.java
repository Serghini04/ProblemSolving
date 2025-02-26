

public class Program
{

	private static Integer parseInput(String []args)
	{
		Integer	time;

		if (args.length != 1)
			throw new RuntimeException("Usage: java Program --count={times}");
		if (!args[0].startsWith("--count="))
			throw new RuntimeException("Usage: java Program --count={times}");

		time = Integer.parseInt(args[0].substring(args[0].indexOf('=') + 1));
		return time;
	}

	public static void main(String []args)
	{
		// try
		// {
			Integer time = parseInput(args);
			SynchronizationThread egg = new SynchronizationThread("Egg");
			SynchronizationThread hen = new SynchronizationThread("Hen");

			while (time > 0)
			{
				egg.run();
				hen.run();
				time--;
			}
		// }
		// catch (Exception e)
		// {
		// 	System.err.println("Error: " + e.getMessage());
		// }
	}
}