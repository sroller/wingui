#include <windows.h>
#include <commctrl.h>

LPCTSTR g_szClassName = TEXT("myWindowsClass");

LRESULT CALLBACK
WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
    case WM_LBUTTONDOWN:
      {
        TCHAR szFileName[MAX_PATH];
        HINSTANCE hInstance = GetModuleHandle(NULL);
        
        GetModuleFileName(hInstance, szFileName, MAX_PATH);
        MessageBox(hwnd, szFileName, TEXT("This program is:"), MB_OK|MB_ICONINFORMATION);
      }
    case WM_CLOSE:
      DestroyWindow(hwnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
  WNDCLASSEX wc;
  HWND hwnd;
  MSG Msg;
  INITCOMMONCONTROLSEX icc;

  icc.dwSize = sizeof(icc);
  icc.dwICC = ICC_WIN95_CLASSES;
  InitCommonControlsEx(&icc);

  wc.cbSize        = sizeof(WNDCLASSEX);
  wc.style         = 0;
  wc.lpfnWndProc   = WndProc;
  wc.cbClsExtra    = 0;
  wc.cbWndExtra    = 0;
  wc.hInstance     = hInstance;
  wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
  wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
  wc.lpszMenuName  = NULL;
  wc.lpszClassName = g_szClassName;
  wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

  if (!RegisterClassEx(&wc))
  {
    MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"),
        MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  hwnd = CreateWindowEx(
      WS_EX_CLIENTEDGE,
      g_szClassName,
      TEXT("Need to think of a better title"),
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
      NULL, NULL, hInstance, NULL);

  if (hwnd == NULL)
  {
    MessageBox(NULL, TEXT("Window Creation Failed!"), TEXT("Error!"),
        MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  while(GetMessage(&Msg, NULL, 0, 0) > 0)
  {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  return Msg.wParam;
}

