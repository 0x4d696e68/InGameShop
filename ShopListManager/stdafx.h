#pragma once

#define DECOMPILE_INGAMESHOP 1

#include <Windows.h>
#include "Include.h"

#define SAFE_DELETE(p)  { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p)  { if(p) { delete [] (p);     (p)=NULL; } }
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }
