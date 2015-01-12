
#include "Pattern.hpp"

Pattern::Pattern(std::string const & pattern) : _pattern(pattern), _current(0), _last(pattern.length())
{
	
	return ;
}

Pattern::Pattern(Pattern const & src)
{
	
	*this = src;
	return ;
}

Pattern::~Pattern( void )
{
	
	return ;
}

Pattern &	Pattern::operator=(Pattern const & rhs)
{
	this->_pattern = rhs._pattern;
	this->_current = rhs._current;
	return *this;
}

e_direction	Pattern::next()
{
	e_direction drt;
	drt = (e_direction)(this->_pattern.at(this->_current++) - '0');
	if (this->_current >= this->_last)
		this->_current = 0;
	return drt;
}

void				Pattern::set(std::string pattern)
{
	this->_last = pattern.length();
	this->_current = 0;
	this->_pattern = pattern;
}

Pattern::Pattern( void ) : _pattern(""), _current(0), _last(0)
{

}

std::string			Pattern::toString() const
{
	std::ostringstream ostr;

	ostr << "Pattern : pattern : " << this->_pattern << ", current : "
		<< this->_current << ", this : " << this->_last;
	return ostr.str();
}

std::ostream &		operator<<(std::ostream & o, Pattern const & rhs)
{
	o << rhs.toString();
	return o;
}
