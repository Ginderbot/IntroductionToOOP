#include <Windows.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstanse, HINSTANCE hPrewInst, LPSTR lpCmdLine, int nCmdShow)
{
	//MessageBox(NULL, "Hello World!", "First Program", MB_YESNO | MB_ICONINFORMATION);
	DialogBoxParam(hInstanse, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	SetFocus(GetDlgItem(hwnd, IDC_NAME));
	case WM_INITDIALOG:
	{

		//HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	//SendMessage(hwnd, WM_SETICON, 0(LPARAM)hIcon);
		

	}
			break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			//MessageBox(hwnd, "Нажата кнопка ОК", "info", MB_OK | MB_ICONINFORMATION);
			CONST INT SIZE = 20;
			CHAR sz_name[SIZE]{};
			HWND hEdit = GetDlgItem(hwnd, IDC_NAME);
			SendMessage(hEdit, WM_GETTEXT, SIZE, (LPARAM)sz_name);
			CHAR cz_greating[SIZE] = "Привет ";
			strcat_s(cz_greating,SIZE, sz_name);
			strcat_s(cz_greating,SIZE, "!");
			MessageBox(hwnd, cz_greating, "Greating", MB_OK|MB_ICONINFORMATION);
		}
			break;
		case IDCANCEL:
			EndDialog(hwnd, IDCANCEL);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}