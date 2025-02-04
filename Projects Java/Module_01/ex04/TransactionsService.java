import java.util.UUID;

public class TransactionsService
{
	private	UsersList users;
	private TransactionsList transactions;
	
	public TransactionsService()
	{
		
	}
	
	public static class IllegalTransactionException extends RuntimeException
	{
		public IllegalTransactionException()
		{
			super("Illegal Transaction");
		}
	}

	public void addUser(String name, int balance)
	{
		users.addUser(new User(name, balance));
	}

	public int getUserBalance(int id)
	{
		return users.findUserById(id).balance;
	}

	public	void transferAmount(int senderId, int recipienterId, int amount)
	{
		User sender = users.findUserById(senderId);
		User recipienter = users.findUserById(recipienterId);
		if (amount < 0 || sender.getBalance() - amount < 0)
	 		throw new IllegalTransactionException();
		UUID transactionId = UUID.randomUUID();
		sender.geTransactionsList().addTransaction(new Transaction(sender, recipienter, -amount, transactionId));
		sender.setBalance(sender.getBalance()  - amount);
		recipienter.geTransactionsList().addTransaction(new Transaction(recipienter, sender, amount, transactionId));
		recipienter.setBalance(recipienter.getBalance()  + amount);
	}
	
}
