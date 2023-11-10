#include <windows.h>
#include <stdio.h>

//BOOL Is_Win11_or_Later()
//{
//    OSVERSIONINFOEX osvi;
//    DWORDLONG dwlConditionMask = 0;
//    int op = VER_GREATER_EQUAL;
//
//    // Initialize the OSVERSIONINFOEX structure.
//
//    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
//    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
//    osvi.dwMajorVersion = 10;
//    osvi.dwBuildNumber = 22000;
//
//    // Initialize the condition mask.
//
//    VER_SET_CONDITION(dwlConditionMask, VER_MAJORVERSION, op);
//    VER_SET_CONDITION(dwlConditionMask, VER_BUILDNUMBER, op);
//
//    // Perform the test.
//
//    return VerifyVersionInfo(
//        &osvi,
//        VER_MAJORVERSION | VER_BUILDNUMBER,
//        dwlConditionMask);
//}
//
//void main()
//{
//    if (Is_Win11_or_Later())
//        printf("윈도우 11 이상입니다!!!\n");
//    else printf("윈도우 11 이하입니다...\n");
//}

typedef void (WINAPI* RtlGetVersion_FUNC) (OSVERSIONINFOEXW*);

// 윈도우버전알아오기
void Is_Win11_or_Later()
{
	DWORD dwMajor = 0;
	DWORD dwMinor = 0;
	DWORD dwBuildNumber = 0;

	HMODULE hMod;
	RtlGetVersion_FUNC func;

	hMod = LoadLibrary(TEXT("ntdll.dll"));

	if (hMod)
	{
		func = (RtlGetVersion_FUNC)GetProcAddress(hMod, "RtlGetVersion");

		if (func == 0)
		{

		}
		else
		{
			OSVERSIONINFOEX Info;

			ZeroMemory(&Info, sizeof(OSVERSIONINFOEX));

			Info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

			func(&Info);

			dwMajor = Info.dwMajorVersion;
			dwMinor = Info.dwMinorVersion;
			dwBuildNumber = Info.dwBuildNumber;
		}

		FreeLibrary(hMod);
	}

	// dwMajor 가 10 이고 빌드번호가 22000 이상이면 윈도우 11 이다
	if (10 == dwMajor && 22000 <= dwBuildNumber)
	{
		printf("윈도우 11입니다!!!");
	}
	else
	{
		printf("윈도우 10입니다...");
	}
}

int main()
{
	Is_Win11_or_Later();

	return 0;

}

