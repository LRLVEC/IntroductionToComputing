#include <cstdio>
#include <cstdlib>
#include <new>

template<class T>struct List
{
	struct ListNode
	{
		T data;
		ListNode* pre;
		ListNode* suc;

		ListNode();
		ListNode(T const&);
		ListNode(ListNode*, T const&);
		ListNode(T const&, ListNode*);
		~ListNode();
	};

	ListNode* begin;
	ListNode* end;
	unsigned int length;

	List();

	~List();

	List<T>& pushBack(T const&);
	List<T>& deleteElement(T const&);

	bool traverse(bool(*p)(T const&))const;
	bool traversePrint()const;
};

//ListNode
template<class T>inline List<T>::ListNode::ListNode()
	:
	data(),
	pre(NULL),
	suc(NULL)
{

}
template<class T>inline List<T>::ListNode::ListNode(T const& _data)
	:
	data(_data),
	pre(NULL),
	suc(NULL)
{
}
template<class T>inline List<T>::ListNode::ListNode(ListNode* _pre, T const& _data)
	:
	data(_data),
	pre(_pre)
{
	if (pre->suc)
	{
		suc = pre->suc;
		suc->pre = this;
		pre->suc = this;
	}
	else
	{
		pre->suc = this;
		suc = NULL;
	}
}
template<class T>inline List<T>::ListNode::ListNode(T const& _data, ListNode* _suc)
	:
	data(_data),
	suc(_suc)
{
	if (suc->pre)
	{
		pre = suc->pre;
		pre->suc = this;
		suc->pre = this;
	}
	else
	{
		suc->pre = this;
		pre = NULL;
	}
}

template<class T>inline List<T>::ListNode::~ListNode()
{
	if (pre)
	{
		if (suc)
		{
			pre->suc = suc;
			suc->pre = pre;
			suc = NULL;
		}
		else
		{
			pre->suc = NULL;
		}
		pre = NULL;
	}
	else if (suc)
		suc->pre = NULL;
}

//List
template<class T>inline List<T>::List()
	:
	begin(NULL),
	end(NULL),
	length(0)
{
}

template<class T>inline List<T>::~List()
{
	while (begin)
	{
		(&(begin->data))->~T();
		ListNode* t(begin->suc);
		::free(begin);
		begin = t;
	}
}

template<class T>inline List<T>& List<T>::pushBack(T const& _data)
{
	if (begin)
		end = new((ListNode*)::malloc(sizeof(ListNode)))ListNode(end, _data);
	else
		end = begin = new((ListNode*)::malloc(sizeof(ListNode)))ListNode(_data);
	++length;
	return *this;
}
template<class T>inline List<T>& List<T>::deleteElement(T const& a)
{
	ListNode* k(begin);
	while (k)
	{
		if (k->data == a)
		{
			ListNode* tp(k);
			k = k->suc;
			::free(tp);
			length--;
		}
		else break;
	}
	begin = k;
	begin->pre = NULL;
	k = begin->suc;
	ListNode* p = begin;
	end = p;
	while (k)
	{
		while (k->data == a)
		{
			ListNode* tp(k);
			k = k->suc;
			::free(tp);
			length--;
			if (!k)break;
		}
		p->suc = k;
		if (k)
		{
			k->pre = p;
			while (k->data != a)
			{
				end = k;
				k = k->suc;
				if (!k)break;
			}
			if (k)p = k->pre;
		}
	}
	return *this;
}
template<class T>inline bool List<T>::traverse(bool(*p)(T const&)) const
{
	ListNode* t(begin);
	while (t)
	{
		if (!p(t->data))return false;
		t = t->suc;
	}
	return true;
}
template<class T>inline bool List<T>::traversePrint() const
{
	ListNode* t(begin);
	while (t)
	{
		if (t == end)
			printf("%d", t->data);
		else
			printf("%d ", t->data);
		t = t->suc;
	}
	return true;
}


int main()
{
	unsigned int n(0);
	scanf("%u", &n);
	List<int> ahh;
	for (unsigned int c0(0); c0 < n; ++c0)
	{
		int a;
		scanf("%d", &a);
		ahh.pushBack(a);
	}
	int d(0);
	scanf("%d", &d);
	ahh.deleteElement(d);
	ahh.traversePrint();
}