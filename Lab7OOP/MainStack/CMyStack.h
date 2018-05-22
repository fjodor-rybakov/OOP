#pragma once
#include <memory>

using namespace std;

template <typename T>
class CMyStack
{
public:
	// Конструктор по умолчанию
	CMyStack() = default;

	// Перемещающий коструктор
	CMyStack(CMyStack<T> && stack) : 
		m_top(stack.m_top), 
		m_size(stack.m_size)
	{
		stack.m_top = nullptr;
		stack.m_size = 0;
	}

	// Перегрузка оператора присваивания для коструктора перемещения
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

	// Копирующий конструктор
	CMyStack(CMyStack<T> const& stack): 
		m_size(stack.m_size),
		m_top(stack.m_top)
	{
	}

	// Перегрузка оператора присваивания для конструктора копирования
	CMyStack<T>& operator=(const CMyStack<T> &stack)
	{
		m_top = stack.m_top;
		m_size = stack.m_size;
		return *this;
	}

	// Добавление в стек
	void AppendTop(T value)
	{
		m_top = make_shared<Item>(m_top, value);
		m_size++;
	}

	// Удаление из вершины стека
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

	// Вывод выершины стека
	T GetTop()
	{
		if (m_top == nullptr)
		{
			throw logic_error("Stack is empty");
		}
		return m_top->value;
	}

	// Проверка на пустоту
	bool IsEmpty()
	{
		return m_top == nullptr;
	}

	// Опустошения стека 
	void Clear()
	{
		while (m_top)
		{
			DeleteTop();
		}
	}

	// Деструктор
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