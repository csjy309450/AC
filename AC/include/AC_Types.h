#ifndef _TYPES_H_
#define _TYPES_H_

#if _MSC_VER > 1500
#define CFG_C99 1
#endif // _MSC_VER > 1500

#define UnNull 1
#define Null 0
#ifndef TRUE
#define TRUE 1
#endif // !TRUE
#ifndef FALSE
#define FALSE 0
#endif // !FALSE
typedef char null_t;
typedef char char_t;
typedef int boolean_t;
#ifndef CFG_C99
typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
#ifdef WIN32
typedef long long int64_t;
typedef unsigned long long uint64_t;
#endif // !WIN32
#else
#include <stdint.h>
#endif // CFG_C99
typedef char* string_t;
typedef float float32_t;
typedef double float64_t;
typedef void void_t, *p_void_t;
typedef unsigned long echarts_t;

#ifdef AUTOCONVERTER_EXPORTS
#define AC_EXP_CLASS _declspec( dllexport )
#define AC_EXP_API  __declspec(dllexport)
#else
#define AC_EXP_CLASS _declspec(dllimport)
#define AC_EXP_API  __declspec(dllimport)
#endif

#define ARG_IN
#define ARG_OUT
#define ARG_IN_OUT

#define DLLEXPORT_API(ret_type) \
	extern "C" _declspec(dllexport) ret_type _stdcall 

#define BUILDIN_ARRAY(type, name, count) \
	struct InerStru_##type##_##name { \
		bool flag; \
		type val[count]; \
	}name

struct Int8
{
	null_t flag; // !用于标记数据时候有效（为空），模拟java、python中的 var = null
	char val;
};

struct UInt8
{
	null_t flag;
	unsigned char val;
};

struct Int16
{
	null_t flag;
	short val;
};

struct UInt16
{
	null_t flag;
	unsigned char val;
};

struct Int32
{
	null_t flag;
	int val;
};

struct UInt32
{
	null_t flag;
	unsigned int val;
};

struct Int64
{
	null_t flag;
	long long val;
};

struct UInt64
{
	null_t flag;
	unsigned long long val;
};

struct String
{
	null_t flag;
	char* val;
};

struct Float32
{
	null_t flag;
	float val;
};

struct Float64
{
	null_t flag;
	double val;
};

typedef struct UInt8 Byte;
typedef struct UInt8 Boolean;
typedef struct Int8 Char;

typedef int xxx_type;

typedef struct tagNumber
{
	enum NumType
	{
		NUM_NULL = 0,
		NUM_INT,
		NUM_FLOAT,
	};

	union NumValue
	{
		int32_t i_val;
		float64_t f_val;
	};
	null_t falg;
	enum NumType vtype;
	union NumValue val;
}Number, *LPNumber;

typedef struct tagFunction
{
	null_t falg;
	char_t fnName[128];
	uint32_t fnBodySize;
	string_t fnBody;
}Function, *LPFunction;

typedef union tagNumFun
{
	enum NumFunType
	{
		NUM_NULL = 0,
		NUM_NUM,
		NUM_FUN
	};
	null_t falg;
	Number i_val;
	Function fn_val;
}NumFun, *LPNumFun;

enum HorizontalAlignType
{
	HAT_NULL = 0,
	HAT_LEFT,
	HAT_RIGHT,
	HAT_CENTER,
};

enum VerticalAlignType
{
	VAT_NULL = 0,
	VAT_TOP,
	VAT_MIDDLE,
	VAT_BOTTOM,
};

typedef union tagPOS
{
	enum PosType
	{
		POS_NULL = 0,
		POS_NUM,
		POS_PERCENTAGE,
		POS_ALIGN
	};
	null_t falg;
	Number i_val;
	enum HorizontalAlignType em_val;
}POS, *LPPOS;

typedef union tagColor
{
	enum ColorType
	{
		ECCT_NULL,
		CT_CODE,
		CT_NAME,
		CT_TETRAD,
	};
	null_t falg;
	char_t color[32];
}Color, *LPColor;

enum Axis2DType
{
	AXIS_X,
	AXIS_Y
};

typedef struct tagStringArray
{
	null_t falg;
	uint32_t nStr;
	string_t * arrStr;
}StringArray, *LPStringArray;

typedef struct tagNumberArray
{
	null_t falg;
	uint32_t size;
	Number * arrNum;
}NumberArray, *LPNumberArray;

typedef struct tagTimeTuple
{
	null_t falg;
	char_t szTm[128];
	Number value;
}TimeTuple, *LPTimeTuple;

typedef struct tagTimeTupleArray
{
	null_t falg;
	uint32_t size;
	TimeTuple * arrValue;
}TimeTupleArray, *LPTimeTupleArray;

#endif // !_TYPES_H_
