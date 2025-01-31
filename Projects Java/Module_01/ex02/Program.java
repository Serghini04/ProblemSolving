public class Program
{
	public static void main(String []arg)
	{
		UsersArrayList	users =  new UsersArrayList(6);
		try
		{
			for (int i = 0; i < 10; i++)
				users.addUser(new User("User Name " + (i + 1), i * 10));
	
		}
		catch (Exception e)
		{
			System.err.println(e);
			System.exit(-1);
		}
		System.exit(0);
	}
}
