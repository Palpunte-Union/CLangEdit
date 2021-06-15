#include "Main.h"


int hitTestRC(int Row, int Col, boolean a, boolean b) {
    switch (Row) {
        case 0:
            switch (Col) {
                case 0:
                    return HTTOPLEFT;
                case 1:
                    if (a) {
                        return HTTOP;
                    } else if (b) {
                        return HTCAPTION;
                    } else {
                        return HTNOWHERE;
                    }
                case 2:
                    return HTTOPRIGHT;
            }
        case 1:
            switch (Col) {
                case 0:
                    return HTLEFT;
                case 1:
                    return HTNOWHERE;
                case 2:
                    return HTRIGHT;
            }
        case 2:
            switch (Col) {
                case 0:
                    return HTBOTTOMLEFT;
                case 1:
                    return HTBOTTOM;
                case 2:
                    return HTBOTTOMRIGHT;
            }
    }
}

LRESULT BorderLessHitTest(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    int borderOffset = 10;
    int borderThickness = 4;

    POINT point;
    RECT rcWindow;

    GetCursorPos(&point);
    GetWindowRect(hWnd, &rcWindow);

    int uRow = 1, uCol = 1;
    boolean fOnResizeBorder = false, fOnFrameDrag = false;

    int topOffset = 27 == 0 ? borderThickness : 27;

    if (point.y >= rcWindow.top && point.y < rcWindow.top + topOffset + borderOffset) {
        fOnResizeBorder = (point.y < (rcWindow.top + borderThickness));
        if (!fOnResizeBorder) {
            fOnFrameDrag = (point.y <= rcWindow.top + 27 + borderOffset) && (point.x < (rcWindow.right - (150 + borderOffset + 0))) && (point.x > (rcWindow.left + 0 + borderOffset + 0));
        }
        uRow = 0;
    }
    else if (point.y < rcWindow.bottom && point.y >= rcWindow.bottom - borderThickness)
        uRow = 2;
    if (point.x >= rcWindow.left && point.x < rcWindow.left + borderThickness)
        uCol = 0;
    else if (point.x < rcWindow.right && point.x >= rcWindow.right - borderThickness)
        uCol = 2;

    return hitTestRC(uRow, uCol, fOnResizeBorder, fOnFrameDrag);
}