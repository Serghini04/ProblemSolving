#include <iostream>
#include <string>
#include <vector>

using namespace std;

class	clsPerson
{
	private:
		int	_id;
		string	_name;
		string	_email;
		string	_phone;
	public:
		void	SetName(string	name)
		{
			_name = name;
		}
		void SetEmail(string email)
		{
			_email = email;
		}
		void	SetPhone(string phone)
		{
			_phone = phone;
		}
		clsPerson(int id, string name, string email, string phone)
		{
			_id = id;
			_name = name;
			_email = email;
			_phone = phone;
		}
		void	PrintInfo()
		{
			cout << "Info :\n";
			cout << "\n=============================\n";
			cout << "ID	  :  " << _id << endl;
			cout << "Name :  " << _name << endl;
			cout << "Email  :  " << _email << endl;
			cout << "Phone  :  " << _phone << endl;
			cout << "\n=============================\n";
		}
		void	SendEmail(string subject, string body)
		{
			cout << "\nThe following messange sent successfully to email : " << _email << endl;
			cout << "Subject : " << subject << endl;
			cout << "Body : " << body << endl;
		}
		void	SendSMS(string sms)
		{
			cout << "The following SMS sent successfully to phone  : " << _name;
			cout << "\n" << sms << endl;
		}
};

int	main()
{
	clsPerson	data(10, "Mehdi", "my@gmail.com", "0632643881");
	data.PrintInfo();
	data.SendEmail("hi", "how are you?");
	data.SendSMS("how are you?");
	return (0);
}