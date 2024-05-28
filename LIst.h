#pragma once
#define _CRT_SECURE_NO_WARNINGS 1;
#include<iostream>
#include<algorithm>
#include<assert.h>
using namespace std;

namespace my_list
{
	//����ڵ�
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
	//������
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
		//����
		iterator()= default;
		iterator(const pNode &p)
		{
			_cur = p;
			
		}
		
		//������ ǰ��++
		Self& operator++()
		{
			
			_cur = _cur->_next;
			return *this;
		}

		//����++
		Self operator++(int)
		{
			Self tmp;
			tmp._cur = _cur;
			_cur = _cur->_next;
			return tmp;
		}

		//ǰ��--
		Self& operator--()
		{
			_cur = _cur->_pre;
			return *this;
		}
	 
		 
		//����--
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

	//����
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
		//����
		List()
		{
			_head = new Node;
			_head->_pre = _head->_next = _head;
			//_head->_data = value();
		}
		//��������Ϊn����������������ݶ�һ��
		List(int n, value_type data = value_type())
		{
			_head = new Node;
			_head->_pre = _head->_next = _head;
			while (n--)
			{
				push_back(data);
			}
		}

		//�õ�������ʼ��
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

		//�������ʼ��
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
		//=����
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

		//����
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



		//������
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

		
		

		
		//β��
		void push_back(const value_type& data)const
		{
			pNode newnode=new Node(data);
			newnode->_pre = _head->_pre;
			newnode->_next = _head;
			_head->_pre->_next = newnode;
			_head->_pre = newnode;
		}

		//βɾ
		void pop_back()
		{
			assert(_head != _head->_next);
			pNode tail = _head->_pre;
			tail->_pre->_next = _head;
			_head->_pre = tail->_pre;
			delete tail;
		}

		//ͷ��
		void push_front(const value_type &data )
		{
			pNode newhead = new Node(data);
			pNode head = _head->_next;
			newhead->_pre = _head;
			newhead->_next = head;
			head->_pre = newhead;
			_head->_next = newhead;
		}

		//ͷɾ
		void pop_front()
		{
			pNode head = _head->_next;
			_head->_next = head->_next;
			head->_next->_pre = _head;
			delete head;
		}

		//���ص�һ��Ԫ��
		value_type& front()
		{
			return _head->_next->_data;
		}

		//�������һ��Ԫ��
		value_type& back()
		{
			return _head->_pre->_data;
		}

		//�ض�λ�ò���
		void insert(iterator pos,const value_type& data)
		{
			pNode newnode = new Node(data);
			pos._cur->_pre->_next = newnode;
			newnode->_pre = pos._cur->_pre;
			newnode->_next = pos._cur;
			pos._cur->_pre = newnode;
		}
		 
		 
		 
		//�ض�λ��ɾ��
		void erase(iterator pos)
		{
			pNode position = pos._cur;
			position->_pre->_next = position->_next;
			position->_next->_pre = position->_pre;
			delete position;
		}


		//ɾ������
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

		//�п�
		bool empoty()
		{
			return _head == _head->_next;
		}
		
		//����
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
		
		//�ڵ����
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

		//��ӡ
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
