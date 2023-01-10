#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		T1 first;
		T2 second;

		pair( const pair& p ) : first(p.first), second(p.second) {}
		pair() : first(T1()), second(T2()) {}
		pair(const T1 &a, const T2 &b) : first(a), second(b) {}

		template <class U1, class U2>
		pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

	};

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return pair<T1, T2>(t, u);
	}
}

#endif