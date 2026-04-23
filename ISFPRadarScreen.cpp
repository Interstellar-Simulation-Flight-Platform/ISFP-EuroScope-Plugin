#include "pch.h"
#include "ISFPRadarScreen.h"

CISFPRadarScreen::CISFPRadarScreen(void)
{
}

CISFPRadarScreen::~CISFPRadarScreen(void)
{
}

void CISFPRadarScreen::OnRefresh(HDC hDC, int Phase)
{
    if (Phase == REFRESH_PHASE_AFTER_LISTS)
    {
        // Get radar area (the whole radar screen)
        RECT radarArea = GetRadarArea();

        // Calculate position at bottom left corner, moved up and right more
        RECT watermarkArea;
        watermarkArea.left = radarArea.left + 120;      // 120 pixels from left edge
        watermarkArea.top = radarArea.bottom - 130;     // 130 pixels from bottom (moved down a bit)
        watermarkArea.right = radarArea.left + 400;     // width 400 pixels
        watermarkArea.bottom = radarArea.bottom - 80;   // height 50 pixels

        // Set text color and background mode
        COLORREF oldTextColor = SetTextColor(hDC, RGB(200, 200, 200));
        int oldBkMode = SetBkMode(hDC, TRANSPARENT);

        // Create font (original settings)
        HFONT hFont = CreateFontA(
            20,                        // nHeight - back to original size
            0,                         // nWidth
            0,                         // nEscapement
            0,                         // nOrientation
            FW_BOLD,                   // fnWeight - bold
            FALSE,                     // fdwItalic
            FALSE,                     // fdwUnderline
            FALSE,                     // fdwStrikeOut
            DEFAULT_CHARSET,           // fdwCharSet
            OUT_DEFAULT_PRECIS,        // fdwOutputPrecision
            CLIP_DEFAULT_PRECIS,       // fdwClipPrecision
            DEFAULT_QUALITY,           // fdwQuality
            DEFAULT_PITCH | FF_SWISS,  // fdwPitchAndFamily
            "Arial"                    // lpszFace
        );

        HFONT oldFont = (HFONT)SelectObject(hDC, hFont);

        // Draw watermark in two lines at bottom left
        // First line: ISFPPlugin
        DrawTextA(hDC, "ISFPPlugin", -1, &watermarkArea, DT_LEFT | DT_TOP | DT_SINGLELINE);

        // Second line: Powered by ISFPFLY
        RECT line2Area = watermarkArea;
        line2Area.top += 24;
        line2Area.bottom += 24;
        DrawTextA(hDC, "Powered by ISFPFLY", -1, &line2Area, DT_LEFT | DT_TOP | DT_SINGLELINE);

        // Restore original settings
        SelectObject(hDC, oldFont);
        DeleteObject(hFont);
        SetBkMode(hDC, oldBkMode);
        SetTextColor(hDC, oldTextColor);
    }
}

void CISFPRadarScreen::OnAsrContentToBeClosed(void)
{
    delete this;
}
