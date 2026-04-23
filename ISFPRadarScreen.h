#pragma once
#include <EuroScopePlugIn.h>

using namespace EuroScopePlugIn;

class CISFPRadarScreen : public CRadarScreen
{
public:
    CISFPRadarScreen(void);
    virtual ~CISFPRadarScreen(void);

    virtual void OnRefresh(HDC hDC, int Phase);
    virtual void OnAsrContentToBeClosed(void);
};
