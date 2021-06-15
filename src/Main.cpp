#include "Main.h"
#include "window/border.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);

TCHAR szClassName[] = TEXT("CLangEdit");

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow) {
    MSG msg;
    BOOL bRet;

    if (!InitApp(hCurInst))
        return false;
    if (!InitInstance(hCurInst, nCmdShow)) 
        return false;

    while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
        if (bRet == -1) {
            break;
        } else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

ATOM InitApp(HINSTANCE hInst) {
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hIcon = (HICON)LoadImage(
        NULL, IDI_APPLICATION,
        IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
    wc.hCursor = (HCURSOR)LoadImage(
        NULL, IDC_ARROW,
        IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
    wc.hbrBackground = CreateSolidBrush(0x252526);
    wc.lpszMenuName = NULL,
    wc.lpszClassName = szClassName;
    wc.hIconSm = (HICON)LoadImage(
        NULL, IDI_APPLICATION,
        IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);

    return (RegisterClassEx(&wc));
}

BOOL InitInstance(HINSTANCE hInst, int nCmdShow) {
    HWND hWnd;

    hWnd = CreateWindow(szClassName,
            TEXT("CLangEdit"),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            NULL,
            NULL,
            hInst,
            NULL
    );
    if(!hWnd)
        return FALSE;
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_NCCALCSIZE:
            return 0;
        case WM_NCHITTEST:
            RECT rcClient;
            POINT poClient;
            poClient.x = LOWORD ( lp );
            poClient.y = HIWORD ( lp );
            GetClientRect ( hWnd, &rcClient );

            ScreenToClient ( hWnd, &poClient );
            LRESULT lresult = BorderLessHitTest(hWnd, msg, wp, lp);
            if (lresult == 0) {
                return CallWindowProc((WNDPROC)GetWindowLong, hWnd, msg, wp, lp);
            }
            return lresult;
        case WM_PAINT:
            HDC hdc;
            PAINTSTRUCT ps;
            return 0;
        case WM_MOUSEHOVER:
            return 0;

    }
    return (DefWindowProc(hWnd, msg, wp, lp));
}