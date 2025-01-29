package Module_01.ex00;

public class Pragram
{
	public static void main(String []arg)
	{
		User user1 = new User("Test 1", 5888);
		User user2 = new User("Test 2", 55);
		Transaction transaction = new Transaction(user1, user2, "debit", 55);
		
		if (!transaction.startTransaction())
			System.out.println("Transaction failed.");
		else
			System.out.println("Transaction Success.");
	}
}
