#pragma once

namespace pe
{
	struct ReferenceCount final
	{
	public:
		ReferenceCount();
		~ReferenceCount();

		void addReference();
		void removeReference();
		unsigned int getReferenceCount();
		bool hasReferences();

	private:
		unsigned int m_count;
	};

	template <class T>
	struct SharedPtr final
	{
	public:
		SharedPtr(T* ptr) : m_ptr(ptr), m_count(new pe::ReferenceCount())
		{
			m_count->addReference();
		}

		SharedPtr() : m_ptr(nullptr), m_count(new pe::ReferenceCount())
		{
			m_count->addReference();
		}

		SharedPtr(const pe::SharedPtr<T>& other) : m_ptr(other.m_ptr), m_count(other.m_count)
		{
			m_count->addReference();
		}

		~SharedPtr()
		{
			// The pointer gets destroyed, so a reference is removed
			m_count->removeReference();
			if (!m_count->hasReferences())
			{
				delete m_ptr;
				delete m_count;
			}
		}

		T& operator*()
		{
			return *m_ptr;
		}

		T* operator->()
		{
			return m_ptr;
		}

		pe::SharedPtr<T>& operator=(const pe::SharedPtr<T>& other)
		{
			if (this != &other)
			{
				// Old pointer loses a reference
				m_count->removeReference();
				// Checks if it was the last reference
				if (!m_count->hasReferences())
				{
					delete m_ptr;
					delete m_count;
				}

				m_ptr = other.m_ptr;
				m_count = other.m_count;
				m_count->addReference();
			}

			return *this;
		}

	private:
		T* m_ptr;
		pe::ReferenceCount* m_count;
	};
}