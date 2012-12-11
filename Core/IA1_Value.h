#ifndef __IA1_VALUE_H__
# define __IA1_VALUE_H__

#include "IA1_enum.h"
#include "IA1_Stat.h"

namespace IA1
{

	class Value : public Stat
	{
	private:
		IA1::argumentOrder	_parent;
		IA1::valueList	_value;
		bool	_activation;
	protected:
	public:
		Value();
		Value(IA1::argumentOrder parent, IA1::valueList value);

		IA1::valueList getValue() const;
		IA1::argumentOrder	getparent() const;
		void	setActivation(bool activation);
		bool	getActivation() const;
	};

}


#endif /* __IA1_VALUE_H__ */