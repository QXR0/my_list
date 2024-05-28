#pragma once
#define _CRT_SECURE_NO_WARNINGS 1;
#include<iostream>
#include<algorithm>
#include<assert.h>
using namespace std;

namespace my_list
{
	//链表节点
	template<class T>
	class ListNode
	{
	public:
		typedef T value_type;
		typedef ListNode<T> Node;
		
		
	public:
		value_type _data;
		Node* _pre;
		Node* _next;
		ListNode(const value_type data=value_type())
		{
			_pre = _next = nullptr;
			_data = data;
		}
		
	};
	//迭代器
	template<class Inputinterator,class Ref,class Ptr>
	class iterator
	{
	public:
		typedef Inputinterator value_type;
		typedef ListNode<value_type>*  pNode;
		typedef iterator<value_type, value_type&, value_type*>  Self;
	public:
		pNode _cur;
	public:
		//构造
		iterator()= default;
		iterator(const pNode &p)
		{
			_cur = p;
			
		}
		
		//迭代器 前置++
		Self& operator++()
		{
			
			_cur = _cur->_next;
			return *this;
		}

		//后置++
		Self operator++(int)
		{
			Self tmp;
			tmp._cur = _cur;
			_cur = _cur->_next;
			return tmp;
		}

		//前置--
		Self& operator--()
		{
			_cur = _cur->_pre;
			return *this;
		}
	 
		 
		//后置--
		Self operator--(int)
		{
			Self tmp;
			tmp._cur = _cur;
			_cur = _cur->_pre;
			return tmp;
		}
		//!=
		bool operator!=(const Self it)const
		{
			return _cur != it._cur;
		}

		//*
		Ref operator*()
		{
			return _cur->_data;
		}

		//->
		Ptr operator->()
		{
			return _cur;
		}


		
	};

	//链表
	template<class T>
	class List
	{
	public:
		typedef T value_type;
		typedef iterator<value_type, const value_type&, const value_type*> const_iterator;
		//typedef iterator<value_type, value_type&, value_type*> reverse_iterator;
		typedef iterator<value_type, value_type&, value_type*> iterator;


		typedef ListNode<value_type> Node;
		typedef ListNode<value_type>* pNode;
	public:
		//构造
		List()
		{
			_head = new Node;
			_head->_pre = _head->_next = _head;
			//_head->_data = value();
		}
		//创建长度为n的链表，且里面的数据都一样
		List(int n, value_type data = value_type())
		{
			_head = new Node;
			_head->_pre = _head->_next = _head;
			while (n--)
			{
				push_back(data);
			}
		}

		//用迭代器初始化
		template<class Inputiterator>
		List(Inputiterator first, Inputiterator last)
		{
			_head = new Node;
			_head->_pre = _head->_next = _head;
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//用链表初始化
		List( List<T>& l)
		{
			_head = new Node;
			_head->_pre = _head->_next = _head;
			iterator it = l.begin();
			while (it!=l.end())
			{
				push_back(*it);
				it++;
			}
		}
		//=重载
		List<value_type> operator=( List& l)
		{
			pNode head = _head->_next;
			while (head!=_head)
			{
				pNode tmp = head->_next;
				delete head;
				head = tmp;
			}
			_head = new Node;
			_head->_pre = _head->_next = _head;
			iterator it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				it++;
			}
			return *this;
		}

		//析构
		~List()
		{
			pNode head = _head->_next;
			while (head != _head)
			{
				pNode tmp = head->_next;
				delete head;
				head = tmp;
			}
			delete _head;
		}



		//迭代器
		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}

		
		

		
		//尾插
		void push_back(const value_type& data)const
		{
			pNode newnode=new Node(data);
			newnode->_pre = _head->_pre;
			newnode->_next = _head;
			_head->_pre->_next = newnode;
			_head->_pre = newnode;
		}

		//尾删
		void pop_back()
		{
			assert(_head != _head->_next);
			pNode tail = _head->_pre;
			tail->_pre->_next = _head;
			_head->_pre = tail->_pre;
			delete tail;
		}

		//头插
		void push_front(const value_type &data )
		{
			pNode newhead = new Node(data);
			pNode head = _head->_next;
			newhead->_pre = _head;
			newhead->_next = head;
			head->_pre = newhead;
			_head->_next = newhead;
		}

		//头删
		void pop_front()
		{
			pNode head = _head->_next;
			_head->_next = head->_next;
			head->_next->_pre = _head;
			delete head;
		}

		//返回第一个元素
		value_type& front()
		{
			return _head->_next->_data;
		}

		//返回最后一个元素
		value_type& back()
		{
			return _head->_pre->_data;
		}

		//特定位置插入
		void insert(iterator pos,const value_type& data)
		{
			pNode newnode = new Node(data);
			pos._cur->_pre->_next = newnode;
			newnode->_pre = pos._cur->_pre;
			newnode->_next = pos._cur;
			pos._cur->_pre = newnode;
		}
		 
		 
		 
		//特定位置删除
		void erase(iterator pos)
		{
			pNode position = pos._cur;
			position->_pre->_next = position->_next;
			position->_next->_pre = position->_pre;
			delete position;
		}


		//删除数据
		void clear()
		{
			
			pNode head = _head->_next;
			while (head != _head)
			{
				pNode tmp = head->_next;
				delete head;
				head = tmp;
			}
			_head->_next = _head->_pre = _head;

		}

		//判空
		bool empoty()
		{
			return _head == _head->_next;
		}
		
		//逆序
		void reverse()
		{
			pNode p1 = begin()._cur;
			pNode p2 = end()._cur;
			p2=p2->_pre;
			while (p1!=p2&&p1->_next!=p2)
			{
				swap(p1->_data, p2->_data);
				p1 = p1->_next;
				p2 = p2->_pre;
			}
			if (p1->_next == p2)
			{
				swap(p1->_data, p2->_data);
			}
		}
		
		//节点个数
		size_t size()const
		{
			int count = 0;
			iterator it = begin();
			while (it != end())
			{
				++it;
				count++;
			}
			return count;
		}

		//打印
		void print()
		{
			iterator it = begin();
			while (it != end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}

	private:
		pNode _head;
	};
}
