#include "../wsi_monitor.h"

#include "wsi_helpers_glfw.h"

#include <windows.h>
#include <wsi/native_wsi.h>

#include <string>
#include <sstream>

namespace dxvk::wsi {

    HMONITOR getDefaultMonitor() {
        return enumMonitors(0);
    }


    HMONITOR enumMonitors(uint32_t index) {
        return isDisplayValid(int32_t(index))
               ? toHmonitor(index)
               : nullptr;
    }

    bool getDisplayName(
            HMONITOR         hMonitor,
            WCHAR            (&Name)[32]) {
        const int32_t displayId    = fromHmonitor(hMonitor);

        if (!isDisplayValid(displayId))
            return false;

        std::wstringstream nameStream;
        nameStream << LR"(\\.\DISPLAY)" << (displayId + 1);

        std::wstring name = nameStream.str();

        std::memset(Name, 0, sizeof(Name));
        name.copy(Name, name.length(), 0);

        return true;
    }


    bool getDesktopCoordinates(
            HMONITOR         hMonitor,
            RECT*            pRect) {
        const int32_t displayId    = fromHmonitor(hMonitor);

        if (!isDisplayValid(displayId))
            return false;

        int32_t displayCount = 0;
        GLFWmonitor** monitors = glfwGetMonitors(&displayCount);
        GLFWmonitor* monitor = monitors[displayId];

        int32_t x;
        int32_t y;
        int32_t w;
        int32_t h;
        glfwGetMonitorWorkarea(monitor, &x, &y, &w, &h);
        
        pRect->left   = x;
        pRect->top    = y;
        pRect->right  = x + w;
        pRect->bottom = y + h;

        return true;
    }

}