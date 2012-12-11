#ifndef __IA1_PARAMETER_H__
# define __IA1_PARAMETER_H__

#include <map>

#include "IA1_enum.h"
#include "IA1_Value.h"

namespace IA1
{
	class Parameter
	{
	private:
		 std::map<IA1::valueList, Value> _valueList;
		 const IA1::argumentOrder _argument;
	protected:
	public:
		 Parameter();
		 Parameter(IA1::argumentOrder argument);
		 std::map<IA1::valueList, Value>& editValueList();
		 const std::map<IA1::valueList, Value>& getValueList() const;
		IA1::argumentOrder	getArgument() const;

	};

}


#endif /* __IA1_PARAMETER_H__ */