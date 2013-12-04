
/**
 * NNIncludeSet.h
 * 작성자: 이선협
 * 작성일: 2013. 10. 30
 * 마지막으로 수정한 사람: 이선협
 * 수정일: 2013. 12. 05
 */

#pragma once 

#include <winsock2.h>
#include <windows.h>

#ifdef WIN32
#include "Library/DirectX/Include/D2D1.h"
#include "Library/DirectX/Include/D2D1Helper.h"
#include "Library/DirectX/Include/DWrite.h"
#include "Library/DirectX/Include/wincodec.h"

#include "Library/DirectX/Include/d3d9.h"
#include "Library/DirectX/Include/d3dx9.h"
#include "Library/DirectX/Include/DxErr.h"
#endif

#include <string>
#include <list>
#include <map>

#include <assert.h>
#include <time.h>

/* */
/* NNIncludeSet
/* 인클루드하는 헤더 파일을 모아둔 헤더파일
/* */