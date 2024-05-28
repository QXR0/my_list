#include"List.h"


//void test_list1()
//{
//	my_list::List<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	my_list::iterator<int> it = l.begin();
//	my_list::List<int>::iterator1 it2 = l.begin();
//	while (it2 != l.end())
//	{
//		std::cout << *it2 << " ";
//		++it2;
//	}
//}
//void test_list2()
//{
//	my_list::List<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.print();
//	l.pop_back();
//	l.pop_back();
//	l.print();
//	l.push_front(100);
//	l.pop_front();
//	l.print();
//	//my_list::iterator<int> pos = std::find(l.begin(), l.end(), 1);
//	l.insert(l.begin(), 1000);
//	l.print();
//	l.erase(++l.begin());
//	l.print();
//	cout << l.empoty();
//
//}
//
//void test_list3()
//{
//	my_list::List<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	l.print();
//	l.erase(--l.end());
//	l.print();
//	l.reverse();
//	l.print();
//	cout << l.size();
//
//}
//
//void test_list4()
//{
//	my_list::List<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	my_list::iterator<int>it = l.begin();
//	//it++;
//	it--;
//	it--;
//	cout<<*it;
//}


void test_list1()
{
	my_list::List<char> l;

	/*l.push_back(1);
	l.push_back(2);
	l.push_back(3);*/
	l.push_back('a');
	l.push_back('b');
	l.push_back('c');
	l.push_front('x');
	l.push_front('x');
	l.erase(l.begin());
	l.erase(l.begin());
	l.insert(l.begin(),'d');
	l.reverse();
	l.reverse();
	l.reverse();
	my_list::List<char>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it<<" ";
		it++;


	}
	cout << endl;
	//l.print();
}

void test_list2()
{
 	my_list::List<char> l;
	l.push_back('a');
	l.push_back('b');
	//my_list::List<char>::const_iterator it = l.begin();
	
	l.print();

}

void test_list3()
{
	my_list::List<char> l1;
	l1.push_back('a');
	l1.push_back('b');
	my_list::List<char> l2(l1);
	//l2.print();
	my_list::List<char> l3(5, 'a');
	l3 = l2;
	//l3.print();
	my_list::List<char> l4(l3.begin(), l3.end());
	l4.clear();
	//l4.pop_back();
	l4.push_back('a');
	l4.print();
}


int main()
{
	//test_list3();
	//it = it1;
	//printf("%p\n%p",it, it1);
	test_list3();

	

	return 0;
}