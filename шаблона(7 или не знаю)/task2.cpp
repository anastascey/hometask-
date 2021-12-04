#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <xstring>
#include <exception>
#include <stdexcept>

class Vector_exceptions : public std::exception
{
public:
	Vector_exceptions() : std::exception() {}

	Vector_exceptions(const std::string& s) : std::exception(s.c_str()) {}

	explicit Vector_exceptions(char const* const s, int) : std::exception(s) {}

	~Vector_exceptions() noexcept = default;
};

template < typename T >
class Vector
{
public:

	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;
	using size_type = std::size_t;

	using iterator = pointer;
	using const_iterator = const_pointer;

public:

	Vector() noexcept : m_size(0), m_capacity(0), m_data(nullptr) {};

	explicit Vector(size_type size);
	explicit Vector(size_type size, const T& initial);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&) noexcept;

	~Vector() noexcept
	{
		delete[] m_data;
	}

public:

	reference operator[] (size_type index)
	{
		if (index < 0 || index >= m_size)
		{
			throw Vector_exceptions("Index must be greater or equal than 0 and smaller than the size");
		}

		return m_data[index];
	}
	const_reference operator[](size_type index) const
	{
		if (index < 0 || index >= m_size)
		{
			throw Vector_exceptions("Index must be greater or equal than 0 and smaller than the size");
		}
		
		return m_data[index];
	}

	reference front()
	{
		if (m_data)
		{
			return m_data[0];
		}
		
		else
		{
			throw Vector_exceptions("Size must be greater than 0");
		}
	}
	reference back()
	{
		if (m_data)
		{
			return m_data[m_size - 1];
		}
		
		else
		{
			throw Vector_exceptions("Size must be greater than 0");
		}
	}

	const_reference front() const
	{
		if (m_data)
		{
			return m_data[0];
		}

		else
		{
			throw Vector_exceptions("Size must be greater than 0");
		}
	}
	const_reference back() const
	{
		if (m_data)
		{
			return m_data[m_size - 1];
		}
		
		else
		{
			throw Vector_exceptions("Size must be greater than 0");
		}
	}

	iterator begin() noexcept
	{
		return m_data;
	}
	iterator end() noexcept
	{
		return m_data + m_size;
	}

	const_iterator begin() const noexcept
	{
		return m_data;
	}
	const_iterator end() const noexcept
	{
		return m_data + m_size;
	}

	size_type size() const noexcept
	{
		return m_size;
	}
	size_type capacity() const noexcept
	{
		return m_capacity;
	}

	void resize(size_type new_size);
	void push_back(const T& value);
	void pop_back()
	{
		if (m_size < 1)
		{
			throw Vector_exceptions("Size must be greater than 0");
		}

		m_size--;
	}
	
	template <typename T> friend std::ostream& operator<< (std::ostream& stream, Vector<T>& data);
	template <typename T> friend std::istream& operator>> (std::istream& stream, Vector<T>& data);

private:

	pointer m_data;
	size_type m_size;
	size_type m_capacity;
};

template < typename T >
Vector < T > ::Vector(size_type size):	m_size(size), m_capacity(size)
{
	m_data = new T[m_size];
}

template < typename T >
Vector < T > ::Vector(size_type size, const T& initial): m_size(size), m_capacity(size)
{
	m_data = new T[m_size];
	for (std::size_t i = 0; i < m_size; ++i)
		m_data[i] = initial;
}

template < typename T >
Vector < T >::Vector(const Vector < T >& other) : m_size(other.m_size), m_capacity(other.m_capacity)
{
	m_data = new T[m_size];
	std::copy(other.begin(), other.end(), m_data);
}

template < typename T >
Vector < T >::Vector(Vector < T >&& other) noexcept : m_size( other.m_size),m_capacity( other.m_capacity), m_data(other.m_data)
{
	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

template < typename T >
Vector < T >& Vector < T > ::operator= (const Vector<T>& other)
{
	if (this == &other) return *this;
	delete[] m_data;

	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_data = new T[m_size];

	std::copy(other.begin(), other.end(), m_data);
	return *this;
}

template < typename T >
Vector < T >& Vector < T > ::operator= (Vector<T> && other) noexcept
{
	if (this == &other) return *this;
	if (m_data)
	{
		delete[] m_data;
	}

	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_data = other.m_data;

	other.m_size = 0;
	other.m_capacity = 0;
	other.m_data = nullptr;

	return *this;
}

template < typename T >
void Vector<T>::push_back(const T& value)
{
	if (m_size >= m_capacity)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		auto new_data = new T[new_capacity];
		std::copy(begin(), end(), new_data);
		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
	}
	m_data[m_size++] = value;
}
template < typename T >
void Vector<T>::resize(size_type new_size)
{
	if (new_size <0)
	{
		throw Vector_exceptions("Size must be greater than 0");
	}

	if (new_size != m_size)
	{
		pointer new_data = new T[new_size];

		if (new_size < m_size)
		{
			m_capacity = new_size;

			std::copy(begin(), begin() + new_size - 1, new_data);

			delete[] m_data;

			m_data = new_data;
		}

		if (new_size > m_size)
		{
			std::copy(begin(), end(), new_data);

			delete[] m_data;

			m_data = new_data;
		}

		m_size = new_size;

	}
}


template < typename T >
std::ostream& operator<< (std::ostream& stream, Vector<T>& data)
{
	std::for_each(data.begin(), data.end(), [](T x) {std::cout << x << ' '; });

	return stream;
}

template < typename T >
std::istream& operator>> (std::istream& stream, Vector<T>& data)
{
	T temp;

	if (data.m_data)
	{
		delete[] data.m_data;
		data.m_size = 0;
		data.m_capacity = 0;
	}

	while (std::cin >> temp)
	{
		data.push_back(temp);
	}

	return stream;
}

template < typename T >

void swap(Vector<T>& a, Vector<T>& b)
{
	Vector<T> temp;

	temp = std::move(b);

	b = std::move(a);

	a = std::move(temp);
}

int main()
{
	try {

		Vector < int > v;

		std::cout << v << '\n';

		Vector<std::string> v1(2);

		v1[0] = "hi";

		std::cout << v1 << '\n';

		Vector<int> v2(2, 7);

		std::cout << v2 << '\n';

		Vector<int> v10(v2);

		std::cout << v10 << '\n';

		Vector<std::string> v3(2, "hello");

		std::cout << v3 << '\n';

		Vector < std::string > v4 = v3;

		std::cout << v4 << '\n';

		v3[0] = "test";

		std::cout << v3 << '\n';

		v3.pop_back();

		std::cout << v3 << '\n';

		Vector < int > v5(7, 9);

		std::cout << v5 << '\n';

		Vector < int > v6;
		v6.push_back(100);

		v6.push_back(101);

		v6.push_back(101);

		std::cout << v6 << '\n';

		Vector < int > v7(std::move(v6));

		std::cout << v6 << '\n';
		std::cout << v7 << '\n';

		v7.resize(5);

		std::cout << v7 << '\n';

		v7.resize(3);

		std::cout << v7 << '\n';

		Vector <int> v8;

		std::cin >> v8;

		std::cout << v8 << '\n';

		swap(v5, v8);

		std::cout << v5 << '\n';
		std::cout << v8 << '\n';

	}

	catch (const Vector_exceptions& e)
	{
		std::cerr << e.what();
	}

	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

	catch (...)
	{
		std::cerr << "Unknown error";
	}
	return 0;
}