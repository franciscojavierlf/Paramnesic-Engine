#pragma once

#include <stdexcept>

namespace pe
{
	template <class T>
	class ArrayList
	{
	public:
		ArrayList(const unsigned int& size) : m_length(0), m_size(size)
		{
			m_arr = new T[m_size];

		}
		
		ArrayList(const pe::ArrayList<T>& other)
		{
			m_size = other.m_size;
			m_length = other.m_length;
			
			m_arr = new T[m_size];

			for (unsigned int i = 0; i < m_length; i++)
				m_arr[i] = other.m_arr[i];
		}

		ArrayList() : pe::ArrayList<T>(0)
		{

		}

		~ArrayList()
		{
			delete[] m_arr;
		}

		void add(const T& value)
		{
			if (m_length >= m_size)
				expand();

			m_arr[m_length++] = value;
		}

		void replace(const unsigned int& i, const T& value)
		{
			if (i >= m_length)
				throw std::out_of_range("Index out of range.");

			m_arr[i] = value;
		}

		// Careful with this one, since if the T has a pointer inside, you will
		// lose focus of that
		void remove(unsigned int i)
		{
			if (i < 0 || i >= m_length)
				throw std::out_of_range("Index out of range.");

			if (m_length < m_size - 10)
				contract();

			while (i < m_length - 1)
				m_arr[i] = m_arr[++i];

			// Reduces length
			m_length--;
		}
		
		T get(const unsigned int& i)
		{
			if (i < 0 || i >= m_length)
				throw std::out_of_range("Index out of range.");

			return m_arr[i];
		}

		const T get(const unsigned int& i) const
		{
			if (i < 0 || i >= m_length)
				throw std::out_of_range("Index out of range.");

			return m_arr[i];
		}

		int indexOf(const T& t) const
		{
			// if == not exists throw pe::operatorexception

			for (unsigned int i = 0; i < m_length; i++)
				if (m_arr[i] == t) return i;

			return -1;
		}

		bool contains(const T& t) const
		{
			return indexOf(t) >= 0;
		}

		void clean()
		{
			m_length = 0;
			m_size = 0;
			if (m_size > 0) delete[] m_arr;
			m_arr = new T[m_size];
		}

		bool isEmpty() const
		{
			return m_length == 0;
		}

		const unsigned int& length() const
		{
			return m_length;
		}

		T operator[](const unsigned int& i)
		{
			return get(i);
		}

		const T operator[](const unsigned int& i) const
		{
			return get(i);
		}

		pe::ArrayList<T>& operator=(const pe::ArrayList<T>& list)
		{
			clean();
			m_size = list.m_size;
			m_length = list.m_length;
			m_arr = new T[m_size];

			for (unsigned int i = 0; i < m_length; i++)
				m_arr[i] = list.m_arr[i];

			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const pe::ArrayList<T>& list)
		{
			// if no << operatrot exception

			os << "[";
			for (unsigned int i = 0; i < list.m_length; i++)
			{
				os << list.get(i);
				os << (i == list.m_length - 1 ? "" : ",");
			}
			os << "]";

			return os;
		}

	private:
		void expand()
		{
			T* aux = m_arr;
			m_size += 10;
			m_arr = new T[m_size];

			for (unsigned int i = 0; i < m_length; i++)
				m_arr[i] = aux[i];

			delete[] aux;
		}

		void contract()
		{
			T* aux = m_arr;
			m_size -= 10;
			m_arr = new T[m_size];

			for (unsigned int i = 0; i < m_length; i++)
				m_arr[i] = aux[i];

			delete[] aux;
		}
		
	private:
		T* m_arr;
		unsigned int m_length;
		unsigned int m_size;
	};
}