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
		if (time <= 0)
			throw new RuntimeException("Usage: time must be greate than 0");
		return time;
	}

	public static void main(String []args)
	{
		try
		{
			Integer time = parseInput(args);
			SynchronizationThread egg = new SynchronizationThread("Egg", time);
			SynchronizationThread hen = new SynchronizationThread("Hen", time);
			egg.start();
			hen.start();

			egg.join();  // Wait for egg to finish
            hen.join();  // Wait for hen to finish
			while (time > 0)
			{
				System.out.println("Human");
				Thread.sleep(50);
				time--;
			}

		}
		catch (Exception e)
		{
			System.err.println("Error: " + e.getMessage());
		}
	}
}