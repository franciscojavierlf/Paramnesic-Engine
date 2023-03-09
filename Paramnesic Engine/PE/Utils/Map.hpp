#pragma once

#include "PE\Utils\String.hpp"
#include "PE/Utils/Exceptions/IndexOutOfRangeException.hpp"
#include "PE\Utils\ArrayList.hpp"

namespace pe
{
	template <class T1, class T2>
	class Map final
	{
	public:
		Map()
		{

		}

		~Map()
		{
			// Already deletes the array lists, since they are in stack
		}

		T1 tagAt(const unsigned int& i)
		{
			if (i >= m_tags.length())
				throw pe::IndexOutOfRangeException();

			return m_tags[i];
		}

		const T1 tagAt(const unsigned int& i) const
		{
			if (i >= m_tags.length())
				throw pe::IndexOutOfRangeException();

			return m_tags[i];
		}

		T2 objectAt(const unsigned int& i)
		{
			if (i >= m_objects.length())
				throw pe::IndexOutOfRangeException();

			return m_objects[i];
		}

		const T2 objectAt(const unsigned int& i) const
		{
			if (i >= m_objects.length())
				throw pe::IndexOutOfRangeException();

			return m_objects[i];
		}

		T2 get(const T1& tag)
		{
			int i = indexOfTag(tag);

			if (i < 0) throw pe::IndexOutOfRangeException();
			return m_objects[i];
		}

		const T2 get(const T1& tag) const
		{
			int i = indexOfTag(tag);

			if (i < 0) throw pe::IndexOutOfRangeException();
			return m_objects[i];
		}

		void add(const T1& tag, const T2& value)
		{
			if (containsTag(tag))
				throw pe::Exception("Tag already exists.");

			m_tags.add(tag);
			m_objects.add(value);
		}

		void replace(const T1& tag, const T2& value)
		{
			int i = indexOfTag(tag);

			if (i < 0) throw pe::Exception("Tag does not exist.");
			m_objects.replace(i, value);
		}


		int indexOfTag(const T1& tag) const
		{
			return m_tags.indexOf(tag);
		}

		int indexOfObject(const T2& object) const
		{
			return m_objects.indexOf(object);
		}

		bool containsTag(const T1& tag) const
		{
			return indexOfTag(tag) >= 0;
		}

		bool containsObject(const T2& object) const
		{
			return indexOfObject(object) >= 0;
		}

		void remove(const T1& tag)
		{
			int i = indexOfTag(tag);

			if (i < 0) throw pe::IndexOutOfRangeException();
			m_tags.remove(i);
			m_objects.remove(i);
		}

		void removeAt(const unsigned int& i)
		{
			if (i >= m_objects.length())
				throw pe::IndexOutOfRangeException();

			m_tags.remove(i);
			m_objects.remove(i);
		}

		unsigned int length() const
		{
			return m_objects.length();
		}

		T2 operator[](const T1& tag)
		{
			return get(tag);
		}

		const T2 operator[](const T1& tag) const
		{
			return get(tag);
		}

		pe::Map<T1, T2>& operator=(const pe::Map<T1, T2>& map)
		{
			m_tags = map.m_tags;
			m_objects = map.m_objects;

			return *this;
		}

	private:
		pe::ArrayList<T1> m_tags;
		pe::ArrayList<T2> m_objects;
	};
}