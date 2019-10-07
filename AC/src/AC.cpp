#include "AC_Utils.h"
#include "AC.hpp"

AC_EXP_API std::string AC_To_Json(AutoConverter & ac)
{
	return ac.Serialize();
}

AC_EXP_API std::string AC_To_Json(std::vector<std::shared_ptr<AutoConverter>> & ac)
{
	std::string strJson;
	for (std::vector<std::shared_ptr<AutoConverter>>::iterator it = ac.begin();
		it != ac.end(); ++it)
	{
		strJson += (*it)->Serialize() + ((it + 1) != ac.end() ? "," : "");
	}
	return "{" + strJson + "}";
}