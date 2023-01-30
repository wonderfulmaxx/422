#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second()
		{}

		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
		{}

		pair(const first_type &a) : first(a), second()
		{}

		pair(const first_type &a, const second_type &b) : first(a), second(b)
		{}
		
		pair &operator=(const pair &pr)
		{
			if (this->first == pr.first && this->second == pr.second)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 l,T2 r)
	{
		ft::pair<T1,T2>paire(l,r);
		return(paire);
	}

}


#endif