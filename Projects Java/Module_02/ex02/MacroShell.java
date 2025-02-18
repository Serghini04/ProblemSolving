import java.util.Scanner;
import java.io.File;

public class MacroShell
{
	private final File path;

	public MacroShell(String arg)
	{
		if (!arg.startsWith("--current-folder="))
			throw new RuntimeException("Usage: java Program --current-folder=<Path>");
		this.path = new File(arg.substring("--current-folder=".length()));
		if (!this.path.exists() || !this.path.isDirectory())
			throw new RuntimeException("Usage: invalid Path");
	}

	private void	lsCmd()
	{
		File[] files = this.path.listFiles();

    	if (files != null) {
			for (File file : files) {
                System.out.printf("%-20s %10.2f KB\n", file.getName(), file.length() / 1024.0);
            }
        }
		else
            System.out.println("Failed to list files.");
	}

	private void cdCmd()
	{

	}
	public void startReadInput()
	{
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNextLine())
		{
			String []line = scanner.nextLine().trim().split("\\s+");
			switch (line[0]) {
				case "ls":
					lsCmd();
					break;
					cdCmd();
				case "cd":

					break;
				
				case "mv":

					break;

				default:
					System.out.println("Command not found : " + line[0]);
					break;
			}
		}

	}
}
