# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

class RandomizedSet {
	unordered_map<int, int> m;
public:
	bool	is_exist(int val)
	{
		if (m.find(val) != m.end())
			return 1;
		return 0;
	}
    RandomizedSet()
	{
	}
    bool insert(int val)
	{
		if (is_exist(val))
			return 0;
		m[val] = val;
		return true;
    }
    bool remove(int val)
	{
		if (!is_exist(val))
			return 0;
		m.erase(val);
		return 1;
    }
    int getRandom()
	{
		auto u = m.begin();
		std::advance(u, rand() % m.size());
		return u->first;
    }
};
