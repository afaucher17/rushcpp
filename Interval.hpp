/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interval.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:36:04 by afaucher          #+#    #+#             */
/*   Updated: 2015/01/10 15:37:53 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_HPP
# define INTERVAL_HPP
# include <string>
# include <sstream>
# include <iostream>

class Interval
{
	public:
		Interval( void );
		Interval(Interval const & src);
		virtual ~Interval( void );
		Interval &	operator=(Interval const & rhs);
		std::string	toString() const;

		void			refresh();
		unsigned int	value() const;

	private:
		unsigned int _initial;
};

std::ostream &		operator<<(std::ostream & o, Interval const & rhs);

#endif /* INTERVAL_HPP */
