#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>

#include "bst_tree.hpp"
#include "bst_iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef typename ft::pair<const Key, T> value_type;
		typedef typename std::size_t size_type;
		typedef typename std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename ft::bst_iterator<key_type, mapped_type> iterator;
		typedef typename ft::bst_const_iterator<key_type, mapped_type> const_iterator;
		typedef typename ft::bst_riterator<key_type, mapped_type> reverse_iterator;
		typedef typename ft::bst_const_riterator<key_type, mapped_type> const_reverse_iterator;

		typedef typename ft::BSTNode<key_type, mapped_type> *node_pointer;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
		public:
			value_compare(){};
			~value_compare(){};

			bool operator()(const value_type &lhs, const value_type &rhs) const { return (comp(lhs.first, rhs.first)); }

		protected:
			Compare comp;
		};

		map(){

		};

		explicit map(const Compare &comp, const Allocator &alloc = Allocator()) : _alloc(alloc), _comp(comp) {}

		map(const map &x) : _alloc(x.get_allocator()), _comp(Compare())
		{
			for (const_iterator it = x.begin(); it != x.end(); it++)
			{
				this->insert(*it);
			}
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp)
		{
			this->insert(first, last);
		}

		~map(){};

		map &operator=(const map &x)
		{
			this->clear();
			for (const_iterator it = x.begin(); it != x.end(); it++)
				this->root.insert(ft::make_pair<Key, T>((*it).first, (*it).second));

			return (*this);
		}

		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

		mapped_type &at(const key_type &k)
		{
			node_pointer node = this->root.find(k);
			if (!node)
				throw std::out_of_range("Out of range.");

			return (node->data.second);
		}

		const mapped_type &at(const key_type &k) const
		{
			const node_pointer node = this->root.find(k);
			if (!node)
				throw std::out_of_range("Out of range.");

			return (node->data.second);
		}

		mapped_type &operator[](const key_type &key)
		{
			return ((*((this->insert(ft::make_pair(key, mapped_type()))).first)).second);
		}

		iterator begin()
		{
			if (this->empty())
				return (iterator(this->root.root));
			return (iterator(this->root.get_minimum()));
		}

		const_iterator begin() const
		{
			if (this->empty())
				return (const_iterator(this->root.root));
			return (const_iterator(this->root.get_minimum()));
		}

		iterator end()
		{
			return (iterator(this->root.get_end()));
		}

		const_iterator end() const
		{
			return (const_iterator(this->root.get_end()));
		}

		reverse_iterator rbegin()
		{
			if (this->empty())
				return (reverse_iterator(this->root.get_end()));
			return (reverse_iterator(this->root.get_maximum()));
		}

		const_reverse_iterator rbegin() const
		{
			if (this->empty())
				return (reverse_iterator(this->root.get_end()));
			return (reverse_iterator(this->root.get_maximum()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->root.get_end()));
		}

		const_reverse_iterator rend() const
		{
			return (reverse_iterator(this->root.get_end()));
		}

		bool empty() const
		{
			return (this->root.get_size() == 0);
		}

		size_type size() const
		{
			return (this->root.get_size());
		}

		size_type max_size() const
		{
			return (this->_alloc.max_size());
		}

		void clear()
		{
			this->root.free_all(this->root.get_root());
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return (this->root.insert(value));
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			while (first != last)
			{
				this->root.insert(*first);
				first++;
			}
		}

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return ((this->root.insert(val)).first);
		}

		void erase(iterator position)
		{
			this->erase((*position).first);
		}

		size_type erase(const key_type &k)
		{
			iterator f = this->find(k);

			if (f == NULL || f == this->root.get_end())
				return (0);

			this->root.delete_node(k);
			this->root.last_node();
			this->root.before_first_node();

			return (1);
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
				this->erase(first++);
		}

		void swap(map &other)
		{
			ft::map<Key, T> other_copy;
			for (const_iterator it = other.begin(); it != other.end(); it++)
				other_copy.insert(*it);

			other.clear();
			for (const_iterator it = this->begin(); it != this->end(); it++)
				other.insert(*it);

			this->clear();
			for (const_iterator it = other_copy.begin(); it != other_copy.end(); it++)
				this->insert(*it);
		}

		size_type count(const Key &key) const
		{
			return (this->root.find(key) != NULL);
		}

		iterator find(const key_type &k)
		{
			node_pointer node = this->root.find(k);

			if (!node)
				return (iterator(this->end()));

			return (iterator(node));
		}

		const_iterator find(const key_type &k) const
		{
			node_pointer node = this->root.find(k);

			if (!node)
				return (const_iterator(this->end()));

			return (const_iterator(node));
		}

		pair<iterator, iterator> equal_range(const key_type &k)
		{
			return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

		iterator lower_bound(const key_type &k)
		{
			iterator it = this->begin();

			key_compare a = this->key_comp();
			while (it != this->end())
			{
				if (!a((*it).first, k))
					return (it);
				it++;
			}
			return (this->end());
		}

		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator it = this->begin();

			key_compare a = this->key_comp();
			while (it != this->end())
			{
				if (!a((*it).first, k))
					return (it);
				it++;
			}
			return (this->end());
		}

		iterator upper_bound(const key_type &k)
		{
			iterator it = this->begin();

			key_compare a = this->key_comp();
			while (it != this->end())
			{
				if (a(k, (*it).first))
					return (it);
				it++;
			}
			return (this->end());
		}

		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator it = this->begin();

			key_compare a = this->key_comp();
			while (it != this->end())
			{
				if (a(k, (*it).first))
					return (it);
				it++;
			}
			return (this->end());
		}

		key_compare key_comp() const
		{
			return (this->_comp);
		}

		value_compare value_comp() const
		{
			return (value_compare());
		}

	private:
		BSTree<key_type, mapped_type, key_compare> root;
		allocator_type _alloc;
		key_compare _comp;
	};

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &lhs,
			  ft::map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
				const ft::map<Key, T, Compare, Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);

	typename ft::map<Key, T>::const_iterator it = lhs.begin();
	typename ft::map<Key, T>::const_iterator it2 = rhs.begin();

	while (it != lhs.end())
	{
		if (((*it).first != (*it2).first) || ((*it).second != (*it2).second))
			return (false);
		it++;
		it2++;
	}

	return (true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
				const ft::map<Key, T, Compare, Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
		return (true);

	typename ft::map<Key, T>::const_iterator it = lhs.begin();
	typename ft::map<Key, T>::const_iterator it2 = rhs.begin();

	while (it != lhs.end())
	{
		if (((*it).first != (*it2).first) || ((*it).second != (*it2).second))
			return (true);
		it++;
		it2++;
	}

	return (false);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
			   const ft::map<Key, T, Compare, Alloc> &rhs)
{
	typename ft::map<Key, T>::const_iterator it = lhs.begin();
	typename ft::map<Key, T>::const_iterator it2 = rhs.begin();

	for (; (it != lhs.end()) && (it2 != rhs.end()); ++it, (void)++it2)
	{
		if ((*it).first < (*it2).first)
			return false;
		if ((*it2).first < (*it).first)
			return true;
	}

	return (it != lhs.end()) && (it2 == rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
				const ft::map<Key, T, Compare, Alloc> &rhs)
{
	typename ft::map<Key, T>::const_iterator it = lhs.begin();
	typename ft::map<Key, T>::const_iterator it2 = rhs.begin();

	for (; (it != lhs.end()) && (it2 != rhs.end()); ++it, (void)++it2)
	{
		if ((*it).first < (*it2).first)
			return false;
		if ((*it2).first < (*it).first)
			return true;
	}

	return (it != lhs.end()) || (it2 == rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
			   const ft::map<Key, T, Compare, Alloc> &rhs)
{
	typename ft::map<Key, T>::const_iterator it = lhs.begin();
	typename ft::map<Key, T>::const_iterator it2 = rhs.begin();

	for (; (it != lhs.end()) && (it2 != rhs.end()); ++it, (void)++it2)
	{
		if ((*it).first < (*it2).first)
			return true;
		if ((*it2).first < (*it).first)
			return false;
	}

	return (it == lhs.end()) && (it2 != rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
				const ft::map<Key, T, Compare, Alloc> &rhs)
{
	typename ft::map<Key, T>::const_iterator it = lhs.begin();
	typename ft::map<Key, T>::const_iterator it2 = rhs.begin();

	for (; (it != lhs.end()) && (it2 != rhs.end()); ++it, (void)++it2)
	{
		if ((*it).first < (*it2).first)
			return true;
		if ((*it2).first < (*it).first)
			return false;
	}

	return (it == lhs.end()) || (it2 != rhs.end());
}

#endif