
/**
 * NNMacroSet.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 04
 */

#pragma once

/* */
/* NNMacroSet
/* 편리하게 사용하기 위해 정의한 매크로
/* */

template <typename T>
inline void SafeDelete( T* &p )
{
	if ( p != nullptr )
	{
		delete p;
		p = nullptr;
	}
}

template <typename T>
inline void SafeArrayDelete( T* &p )
{
	if ( p != nullptr )
	{
		delete[] p;
		p = nullptr;
	}
}

template <typename T>
inline void SafeRelease( T* &p )
{
	if ( p!= nullptr )
	{
		p->Release();
		p = nullptr;
	}
}

#define NN_PI 3.14159265358979

inline float NNDegreeToRadian( float n )
{
	return n / 180.f * (float)NN_PI;
}
inline double NNDegreeToRadian( double n )
{
	return n / 180 * NN_PI;
}

inline float NNRadianToDegree( float n )
{
	return n * 180.f / (float)NN_PI;
}
inline double NNRadianToDegree( double n )
{
	return n * 180 / NN_PI;
}

#ifdef _DEBUG
#define assert(_Expression) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )
#endif

#define NNCREATE_FUNC(CLASS_NAME) \
	static CLASS_NAME* Create() \
	{ \
		CLASS_NAME* pInstance = new CLASS_NAME(); \
		pInstance->Init(); \
		return pInstance; \
	}


#define WM_SOCKET 104