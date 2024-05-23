#pragma once
#define _CRT_SECURE_NO_WARNINGS 1;
#include<iostream>
#include<algorithm>
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
		ListNode(const ListNode<value_type>& l)
		{
			_data = l._data;
			_pre = l._pre;
			_next = l._next;
		}
		ListNode<value_type> &operator=(const ListNode<value_type>& l)
		{
			_data = l._data;
			_pre = l._pre;
			_next = l._next;
			return *this;
		}
		
	};
	//迭代器
	template<class Inputinterator>
	class iterator
	{
	public:
		typedef Inputinterator value_type;
	private:
		ListNode<Inputinterator>* _cur;
	public:
		iterator( ListNode<Inputinterator>*it = ListNode<Inputinterator>())
		{
			_cur = it;
		}
		
		//迭代器 前置++
		iterator<Inputinterator> operator++()
		{

			_cur = _cur->_next;
			return *this;
		}

		//后置++
		iterator<Inputinterator> operator++(int)
		{
			iterator<Inputinterator> tmp(_cur);
			_cur = _cur->_next;
			return tmp;
		}
		//前置--
		iterator<value_type> operator--()
		{
			_cur = _cur->_pre;
			return *this;
		}
	 
		 
		//后置--
		iterator<value_type> operator--(int)
		{
			iterator<Inputinterator> tmp(_cur);
			_cur = _cur->_pre;
			return tmp;
		}
		//!=
		bool operator!=(iterator<Inputinterator> it)
		{
			return _cur != it._cur;
		}
		value_type& operator*()
		{
			return _cur->_data;
		}
		ListNode<value_type>* getnode()
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
	public:
		List()
		{
			_head = new ListNode<T>;
			_head->_pre = _head->_next = _head;
		}
		
		iterator<value_type> begin()
		{
			return iterator<value_type>(_head->_next);
		}

		iterator<value_type> end()
		{
			return iterator<value_type>(_head);
		}

		
		//尾插
		void push_back(const value_type& data)
		{
			ListNode<value_type>* newnode=new ListNode<value_type>(data);
			newnode->_pre = _head->_pre;
			newnode->_next = _head;
			_head->_pre->_next = newnode;
			_head->_pre = newnode;
		}

		//尾删
		void pop_back()
		{
			ListNode<value_type>* tail = _head->_pre;
			tail->_pre->_next = _head;
			_head->_pre = tail->_pre;
			delete tail;
		}

		//头插
		void push_front(const value_type &data )
		{
			ListNode<value_type>* newhead = new ListNode<value_type>(data);
			ListNode<value_type>* head = _head->_next;
			newhead->_pre = _head;
			newhead->_next = head;
			head->_pre = newhead;
			_head->_next = newhead;
		}

		//头删
		void pop_front()
		{
			ListNode<value_type>* head = _head->_next;
			_head->_next = head->_next;
			head->_next->_pre = _head;
			delete head;
		}

		//特定位置插入
		void insert(iterator<value_type> pos,const value_type& data)
		{
			ListNode<value_type>* newnode = new ListNode<value_type>(data);
			pos.getnode()->_pre->_next = newnode;
			newnode->_pre = pos.getnode()->_pre;
			newnode->_next = pos.getnode();
			pos.getnode()->_pre = newnode;
		}
		 
		 
		 
		//特定位置删除
		void erase(iterator<value_type> pos)
		{
			ListNode<value_type>* position = pos.getnode();
			position->_pre->_next = position->_next;
			position->_next->_pre = position->_pre;
			delete position;
		}


		//判空
		bool empoty()
		{
			return _head == _head->_next;
		}
		
		//逆序
		void reverse()
		{
			ListNode<value_type>* p1 = begin().getnode();
			ListNode<value_type>* p2 = end().getnode();
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
		size_t size()
		{
			int count = 0;
			iterator<value_type> it = begin();
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
			iterator<value_type> it = begin();
			while (it != end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}

	private:
		ListNode<T>* _head;
	};

	

}
