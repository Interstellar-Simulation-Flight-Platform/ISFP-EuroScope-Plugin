#include "pch.h"
#include "CESPlugIn.h"
#include "ISFPRadarScreen.h"
#include <string>

CESPlugIn* pMyPlugIn = nullptr;

void __declspec (dllexport)
EuroScopePlugInInit(EuroScopePlugIn::CPlugIn** ppPlugInInstance)
{
    *ppPlugInInstance = pMyPlugIn =
        new CESPlugIn();
}

void __declspec (dllexport)
EuroScopePlugInExit(void)
{
    delete pMyPlugIn;
}

CESPlugIn::CESPlugIn(void)
    :CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
        "ISFPPlugin",
        "1.0.0",
        "ISFPFLY",
        "Powered by ISFPFLY")
{
    // Display plugin loaded message
    DisplayUserMessage("ISFPPlugin", "", "ISFPPlugin Powered by ISFPFLY", 1, 0, 0, 0, 0);
    
    // Display welcome message
    DisplayUserMessage("ISFPPlugin", "", "Welcome to ISFPFLY!", 1, 0, 0, 0, 0);
    DisplayUserMessage("ISFPPlugin", "", "Server Address: fsd.flyisfp.com", 1, 0, 0, 0, 0);
    DisplayUserMessage("ISFPPlugin", "", "TeamSpeak Address: ts.flyisfp.com", 1, 0, 0, 0, 0);
    DisplayUserMessage("ISFPPlugin", "", "QQ Group: 644614465", 1, 0, 0, 0, 0);
    DisplayUserMessage("ISFPPlugin", "", "Have a good time!", 1, 0, 0, 0, 0);
}

CRadarScreen* CESPlugIn::OnRadarScreenCreated(const char* sDisplayName,
                                              bool NeedRadarContent,
                                              bool GeoReferenced,
                                              bool CanBeSaved,
                                              bool CanBeCreated)
{
    // Accept standard ES radar screen
    if (strcmp(sDisplayName, "Standard ES radar screen") == 0)
    {
        return new CISFPRadarScreen();
    }
    return nullptr;
}
