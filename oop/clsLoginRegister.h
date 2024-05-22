#include "oop.h"

class	clsLoginRegister
{
	string	_Date;
	string	_UserName;
	string	_Password;
	int		_Permissions;

		static clsLoginRegister _convertLineToclsLogin(string line)
		{
			clsLoginRegister User;
			vector<string> arr = clsString::Split(line, ">>>");
			User._Date = arr[0];
			User._UserName = arr[1];
			User._Password = arr[2];
			User._Permissions = stoi(arr[3]);
			return (User);
		}
		static	string _convertclsLoginRegisterToLine(clsLoginRegister data)
		{
			string	res;

			res = data._Date +">>>" +data._UserName + ">>>"+ data._Password +">>>" + to_string(data._Permissions);
			return (res + "\n");
		}
	public:
		static	vector<clsLoginRegister> ReadFileloginRegister( void )
		{
			vector<clsLoginRegister>	res;
			clsLoginRegister			data;
			string	line;
			fstream	fd;

			fd.open("LoginRegister.txt", ios::in);
			if (fd.is_open())
			{
				while (getline(fd, line))
				{
					data = _convertLineToclsLogin(line);
					res.push_back(data);
				}
				fd.close();
			}
			return (res);
		}
		static void SaveLoginRegisterToFile(vector<clsLoginRegister> res)
		{
			fstream	fd;

			fd.open("LoginRegister.txt", ios::out);
			if (fd.is_open())
			{
				for (auto it = res.begin() ; it != res.end() ; it++)
				{
					fd << _convertclsLoginRegisterToLine(*it);
				}
				fd.close();
			}
		}
		static	void	AddUserToLoginRegister(clsUser User)
		{
			clsLoginRegister	Data;

			Data._Date = clsDate::DateToString(clsDate::GetSystemDate()) + " - " + clsDate::getCurrentTime();
			Data._UserName = User.UserName();
			Data._Password = User.Password();
			Data._Permissions = User.Permissions();
			vector<clsLoginRegister> res = ReadFileloginRegister();
			res.push_back(Data);
			SaveLoginRegisterToFile(res);
		}
};


