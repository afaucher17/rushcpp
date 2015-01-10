#ifndef POSITION_HPP
# define POSITION_HPP

class Position
{
	public:
		Position( void );
		Position(int x, int y);
		Position(Position const & src);
		~Position( void );
		Position &	operator=(Position const & rhs);

		int			getX() const;
		int			getY() const;
		void		update(int x, int y);

	private:
		int			_x;
		int			_y;
};

#endif /* POSITION_HPP */
