import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Map;

import javax.management.RuntimeErrorException;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileSignatures {

	private final String signaturesFile;
	private final Map<String, String> map;
	private FileOutputStream res;

	public FileSignatures()
	{
		map = new HashMap<>();
		signaturesFile = "signatures.txt";
		try
		{
			res = new FileOutputStream("result.txt");
		}
		catch (IOException e)
		{
			System.err.println(e.getMessage());
			System.exit(1);
		}
	}

	private boolean	getTypeOfExection(String line)
	{
		try
		{
			if (map.containsKey(line))
				res.write((map.get(line) + "\n").getBytes());
			for ()
		}
		catch(IOException e)
		{
			System.err.println(e.getMessage());
			System.exit(1);
		}
		return true;
	}

	public void	readSignaturesFile()
	{
		try {
			FileInputStream	fd = new FileInputStream( "signatures.txt");
		
			Scanner scanner = new Scanner(fd);
			while (scanner.hasNextLine())
			{
				String line = scanner.nextLine().trim().replaceAll("\\s+", "");
				int pos = line.indexOf(',');
				if (pos == -1)
					throw new RuntimeException("Invalid Signature => (" + line + ").");
				map.put(line.substring(pos + 1), line.substring(0, pos));
			}
		}
		catch (IOException e) {
			System.err.println(e.getMessage());
			System.exit(1);
		}
	}

	private String	processedFile(String line)
	{
		String statusMsg = "PROCESSED";
		try (FileInputStream file = new FileInputStream(line)) 
		{
			byte []reads = new byte[8];
			if (file.read(reads) == -1)
				return "UNDEFINED";
			getTypeOfExection(line);
		}
		catch (IOException e)
		{
			return "NOTEXITS";
		}
		return statusMsg;
	}

	public void	readUserInput()
	{
		try (Scanner scanner = new Scanner(System.in))
		{
			while (scanner.hasNextLine())
			{
				String line = scanner.nextLine().trim();
				if (line.equals("42"))
					break ;
				System.out.println(processedFile(line));
			}
		}
		catch (Exception e)
		{
			System.err.println(e.getMessage());
		}
	}
}
