
public class Pragram
{
	public static void main(String []arg)
	{
		User user1 = new User("Test 1", 5888);
		User user2 = new User("Test 2", 55);
		Transaction transaction = new Transaction(user1, user2, 55);
		
		System.out.println(user1);
		System.out.println(user2);
		
		if (!transaction.startTransaction())
			System.out.println("Transaction failed.");
		else
		{
			System.out.println(transaction);
			System.out.println("Transaction Success.");
		}
	}
}
