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
	//3/ Protected: Accessible Inside the class and all classes inherits class.
	protected:
		int	Id()
		{
			return (_id);
		}
		string	Name()
		{
			return (_name);
		}
		string Email()
		{
			return (_email);
		}
		string	Phone()
		{
			return (_phone);
		}
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
			cout << "ID     :  " << _id << endl;
			cout << "Name   :  " << _name << endl;
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

//							Inheritance
// Sub Class/Derived Class	==Inherits==>	Sup Class/Base Class
class clsEmployee : public clsPerson // public (Visibility Mode).
//					 Visibility Mode
//	  members : Private     |  Prptected   |  Public
// public =>  inaccessible  |  protected   |  private
// private => inaccessible  |  private     |  private
// protected => inaccessible|  protected   |  protected

{
	private :
		string	_Title;
		string	_Department;
		float	_Salary;
	public :
		clsEmployee(int id, string name, string email, string phone, \
		string title, string department, float salary) : clsPerson(id, name, email, phone)
		{
			_Title = title;
			_Department = department;
			_Salary = salary;
		}
		// Function Overriding. || If a function with the same name is created in a derived class, this function overrides the one in the base class.
		void	PrintInfo()
		{
			cout << "Info :\n";
			cout << "=============================\n";
			cout << "  ID         :  " << Id() << endl;
			cout << "  Name       :  " << Name() << endl;
			cout << "  Email      :  " << Email() << endl;
			cout << "  Phone      :  " << Phone() << endl;
			cout << "  Title      :  " << _Title << endl;
			cout << "  Department :  " << _Department << endl;
			cout << "  Salary     :  " << _Salary << endl;
			cout << "=============================\n";
		}
};
//.
// <>
//<<>>
// <>
int	main()
{
	clsEmployee data(66, "Mehdi", "my@gmail.com", "065326434", "CEO", "Programing", 5000);
	data.SetName("Mehdi");
	data.SetEmail("my@gmail.com");
	data.SetPhone("0518418415");
	data.PrintInfo();
	return (0);
}