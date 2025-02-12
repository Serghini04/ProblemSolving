import java.util.Scanner;

enum Modes
{
	Dev,
	Production	
}

public class Menu
{
	Modes mode;
	TransactionsService transactionsService;
	private Scanner scanner;

	private final int	addUser = 1;
	private final int	viewUserbalances = 2;
	private final int	performTransfer = 3;
	private final int	viewTransactionsUser = 4;
	private final int	removeTransfer = 5;
	private final int	transferValidity = 6;
	private final int	finishExecution = 7;

	public Menu(String input)
	{
		if (input.equals("--profile=dev"))
			mode = Modes.Dev;
		else
			mode = Modes.Production;
		transactionsService = new TransactionsService();
	}

	public void	printMenu()
	{
		System.out.println("1. Add a user");
		System.out.println("2. View user balances");
		System.out.println("3. Perform a transfer");
		System.out.println("4. View all transactions for a specific user");
		if (mode.equals(Modes.Dev))
		{
			System.out.println("5. Dev - remove a transfer by ID");
			System.out.println("6. Dev - check transfer validity");
			System.out.println("7. Finish execution");
		}
		else
			System.out.println("5. Finish execution");
	}

	public void applyInput(int input)
	{
		switch (input)
		{
			case addUser :
				transactionsService.addUser(scanner);
				break ;
			case viewUserbalances :
				transactionsService.getUserBalance(scanner);
				break ;
			case performTransfer :
				transactionsService.transferAmount(scanner);
				break ;
			case viewTransactionsUser :
				transactionsService.findUserTransactions(scanner);
				break ;
			case removeTransfer :
				transactionsService.removedUserTransaction(scanner);
				break ;
			default:
				break;
		}
	}

	public void readInput()
	{
		int input;
		scanner = new Scanner(System.in);

		while (true)
		{
			printMenu();
			if (!scanner.hasNext())
			{
				System.err.println("End of input detected. Exiting...");
				break;
			}
			if (!scanner.hasNextInt())
			{
				System.err.println("Invalid Input");
				scanner.next();
			}
			else
			{
				input = scanner.nextInt();
				if ((mode.equals(Modes.Dev) && input >= 1  && input <= 7) || ((mode.equals(Modes.Production) && input >= 1  && input <= 5)))
					applyInput(input);
				else
					System.err.println("Invalid Input");
			}
			System.out.println("---------------------------------------------------------");
		}
		scanner.close();
	}	

}