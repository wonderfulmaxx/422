#include <map>
#include <vector>
#include <stack>
#include <iostream>

template <typename T>
void print_vector(std::vector<T> &vector)
{
	typename std::vector<T>::iterator first = vector.begin();
	typename std::vector<T>::iterator last = vector.end();

	std::cout << "Content: " << std::endl;
	for (; first != last; first++)
	{
		std::cout << ((*first)) << " ";
	}

	std::cout << std::endl;
	std::cout << "Size: " << vector.size() << std::endl;
	std::cout << std::endl;
}

template <typename Key, typename T>
void print_map(std::map<Key, T> &map)
{
	typename std::map<Key, T>::iterator first = map.begin();
	typename std::map<Key, T>::iterator last = map.end();

	std::cout << "Content: " << std::endl;
	for (; first != last; first++)
	{
		std::cout << ((*first).first) << " : " << ((*first).second) << "\n";
	}

	std::cout << std::endl;
	std::cout << "Size: " << map.size() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	/**
	 * @brief VECTOR CONSTRUCTORS
	 *
	 */
	std::cout << "\e[104mVECTOR CONSTRUCTORS\e[0m" << std::endl;
	{
		std::vector<int> c;

		print_vector(c);
	}

	{
		std::vector<int> c(10, 42);

		print_vector(c);
	}

	{
		std::vector<int> c(10, 42);
		std::vector<int> d(c);

		print_vector(d);
	}

	{
		std::vector<int> c(10, 42);

		std::vector<int> d(c.begin(), c.end());

		print_vector(d);
	}

	/**
	 * @brief VECTOR OPERATOR=
	 *
	 */
	std::cout << "\e[104mVECTOR OPERATOR=\e[0m" << std::endl;

	{
		std::vector<int> c;

		c.push_back(5);
		c.push_back(42);
		c.push_back(77);
		c.push_back(18);
		c.push_back(24);

		print_vector(c);

		std::vector<int> d = c;

		print_vector(d);
	}

	/**
	 * @brief VECTOR ASSIGN
	 *
	 */
	std::cout << "\e[104mVECTOR ASSIGN\e[0m" << std::endl;

	{
		std::vector<int> c;

		c.assign(10, 42);

		print_vector(c);

		c.assign(18, 24);

		print_vector(c);

		std::vector<int> d;

		d.assign(c.begin(), c.end());

		print_vector(d);
	}

	/**
	 * @brief VECTOR AT
	 *
	 */
	std::cout << "\e[104mVECTOR AT\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.assign(30, 42);

		std::cout << (c.at(5)) << std::endl;
		std::cout << (c.at(17)) << std::endl;

		c[6] = 4;

		std::cout << (c.at(4)) << std::endl;

		try
		{
			std::cout << (c.at(-4)) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << (c.at(80)) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}

	/**
	 * @brief OPERATOR[]
	 *
	 */
	std::cout << "\e[104mVECTOR OPERATOR[]\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.assign(5, 42);

		std::cout << c[0] << std::endl;

		c[1] = 17;

		print_vector(c);
	}

	/**
	 * @brief FRONT & BACK
	 *
	 */
	std::cout << "\e[104mVECTOR FRONT/BACK\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.push_back(10);
		c.push_back(187);
		c.push_back(22);
		c.push_back(14);
		c.push_back(15);

		print_vector(c);

		std::cout << "FRONT: " << c.front() << std::endl;
		std::cout << "BACK: " << c.back() << std::endl
				  << std::endl;
	}

	/**
	 * @brief DATA
	 *
	 */
	std::cout << "\e[104mDATA\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.push_back(10);
		c.push_back(187);
		c.push_back(22);
		c.push_back(14);
		c.push_back(15);

		print_vector(c);

		std::cout << (*(c.data())) << "\n"
				  << std::endl;
	}

	/**
	 * @brief ITERATOR
	 *
	 */
	std::cout << "\e[104mITERATOR\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.push_back(10);
		c.push_back(187);
		c.push_back(22);
		c.push_back(14);
		c.push_back(15);

		print_vector(c);

		std::vector<int>::iterator it = c.begin();
		std::vector<int>::iterator ite = c.end();

		std::cout << "BEGIN ITERATOR: " << (*it) << std::endl;
		std::cout << "END ITERATOR: " << (*(--ite)) << std::endl;
		std::cout << std::endl;
		std::cout << "BEGIN ITERATOR ++ : " << (*(++it)) << std::endl;
		std::cout << "END ITERATOR -- : " << (*(--ite)) << std::endl;
	}

	/**
	 * @brief REVERSE ITERATOR
	 *
	 */
	std::cout << "\e[104mREVERSE ITERATOR\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.push_back(10);
		c.push_back(187);
		c.push_back(22);
		c.push_back(14);
		c.push_back(15);

		print_vector(c);

		std::vector<int>::reverse_iterator it = c.rbegin();
		std::vector<int>::reverse_iterator ite = c.rend();

		std::cout << "BEGIN RITERATOR: " << (*(it)) << std::endl;
		std::cout << "END RITERATOR: " << (*(--ite)) << std::endl;

		std::cout << "BEGIN RITERATOR ++: " << (*(++it)) << std::endl;
		std::cout << "END RITERATOR: " << (*(--ite)) << std::endl;
	}

	/**
	 * @brief EMPTY
	 *
	 */
	std::cout << "\e[104mEMPTY\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.push_back(10);
		c.push_back(187);
		c.push_back(22);
		c.push_back(14);
		c.push_back(15);

		std::cout << c.empty() << std::endl;

		std::vector<int> d;

		std::cout << d.empty() << std::endl;
	}

	/**
	 * @brief SIZE
	 *
	 */
	std::cout << "\e[104mSIZE\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.push_back(10);
		c.push_back(187);
		c.push_back(22);
		c.push_back(14);
		c.push_back(15);

		std::cout << c.size() << std::endl;

		std::vector<int> d;

		std::cout << d.size() << std::endl;
	}

	/**
	 * @brief RESERVE
	 *
	 */
	std::cout << "\e[104mRESERVE\e[0m" << std::endl;
	{
		std::vector<int> c;

		std::cout << c.capacity() << std::endl;

		c.reserve(5);

		std::cout << c.size() << std::endl;
		std::cout << c.capacity() << std::endl;
	}

	/**
	 * @brief CAPACITY
	 *
	 */
	std::cout << "\e[104mCAPACITY\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.assign(10, 5);

		std::cout << c.capacity() << std::endl;

		std::vector<int> d;

		std::cout << d.capacity() << std::endl;
	}

	/**
	 * @brief CLEAR
	 *
	 */
	std::cout << "\e[104mCLEAR\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.assign(10, 5);
		print_vector(c);
		c.clear();
		print_vector(c);

		std::vector<int> d;
		print_vector(c);
		d.clear();
		print_vector(c);

		std::vector<int> e;
		e.assign(30, 42);
		print_vector(c);
		d.clear();
		print_vector(c);
	}

	/**
	 * @brief INSERT
	 *
	 */
	std::cout << "\e[104mINSERT\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.insert(c.begin(), 42);
		c.insert(c.begin(), 77);

		print_vector(c);

		std::vector<int> d(10, 42);
		std::vector<int>::iterator it = d.begin();
		it += 5;

		d.insert(it, 777);

		print_vector(d);
	}

	/**
	 * @brief ERASE
	 *
	 */
	std::cout << "\e[104mERASE\e[0m" << std::endl;
	{
		std::vector<int> c(10, 5);

		c.erase(c.begin());

		print_vector(c);

		c.erase(--c.end());

		print_vector(c);

		c.erase(c.begin(), c.end());

		print_vector(c);
	}

	/**
	 * @brief PUSH_BACK/POP_BACK
	 *
	 */
	std::cout << "\e[104mPUSH_BACK/POP_BACK\e[0m" << std::endl;
	{
		std::vector<int> c;

		c.push_back(777);

		print_vector(c);

		c.push_back(42);

		print_vector(c);

		c.push_back(17);

		print_vector(c);

		c.pop_back();

		print_vector(c);

		c.pop_back();

		print_vector(c);
	}

	/**
	 * @brief PUSH_BACK/POP_BACK
	 *
	 */
	std::cout << "\e[104mRESIZE\e[0m" << std::endl;
	{
		std::vector<int> c(10, 5);

		c.resize(5);

		print_vector(c);

		c.resize(10, 777);

		print_vector(c);
	}

	/**
	 * @brief SWAP
	 *
	 */
	std::cout << "\e[104mSWAP\e[0m" << std::endl;
	{
		std::vector<int> c(10, 5);
		std::vector<int> d(3, 42);

		print_vector(c);
		print_vector(d);

		c.swap(d);

		print_vector(c);
		print_vector(d);
	}

	/**
	 * @brief OPERATOR==
	 *
	 */
	std::cout << "\e[104mSWAP\e[0m" << std::endl;
	{
		std::vector<int> c(10, 5);
		std::vector<int> d(3, 42);

		std::cout << (c == d) << std::endl;
		std::cout << (c > d) << std::endl;
		std::cout << (c >= d) << std::endl;
		std::cout << (c < d) << std::endl;
		std::cout << (c <= d) << std::endl;

		c.clear();
		c.push_back(50);
		c.push_back(17);

		d.clear();
		d.push_back(50);
		d.push_back(17);

		std::cout << (c == d) << std::endl;
		std::cout << (c > d) << std::endl;
		std::cout << (c >= d) << std::endl;
		std::cout << (c < d) << std::endl;
		std::cout << (c <= d) << std::endl;

		c.clear();
		c.push_back(50);
		c.push_back(17);

		d.clear();
		d.push_back(14);
		d.push_back(28);

		std::cout << (c == d) << std::endl;
		std::cout << (c > d) << std::endl;
		std::cout << (c >= d) << std::endl;
		std::cout << (c < d) << std::endl;
		std::cout << (c <= d) << std::endl;
	}

	std::cout << std::endl;

	/**
	 * @brief MAP CONSTRUCTORS
	 *
	 */
	std::cout << "\e[103mMAP CONSTRUCTORS\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		print_map(c);
	}

	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		print_map(c);

		std::map<int, std::string> d(c.begin(), c.end());

		print_map(d);
	}

	/**
	 * @brief MAP OPERATOR=
	 *
	 */
	std::cout << "\e[103mMAP OPERATOR=\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		print_map(c);

		std::map<int, std::string> d = c;

		print_map(d);
	}

	/**
	 * @brief MAP AT
	 *
	 */
	std::cout << "\e[103mMAP AT\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << c.at(5) << std::endl;

		try
		{
			std::cout << c.at(1) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}

	/**
	 * @brief MAP OPERATOR[]
	 *
	 */
	std::cout << "\e[103mMAP OPERATOR[]\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << c[5] << std::endl;
		std::cout << c[42] << std::endl;
		std::cout << c[-8] << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP ITERATOR
	 *
	 */
	std::cout << "\e[103mMAP ITERATOR\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::map<int, std::string>::iterator it = c.begin();
		std::map<int, std::string>::iterator ite = c.end();
		--ite;

		std::cout << "MAP BEGIN: " << ((*it).first) << " : " << ((*it).second) << std::endl;
		std::cout << "MAP END: " << ((*ite).first) << " : " << ((*ite).second) << std::endl;

		std::cout << "MAP BEGIN++: " << ((*(++it)).first) << " : " << ((*(it)).second) << std::endl;
		std::cout << "MAP END--: " << ((*(--ite)).first) << " : " << ((*(ite)).second) << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP REVERSE ITERATOR
	 *
	 */
	std::cout << "\e[103mMAP REVERSE ITERATOR\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::map<int, std::string>::reverse_iterator it = c.rbegin();
		std::map<int, std::string>::reverse_iterator ite = c.rend();
		--ite;

		std::cout << "MAP RBEGIN: " << ((*it).first) << " : " << ((*it).second) << std::endl;
		std::cout << "MAP REND: " << ((*ite).first) << " : " << ((*ite).second) << std::endl;

		std::cout << "MAP RBEGIN++: " << ((*(++it)).first) << " : " << ((*(it)).second) << std::endl;
		std::cout << "MAP REND--: " << ((*(--ite)).first) << " : " << ((*(ite)).second) << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP EMPTY
	 *
	 */
	std::cout << "\e[103mMAP EMPTY\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		std::cout << c.empty() << std::endl;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << c.empty() << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP SIZE
	 *
	 */
	std::cout << "\e[103mMAP SIZE\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		std::cout << c.size() << std::endl;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << c.size() << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP CLEAR
	 *
	 */
	std::cout << "\e[103mMAP CLEAR\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		print_map(c);

		c.clear();

		print_map(c);
	}

	/**
	 * @brief MAP INSERT
	 *
	 */
	std::cout << "\e[103mMAP INSERT\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		print_map(c);
	}

	/**
	 * @brief MAP ERASE
	 *
	 */
	std::cout << "\e[103mMAP ERASE\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		print_map(c);

		c.erase(42);

		print_map(c);

		c.erase(c.begin());

		print_map(c);

		c.erase(c.begin(), c.end());

		print_map(c);
	}

	/**
	 * @brief MAP SWAP
	 *
	 */
	std::cout << "\e[103mMAP SWAP\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		print_map(c);

		std::map<int, std::string> d;

		d.insert(std::make_pair<int, std::string>(777, "Meu"));
		d.insert(std::make_pair<int, std::string>(28, "Meu2"));

		print_map(d);

		c.swap(d);

		print_map(c);
		print_map(d);
	}

	/**
	 * @brief MAP COUNT
	 *
	 */
	std::cout << "\e[103mMAP COUNT\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << c.count(1) << std::endl;
		std::cout << c.count(42) << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP FIND
	 *
	 */
	std::cout << "\e[103mMAP FIND\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << ((*c.find(42)).first) << std::endl;
		std::cout << ((*c.find(8)).first) << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP EQUAL RANGE
	 *
	 */
	std::cout << "\e[103mMAP EQUAL RANGE\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << ((c.equal_range(42).first)->first) << std::endl;
		std::cout << ((c.equal_range(42).first)->second) << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief MAP LOWER/UPPER BOUND
	 *
	 */
	std::cout << "\e[103mMAP LOWER/UPPER BOUND\e[0m" << std::endl;
	{
		std::map<int, std::string> c;

		c.insert(std::make_pair<int, std::string>(5, "Hello"));
		c.insert(std::make_pair<int, std::string>(42, "quatre deux"));
		c.insert(std::make_pair<int, std::string>(22, "Hola"));
		c.insert(std::make_pair<int, std::string>(-8, "Halo"));
		c.insert(std::make_pair<int, std::string>(8, "Salut"));

		std::cout << "LOWER BOUND: " << ((*c.lower_bound(42)).first) << std::endl;
		std::cout << "LOWER BOUND: " << ((*c.lower_bound(5)).first) << std::endl;

		std::cout << "UPPER BOUND: " << ((*c.upper_bound(22)).first) << std::endl;
		std::cout << "UPPER BOUND: " << ((*c.upper_bound(5)).first) << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief STACK CONSTRUCTORS
	 *
	 */
	std::cout << "\e[105mSTACK CONSTRUCTORS\e[0m" << std::endl;
	{
		std::stack<int> c;
	}

	{
		std::stack<int> c;

		c.push(45);

		std::stack<int> d(c);

		std::cout << c.top() << std::endl;
		std::cout << d.top() << std::endl;
		std::cout << std::endl;
	}

	/**
	 * @brief STACK OPERATOR=
	 *
	 */
	std::cout << "\e[105mSTACK OPERATOR=\e[0m" << std::endl;
	{
		std::stack<int> c;

		c.push(777);

		std::stack<int> d = c;

		std::cout << c.top() << std::endl;
		std::cout << d.top() << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief STACK EMPTY
	 *
	 */
	std::cout << "\e[105mSTACK EMPTY\e[0m" << std::endl;
	{
		std::stack<int> c;

		std::cout << c.empty() << std::endl;

		c.push(777);

		std::cout << c.empty() << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief STACK SIZE
	 *
	 */
	std::cout << "\e[105mSTACK SIZE\e[0m" << std::endl;
	{
		std::stack<int> c;

		std::cout << c.size() << std::endl;

		c.push(777);
		c.push(777);
		c.push(777);
		c.push(42);

		std::cout << c.size() << std::endl;

		std::cout << std::endl;
	}

	/**
	 * @brief STACK POP
	 *
	 */
	std::cout << "\e[105mSTACK POP\e[0m" << std::endl;
	{
		std::stack<int> c;

		c.push(777);
		c.push(21);
		c.push(24);
		c.push(42);

		std::cout << c.top() << std::endl;
		c.pop();
		std::cout << c.top() << std::endl;
		c.pop();
		std::cout << c.top() << std::endl;
		c.pop();
		std::cout << c.top() << std::endl;
		c.pop();
		std::cout << std::endl;
	}

	return (0);
}