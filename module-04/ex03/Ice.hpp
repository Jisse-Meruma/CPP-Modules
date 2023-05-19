#ifndef ICE_HPP
# define ICE_HPP

class Ice
{
	public:
		Ice(void);
		Ice(const Ice& C);
		~Ice(void);

		Ice &operator=(const Ice& C);
};

#endif