#include "Main.h"

#ifndef MENUITEM_H_INCLUDED
#define MENUITEM_H_INCLUDED

class MenuItem
{
    public:
        virtual LRESULT draw(HWND hWnd, WPARAM wParam, LPARAM lParam);

        virtual LRESULT onHover(HWND hWnd, WPARAM wParam, LPARAM lParam);

        virtual LRESULT onRightClick(HWND hWnd, WPARAM wParam, LPARAM lParam);

        virtual LRESULT onLeftClick(HWND hWnd, WPARAM wParam, LPARAM lParam);

        LRESULT onHoverDefault(HWND hWnd, NPOS NPos) {
            HDC hdc;
            PAINTSTRUCT ps;
            RECT Rect;

            Rect.top = NPos.y;
            Rect.left = NPos.x;
            Rect.bottom = NPos.y + NPos.height;
            Rect.right = NPos.x + NPos.width;

            hdc = BeginPaint(hWnd, &ps);
            Rectangle(hdc, 50, 50, 200, 150);
            FillRect(hdc, &Rect, CreateSolidBrush(0x2D2D30));
            EndPaint(hWnd, &ps);
            return 0;
        }
};


#endif