#ifndef TYPE_TRAITS
# define TYPE_TRAITS

namespace ft
{
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (*first1 < *first2)
            return true;
        if (*first2 < *first1)
            return false;
    }
 
    return (first1 == last1) && (first2 != last2);
	}

    template<bool,typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class T, T v>
    struct integral_constant
    {
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T,v>type;
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T> struct is_integral : public false_type{};
    
    template<>  struct is_integral<bool> : public true_type{};
    template<>  struct is_integral<char> : public true_type{};
    template<>  struct is_integral<wchar_t> : public true_type{};
    template<>  struct is_integral<signed char> : public true_type{};
    template<>  struct is_integral<short int> : public true_type{};
    template<>  struct is_integral<int> : public true_type{};
    template<>  struct is_integral<long int> : public true_type{};
    template<>  struct is_integral<long long int> : public true_type{};
    template<>  struct is_integral<unsigned char> : public true_type{};
    template<>  struct is_integral<unsigned short int> : public true_type{};
    template<>  struct is_integral<unsigned int> : public true_type{};
    template<>  struct is_integral<unsigned long int> : public true_type{};
    template<>  struct is_integral<unsigned long long int> : public true_type{};

    template<>  struct is_integral<const bool> : public true_type{};
    template<>  struct is_integral<const char> : public true_type{};
    template<>  struct is_integral<const wchar_t> : public true_type{};
    template<>  struct is_integral<const signed char> : public true_type{};
    template<>  struct is_integral<const short int> : public true_type{};
    template<>  struct is_integral<const int> : public true_type{};
    template<>  struct is_integral<const long int> : public true_type{};
    template<>  struct is_integral<const long long int> : public true_type{};
    template<>  struct is_integral<const unsigned char> : public true_type{};
    template<>  struct is_integral<const unsigned short int> : public true_type{};
    template<>  struct is_integral<const unsigned int> : public true_type{};
    template<>  struct is_integral<const unsigned long int> : public true_type{};
    template<>  struct is_integral<const unsigned long long int> : public true_type{};
}

# endif