#ifndef BST_ITERATOR_HPP
#define BST_ITERATOR_HPP

#include "bst_node.hpp"

namespace ft
{
	template < typename Key, typename T >
	class bst_iterator
	{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename ft::BSTNode<Key, T> *node_pointer;
		typedef typename std::ptrdiff_t difference_type;
		typedef typename ft::pair<Key, T> pair;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

		bst_iterator(void) : curr(NULL) {}
		bst_iterator(node_pointer x) : curr(x) {}
		bst_iterator(const bst_iterator & other) : curr(other.curr) {}

		virtual ~bst_iterator() {}

		pair &operator*() const { return curr->data; }

		pair *operator->() const { return &(curr->data); }

		bst_iterator &operator++()
		{
			if (!curr)
				return (*this);

			if (curr->next)
			{
				curr = curr->next;
				return *this;
			}

			if (curr->right != NULL)
			{
				curr = curr->right;
				while (curr && curr->left != NULL)
					curr = curr->left;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->right)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_iterator operator++(int)
		{
			bst_iterator old = *this;
			operator++();
			return old;
		}

		bst_iterator operator+(difference_type j) const
		{
			bst_iterator it = *this;

			while (j > 0)
			{
				++it;
				--j;
			}

			return (it);
		}

		bst_iterator operator+=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				++(*this);
				i++;
			}

			return (*this);
		}

		bst_iterator &operator--()
		{
			if (curr->previous)
			{
				curr = curr->previous;
				return *this;
			}

			if (curr->left != NULL)
			{
				curr = curr->left;
				while (curr->right != NULL)
					curr = curr->right;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->left)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_iterator operator--(int)
		{
			bst_iterator old = *this;
			operator--();
			return old;
		}

		bst_iterator operator-(difference_type j) const
		{
			bst_iterator it = *this;

			while (j > 0)
			{
				--it;
				--j;
			}

			return (it);
		}

		bst_iterator operator-=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				--(*this);
				i++;
			}

			return *this;
		}

		bool operator!=(const bst_iterator &other) const { return (this->curr != other.curr); }
		bool operator==(const bst_iterator &other) const { return (this->curr == other.curr); }

		operator bst_iterator< Key, const T >()
		{
			return (bst_iterator< Key, const T >(this->curr));
		}

		node_pointer base() const { return (this->curr); }

	private:
		node_pointer		curr;
	};

	template < typename Key, typename T >
	class bst_const_iterator
	{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename ft::BSTNode<Key, const T> *node_pointer;
		typedef typename std::ptrdiff_t difference_type;
		typedef typename ft::pair<Key, const T> pair;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

		bst_const_iterator(void) : curr(NULL) {}
		bst_const_iterator(node_pointer x) : curr(x) {}
		bst_const_iterator(const bst_const_iterator &other) : curr(other.curr) {}

		bst_const_iterator(const ft::bst_iterator< Key, T > &other) {
			this->curr = reinterpret_cast<node_pointer>(other.base());
		}

		virtual ~bst_const_iterator() {}

		pair &operator*() const { return curr->data; }

		pair *operator->() const { return &(curr->data); }

		bst_const_iterator &operator++()
		{
			if (!curr)
				return (*this);

			if (curr->next)
			{
				curr = curr->next;
				return *this;
			}

			if (curr->right != NULL)
			{
				curr = curr->right;
				while (curr && curr->left != NULL)
					curr = curr->left;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->right)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_const_iterator operator++(int)
		{
			bst_const_iterator old = *this;
			operator++();
			return old;
		}

		bst_const_iterator operator+(difference_type j) const
		{
			bst_const_iterator it = *this;

			while (j > 0)
			{
				++it;
				--j;
			}

			return (it);
		}

		bst_const_iterator operator+=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				++(*this);
				i++;
			}

			return (*this);
		}

		bst_const_iterator &operator--()
		{
			if (curr->previous)
			{
				curr = curr->previous;
				return *this;
			}

			if (curr->left != NULL)
			{
				curr = curr->left;
				while (curr->right != NULL)
					curr = curr->right;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->left)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_const_iterator operator--(int)
		{
			bst_const_iterator old = *this;
			operator--();
			return old;
		}

		bst_const_iterator operator-(difference_type j) const
		{
			bst_const_iterator it = *this;

			while (j > 0)
			{
				--it;
				--j;
			}

			return (it);
		}

		bst_const_iterator operator-=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				--(*this);
				i++;
			}

			return *this;
		}

		bool operator!=(const bst_const_iterator &other) const { return (this->curr != other.curr); }
		bool operator==(const bst_const_iterator &other) const { return (this->curr == other.curr); }

		node_pointer base() const { return (this->curr); }

	private:
		node_pointer		curr;
	};

	template <typename Key, typename T>
	typename ft::bst_iterator<Key, T>::difference_type
	operator!=(const ft::bst_iterator<Key, T> lhs,
			   const ft::bst_const_iterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() != a);
	}

	template <typename Key, typename T>
	typename ft::bst_iterator<Key, T>::difference_type
	operator==(const ft::bst_iterator<Key, T> lhs,
			   const ft::bst_const_iterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() == a);
	}

	template <typename Key, typename T>
	typename ft::bst_iterator<Key, T>::difference_type
	operator>(const ft::bst_iterator<Key, T> lhs,
			  const ft::bst_const_iterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() > a);
	}

	template <typename Key, typename T>
	typename ft::bst_iterator<Key, T>::difference_type
	operator>=(const ft::bst_iterator<Key, T> lhs,
			   const ft::bst_const_iterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() >= a);
	}

	template <typename Key, typename T>
	typename ft::bst_iterator<Key, T>::difference_type
	operator<(const ft::bst_iterator<Key, T> lhs,
			  const ft::bst_const_iterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() < a);
	}

	template <typename Key, typename T>
	typename ft::bst_iterator<Key, T>::difference_type
	operator<=(const ft::bst_iterator<Key, T> lhs,
			   const ft::bst_const_iterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() <= a);
	}

	template < typename Key, typename T >
	class bst_riterator
	{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename ft::BSTNode<Key, T> *node_pointer;
		typedef typename std::ptrdiff_t difference_type;
		typedef typename ft::pair<Key, T> pair;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

		bst_riterator(void) : curr(NULL) {}
		bst_riterator(node_pointer x) : curr(x) {}
		bst_riterator(const bst_riterator &other) : curr(other.curr) {}

		virtual ~bst_riterator() {}

		pair &operator*() const { return curr->data; }

		pair *operator->() const { return &(curr->data); }

		bst_riterator &operator++()
		{
			if (curr->previous)
			{
				curr = curr->previous;
				return *this;
			}

			if (curr->left != NULL)
			{
				curr = curr->left;
				while (curr->right != NULL)
					curr = curr->right;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->left)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_riterator operator++(int)
		{
			bst_riterator old = *this;
			operator++();
			return old;
		}

		bst_riterator operator+(difference_type j) const
		{
			bst_riterator it = *this;

			while (j > 0)
			{
				++it;
				--j;
			}

			return (it);
		}

		bst_riterator operator+=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				++(*this);
				i++;
			}

			return (*this);
		}

		bst_riterator &operator--()
		{
			if (!curr)
				return (*this);

			if (curr->next)
			{
				curr = curr->next;
				return *this;
			}

			if (curr->right != NULL)
			{
				curr = curr->right;
				while (curr && curr->left != NULL)
					curr = curr->left;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->right)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_riterator operator--(int)
		{
			bst_riterator old = *this;
			operator--();
			return old;
		}

		bst_riterator operator-(difference_type j) const
		{
			bst_riterator it = *this;

			while (j > 0)
			{
				--it;
				--j;
			}

			return (it);
		}

		bst_riterator operator-=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				--(*this);
				i++;
			}

			return *this;
		}

		bool operator!=(const bst_riterator &other) const { return (this->curr != other.curr); }
		bool operator==(const bst_riterator &other) const { return (this->curr == other.curr); }

		operator bst_riterator<Key, const T>()
		{
			return (bst_riterator<Key, const T>(this->curr));
		}

		node_pointer base() const { return (this->curr); }

	private:
		node_pointer curr;
	};

	template <typename Key, typename T>
	class bst_const_riterator
	{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename ft::BSTNode<Key, const T> *node_pointer;
		typedef typename std::ptrdiff_t difference_type;
		typedef typename ft::pair<Key, const T> pair;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

		bst_const_riterator(void) : curr(NULL) {}
		bst_const_riterator(node_pointer x) : curr(x) {}
		bst_const_riterator(const bst_const_riterator &other) : curr(other.curr) {}

		bst_const_riterator(const ft::bst_riterator<Key, T> &other)
		{
			this->curr = reinterpret_cast<node_pointer>(other.base());
		}

		virtual ~bst_const_riterator() {}

		pair &operator*() const { return curr->data; }

		pair *operator->() const { return &(curr->data); }

		bst_const_riterator &operator++()
		{
			if (curr->previous)
			{
				curr = curr->previous;
				return *this;
			}

			if (curr->left != NULL)
			{
				curr = curr->left;
				while (curr->right != NULL)
					curr = curr->right;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->left)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_const_riterator operator++(int)
		{
			bst_const_riterator old = *this;
			operator++();
			return old;
		}

		bst_const_riterator operator+(difference_type j) const
		{
			bst_const_riterator it = *this;

			while (j > 0)
			{
				++it;
				--j;
			}

			return (it);
		}

		bst_const_riterator operator+=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				++(*this);
				i++;
			}

			return (*this);
		}

		bst_const_riterator &operator--()
		{
			if (!curr)
				return (*this);

			if (curr->next)
			{
				curr = curr->next;
				return *this;
			}

			if (curr->right != NULL)
			{
				curr = curr->right;
				while (curr && curr->left != NULL)
					curr = curr->left;
			}
			else
			{
				node_pointer y = curr->parent;
				while (y != NULL && curr == y->right)
				{
					curr = y;
					y = y->parent;
				}
				curr = y;
			}
			return *this;
		}

		bst_const_riterator operator--(int)
		{
			bst_const_riterator old = *this;
			operator--();
			return old;
		}

		bst_const_riterator operator-(difference_type j) const
		{
			bst_const_riterator it = *this;

			while (j > 0)
			{
				--it;
				--j;
			}

			return (it);
		}

		bst_const_riterator operator-=(difference_type j)
		{
			difference_type i = 0;

			while (i != j)
			{
				--(*this);
				i++;
			}

			return *this;
		}

		bool operator!=(const bst_const_riterator &other) const { return (this->curr != other.curr); }
		bool operator==(const bst_const_riterator &other) const { return (this->curr == other.curr); }

		node_pointer base() const { return (this->curr); }

	private:
		node_pointer curr;
	};

	template <typename Key, typename T>
	typename ft::bst_riterator<Key, T>::difference_type
	operator!=(const ft::bst_riterator<Key, T> lhs,
			   const ft::bst_const_riterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() != a);
	}

	template <typename Key, typename T>
	typename ft::bst_riterator<Key, T>::difference_type
	operator==(const ft::bst_riterator<Key, T> lhs,
			   const ft::bst_const_riterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() == a);
	}

	template <typename Key, typename T>
	typename ft::bst_riterator<Key, T>::difference_type
	operator>(const ft::bst_riterator<Key, T> lhs,
			  const ft::bst_const_riterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() > a);
	}

	template <typename Key, typename T>
	typename ft::bst_riterator<Key, T>::difference_type
	operator>=(const ft::bst_riterator<Key, T> lhs,
			   const ft::bst_const_riterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() >= a);
	}

	template <typename Key, typename T>
	typename ft::bst_riterator<Key, T>::difference_type
	operator<(const ft::bst_riterator<Key, T> lhs,
			  const ft::bst_const_riterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() < a);
	}

	template <typename Key, typename T>
	typename ft::bst_riterator<Key, T>::difference_type
	operator<=(const ft::bst_riterator<Key, T> lhs,
			   const ft::bst_const_riterator<Key, T> rhs)
	{
		ft::BSTNode<Key, T> *a = reinterpret_cast<ft::BSTNode<Key, T> *>(rhs.base());
		return (lhs.base() <= a);
	}
}

#endif