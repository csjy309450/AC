// ACTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
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

struct AC_Test2 : public AC_Struct
{
public:
	AC_Test2(const char* name) : AC_Struct(name, PLACE_HOLDER)
	{
		AC_Test1 a("param7");
		GET(GET(a, AC_Number<int>, "parm0"), int, NULL) = 198;
		m_val = {
			AC_Mem(AC_Number<int>, ("parm3", 10)),
			AC_Mem(AC_Number<double>, ("parm5", 1.204)),
			AC_Mem(AC_Boolean, ("parm6", true)),
			AC_Mem(AC_Test1, (a)),
		};
	}
	~AC_Test2() {}
};

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

struct AC_Test4 : public AC_Array
{
public:
	AC_Test4(const char* name) : AC_Array(name, PLACE_HOLDER)
	{
		m_val = {
			AC_Mem(AC_Number<int>, ("parm1", 1)),
			AC_Mem(AC_Number<int>, ("parm2", 2)),
			AC_Mem(AC_Number<int>, ("parm3", 3)),
			AC_Mem(AC_Number<float>, ("parm4", PLACE_HOLDER)),
		};
	}
	~AC_Test4() {}
};

struct AC_Test5 : public AC_Struct
{
public:
	AC_Test5(const char* name) : AC_Struct(name, PLACE_HOLDER)
	{
		AC_Test1 parm1("parm1");
		GET(GET(parm1, AC_Number<int>, "parm0"), int, "") = 1024;
		m_val = {
			AC_Mem(AC_Test1, (parm1)),
			AC_Mem(AC_Test2, (AC_Test2("parm2"))),
			AC_Mem(AC_Test3, (AC_Test3("parm3"))),
			AC_Mem(AC_Test4, (AC_Test4("parm4"))),
		};
	}
	~AC_Test5() {}
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::shared_ptr<AC_Test1> test1(new AC_Test1("test1"));
	std::cout << "**** test1 *****\n\n" << AC_To_Json(*(test1)) << std::endl << std::endl;

	std::shared_ptr<AC_Test2> test2(new AC_Test2("test2"));
	std::cout << "**** test2 *****\n\n" << AC_To_Json(*(test2)) << std::endl << std::endl;

	std::shared_ptr<AC_Test3> test3(new AC_Test3("test3"));
	std::cout << "**** test3 *****\n\n" << AC_To_Json(*(test3)) << std::endl << std::endl;

	std::shared_ptr<AC_Test4> test4(new AC_Test4("test4"));
	std::cout << "**** test4 *****\n\n" << AC_To_Json(*(test4)) << std::endl << std::endl;

	std::shared_ptr<AC_Test5> test5(new AC_Test5("test5"));
	std::cout << "**** test5 *****\n\n" << AC_To_Json(*test5) << std::endl << std::endl;
	return getchar();
}

