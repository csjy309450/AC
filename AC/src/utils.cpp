#include "AC_Utils.h"

int replace_all(std::string & src, const char* parten, const char* dist)
{
	if (parten == NULL)
	{
		return -1;
	}
	if (src.empty())
	{
		return -1;
	}
	do{
		size_t pos = src.find(parten); // 查找每一行中的"Tom"
		if (pos != std::string::npos)
		{
			src = src.replace(pos, strlen(parten), dist); // 将Tom替换为Jerry
			continue;
		}
		else{
			break;
		}
	} while (1);
	return 0;
}