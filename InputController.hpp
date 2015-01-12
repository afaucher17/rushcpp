#ifndef INPUTCONTROLLER_HPP
# define INPUTCONTROLLER_HPP

class InputController
{
	public:
		InputController( void );
		InputController(InputController const & src);
		~InputController( void );
		InputController &	operator=(InputController const & rhs);

		static int			getInput(void);
};

#endif /* INPUTCONTROLLER_HPP */
