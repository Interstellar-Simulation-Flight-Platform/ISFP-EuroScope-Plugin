#pragma once
#include <EuroScopePlugIn.h>

using namespace EuroScopePlugIn;

class CESPlugIn : public CPlugIn
{
public:
    CESPlugIn(void);
    virtual CRadarScreen* OnRadarScreenCreated(const char* sDisplayName,
                                               bool NeedRadarContent,
                                               bool GeoReferenced,
                                               bool CanBeSaved,
                                               bool CanBeCreated);
};
