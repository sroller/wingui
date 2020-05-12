#include <windows.h>
#include <commctrl.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
  MessageBox(NULL, TEXT("Goodbye, cruel world!"), TEXT("Note"), MB_OK);
  return 0;
}

