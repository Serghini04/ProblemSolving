import java.util.UUID;

import javax.swing.text.Style;

import java.util.Scanner;

public class TransactionsService
{
	private	UsersList users;
	private TransactionsList unpairedTransactions;

	public TransactionsService()
	{
		users = new UsersArrayList();
		unpairedTransactions = new TransactionsLinkedList();
	}

	private void putError(Scanner s) {
		System.err.println("Invalid Input.");
		if (s.hasNext())
			s.next();  // Consume invalid input only if available
		else
			System.exit(0);  // Gracefully exit instead of crashing
	}
	
	
	public static class IllegalTransactionException extends RuntimeException
	{
		public IllegalTransactionException()
		{
			super("Illegal Transaction");
		}
	}

	public UsersList getUsers()
	{
		return users;
	}

	public void addUser(Scanner s)
	{
		System.out.println("Enter a user name and a balance :");
		if (!s.hasNext())
		{
			putError(s);
			return ;
		}
		String name = s.next();
		if (!s.hasNextInt())
		{
			putError(s);
			return ;
		}
		int balance = s.nextInt();
		User user = new User(name, balance);
		users.addUser(user);
		System.out.println("User with id = " + user.getId() + " is added");
	}

	public void getUserBalance(Scanner s)
	{
		System.out.println("Enter a user ID :");
		if (!s.hasNextInt())
		{
			putError(s);
			return ;
		}
		int id = s.nextInt();
		try
		{
			User user = users.findUserById(id);
			System.out.println(user.getName() + " - " + user.getBalance());
		}
		catch (Exception e)
		{
			System.err.println("Invalid Id.");
		}
	}

	public	void transferAmount(Scanner s)
	{
		// Enter a sender ID, a recipient ID, and a transfer amount
		int senderId = 0, recipienterId = 0, amount = 0;
		System.out.println("Enter a sender ID, a recipient ID, and a transfer amount :");
		if (!s.hasNextInt())
		{
			putError(s);
			return ;
		}
		senderId = Integer.parseInt(s.next());
		if (!s.hasNextInt())
		{
			putError(s);
			return ;
		}
		recipienterId = Integer.parseInt(s.next());
		if (!s.hasNextInt())
		{
			putError(s);
			return ;
		}
		amount = Integer.parseInt(s.next());
		try
		{
			User sender = users.findUserById(senderId);
			User recipienter = users.findUserById(recipienterId);
			if (amount < 0 || sender.getBalance() - amount < 0)
				throw new IllegalTransactionException();
			UUID transactionId = UUID.randomUUID();
			sender.getTransactionsList().addTransaction(new Transaction(sender, recipienter, -amount, transactionId));
			sender.setBalance(sender.getBalance()  - amount);
			recipienter.getTransactionsList().addTransaction(new Transaction(recipienter, sender, amount, transactionId));
			recipienter.setBalance(recipienter.getBalance()  + amount);
		}
		catch(Exception e)
		{
			System.err.println("Error : " + e.getMessage());
			return ;
		}
		System.out.println("The transfer is completed");
	}

	public void	findUserTransactions(Scanner s)
	{
		int userID;
		System.out.println("Enter a user ID :");
		if (!s.hasNextInt())
		{
			putError(s);
			return ;
		}
		userID = Integer.parseInt(s.next());
		try
		{
			User	user = users.findUserById(userID);
			Transaction[] tr = user.getTransactionsList().toArray();
			//To Mike(id = 2) -100 with id = cc128842-2e5c-4cca-a44c-7829f53fc31
			for (int i = 0; i < tr.length; i++)
			{
				System.out.println("To (" + tr[i].getRecipient().getName() + " = " + tr[i].getRecipient().getId() + ") " + tr[i].getAmount() + " with id = " + tr[i].getId());
			}
		}
		catch(Exception e)
		{
			System.err.println("Error : " + e.getMessage());
		}
	}

	public void	removedUserTransaction(Scanner s)
	{
		int userId;
		UUID transactionId;
		System.out.println("Enter a user ID and a transfer ID :");
		if (!s.hasNextInt())
		{
			putError(s);
			return ;
		}
		userId = Integer.parseInt(s.next());
		if (!s.hasNext())
		{
			putError(s);
			return ;
		}
		transactionId = UUID.fromString(s.next());
		try
		{
			User user = users.findUserById(userId);
			Transaction toDelete = user.getTransactionsList().getTransactionById(transactionId);
			try
			{
				this.unpairedTransactions.removeTransaction(transactionId);
			}
			catch (Exception e)
			{
				User secondUser = (userId == toDelete.getRecipient().getId())
						? users.findUserByIndex(toDelete.getSender().getId())
						: users.findUserByIndex(toDelete.getRecipient().getId());
				Transaction toSave = ((TransactionsLinkedList) secondUser.getTransactionsList())
						.getTransactionById(transactionId);
				this.unpairedTransactions.addTransaction(toSave);
			}
			user.getTransactionsList().removeTransaction(transactionId);
		}
		catch(Exception e)
		{
			System.err.println("Error : " + e.getMessage());
		}
	}

	// Add Menu functionality : ...

	public Transaction[] getUnpairedTransactions() {
		return unpairedTransactions.toArray();
	}

}
