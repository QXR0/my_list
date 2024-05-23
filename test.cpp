#include"List.h"
#include<list>

void test_list1()
{
	my_list::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(3);
	l.push_back(3);
	my_list::iterator<int> it = l.begin();
	while (it != l.end())
	{
		std::cout << *it << " ";
		++it;
	}
}
void test_list2()
{
	my_list::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.print();
	l.pop_back();
	l.pop_back();
	l.print();
	l.push_front(100);
	l.pop_front();
	l.print();
	//my_list::iterator<int> pos = std::find(l.begin(), l.end(), 1);
	l.insert(l.begin(), 1000);
	l.print();
	l.erase(++l.begin());
	l.print();
	cout << l.empoty();

}

void test_list3()
{
	my_list::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.print();
	l.erase(--l.end());
	l.print();
	l.reverse();
	l.print();
	cout << l.size();

}

void test_list4()
{
	my_list::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	my_list::iterator<int>it = l.begin();
	//it++;
	it--;
	it--;
	cout<<*it;
}


int main()
{
	//test_list3();
	//it = it1;
	//printf("%p\n%p",it, it1);
	test_list4();

	return 0;
}