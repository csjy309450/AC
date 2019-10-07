AC
==

## 0 introduction

AC is a data serialization framework based on pure c++11, box support, no tripartite dependence.

## 1 usage

### 1.1 core object

* class AutoConverter ///< abstract class for converting c object to text(json/xml)
* class Serializer ///< interface of object serializer.
* template\<class T_AC\> class AC_Container ///< AutoConverter object container.
* class AC_Struct ///< simulate to python struct type, user could add member dynamically.
* class AC_Array ///< simulate to java List type, user could add member dynamically.
* class AC_Enum ///< enum type.
* template\<class T\> class AC_Variable ///< base variable type.
* template\<class T\> class AC_Number ///< numerical variable type.
* typedef AC_Number\<int\> AC_Int
* typedef AC_Number\<double\> AC_Float
* class AC_Char
* class AC_String
* class AC_Boolean
* class AC_2DPoint

### 1.2 examples

> example-1 (AC_Struct)

```c++
#include "AC.hpp"
struct AC_Test1 : public AC_Struct
{
public:
	AC_Test1(const char* name) : AC_Struct(name, PLACE_HOLDER)
	{
		m_val = {
			AC_Mem(AC_Number<int>, ("parm0", 10)),
			AC_Mem(AC_Char, ("parm1", 'A')),
			AC_Mem(AC_Number<double>, ("parm2", 1.204)),
		};
	}
	AC_Test1(const AC_Test1 & other) : AC_Struct(other)
	{
	}
	~AC_Test1() {}
};

int main()
{
	AC_Test1 test1("test1");
	std::cout << "**** test1 *****\n\n" << AC_To_Json(test1) << std::endl << std::endl;
}
```

> example-2 (AC_Array)

```c++
#include "AC.hpp"
struct AC_Test3 : public AC_Array
{
public:
	AC_Test3(const char* name) : AC_Array(name, PLACE_HOLDER)
	{
		AC_Test1 a("parm4");
		GET(GET(a, AC_Number<int>, "parm0"), int, "") = 298;
		m_val = {
			AC_Mem(AC_Number<int>, ("parm1", 10)),
			AC_Mem(AC_Number<double>, ("parm2", 1.204)),
			AC_Mem(AC_Boolean, ("parm3", true)),
			AC_Mem(AC_Test1, (a)),
		};
	}
	~AC_Test3() {}
};
int main()
{
	AC_Test3 test3("test3");
	std::cout << "**** test3 *****\n\n" << AC_To_Json(test3) << std::endl << std::endl;
}
```

