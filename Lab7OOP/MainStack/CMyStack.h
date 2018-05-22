#pragma once
#include <memory>

using namespace std;

template <typename T>
class CMyStack
{
public:
	// ����������� �� ���������
	CMyStack() = default;

	// ������������ ����������
	CMyStack(CMyStack<T> && stack) : 
		m_top(stack.m_top), 
		m_size(stack.m_size)
	{
		stack.m_top = nullptr;
		stack.m_size = 0;
	}

	// ���������� ��������� ������������ ��� ����������� �����������
	CMyStack<T>& operator=(CMyStack<T> && stack)
	{
		if (this != &stack)
		{
			m_top = stack.m_top;
			m_size = stack.m_size;
			stack.m_top = nullptr;
			stack.m_size = 0;
		}
		return *this;
	}

	// ���������� �����������
	CMyStack(CMyStack<T> const& stack): 
		m_size(stack.m_size),
		m_top(stack.m_top)
	{
	}

	// ���������� ��������� ������������ ��� ������������ �����������
	CMyStack<T>& operator=(const CMyStack<T> &stack)
	{
		m_top = stack.m_top;
		m_size = stack.m_size;
		return *this;
	}

	// ���������� � ����
	void AppendTop(T value)
	{
		m_top = make_shared<Item>(m_top, value);
		m_size++;
	}

	// �������� �� ������� �����
	void DeleteTop()
	{
		if (m_size == 0)
		{
			throw logic_error("Stack is empty");
		}
		m_top->value.~T();
		m_top = m_top->next;
		m_size--;
	}

	// ����� �������� �����
	T GetTop()
	{
		if (m_top == nullptr)
		{
			throw logic_error("Stack is empty");
		}
		return m_top->value;
	}

	// �������� �� �������
	bool IsEmpty()
	{
		return m_top == nullptr;
	}

	// ����������� ����� 
	void Clear()
	{
		while (m_top)
		{
			DeleteTop();
		}
	}

	// ����������
	~CMyStack() noexcept
	{
		Clear();
	}
private:
	size_t m_size = 0;

	class Item
	{
	public:
		shared_ptr<Item> next;
		T value;
		Item(shared_ptr<Item> nextItem, T val): 
			value(val), 
			next(nextItem)
		{
		}
	};
	shared_ptr<Item> m_top;
};