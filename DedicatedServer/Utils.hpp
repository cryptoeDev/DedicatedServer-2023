#pragma once
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include <map>
#include <vector>

using namespace std;
typedef unsigned int								EntityId;
typedef const char* cchar;
typedef unsigned char								BYTE;
typedef __int8										int8;
typedef __int16										int16;
typedef __int32										int32;
typedef __int64										int64;
typedef unsigned int								uint;
typedef unsigned __int8								uint8;
typedef unsigned __int16							uint16;
typedef unsigned __int32							uint32;
typedef unsigned __int64							uint64;

interface CRT
{
public:

	static char* StrStr(const char* str, const char* strSearch);
	static int StrCmp(const char* string1, const char* string2);

	static void* MemCpy(void* dest, const void* source, unsigned int count);
	static void* MemSet(void* memptr, char val, unsigned int num);
	static void* RtlSecureZeroMemory(void* ptr, unsigned int num);
};