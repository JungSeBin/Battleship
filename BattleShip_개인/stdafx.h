// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <string>
#include <crtdbg.h>
#include <assert.h>
#include <vector>



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include "enum.h"
#include "structure.h"

#define SafeDelete(x) if(x != nullptr){delete x; x= nullptr;}

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK,__FILE__,__LINE__)
#endif