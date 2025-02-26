public class SynchronizationThread extends Thread {
	
	private String threadName;

	public SynchronizationThread(String name)
	{
		this.threadName = name;
	}

	public void	run()
	{
		System.out.println(threadName);
	}

}
