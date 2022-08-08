#include "../wsi_mode.h"

#include "wsi_helpers_glfw.h"

#include <wsi/native_wsi.h>

#include "../../util/util_string.h"
#include "../../util/log/log.h"

namespace dxvk::wsi {

    static inline uint32_t roundToNextPow2(uint32_t num) {
        if (num-- == 0)
            return 0;

        num |= num >> 1; num |= num >> 2;
        num |= num >> 4; num |= num >> 8;
        num |= num >> 16;

        return ++num;
    }


    static inline void convertMode(const GLFWvidmode& mode, WsiMode* pMode) {
        pMode->width          = uint32_t(mode.width);
        pMode->height         = uint32_t(mode.height);
        pMode->refreshRate    = WsiRational{ uint32_t(mode.refreshRate) * 1000, 1000 };
        // BPP should always be a power of two
        // to match Windows behaviour of including padding.
        pMode->bitsPerPixel   = roundToNextPow2(mode.blueBits + mode.redBits + mode.greenBits);
        pMode->interlaced     = false;
    }


    bool getDisplayMode(
            HMONITOR         hMonitor,
            uint32_t         ModeNumber,
            WsiMode*         pMode) {
        const int32_t displayId    = fromHmonitor(hMonitor);
        int32_t displayCount = 0;
        GLFWmonitor** monitors = glfwGetMonitors(&displayCount);
        GLFWmonitor* monitor = monitors[displayId];
        
        if (!isDisplayValid(displayId))
            return false;
        
        int32_t count = 0;
        const GLFWvidmode* modes = glfwGetVideoModes(monitor, &count);

        convertMode(modes[ModeNumber], pMode);

        return true;
    }


    bool getCurrentDisplayMode(
            HMONITOR         hMonitor,
            WsiMode*         pMode) {
        const int32_t displayId    = fromHmonitor(hMonitor);

        if (!isDisplayValid(displayId))
            return false;

        int32_t displayCount = 0;
        GLFWmonitor** monitors = glfwGetMonitors(&displayCount);
        GLFWmonitor* monitor = monitors[displayId];
        
        auto mode = glfwGetVideoMode(monitor);
        
        convertMode(*mode, pMode);

        return true;
    }


    bool getDesktopDisplayMode(
            HMONITOR         hMonitor,
            WsiMode*         pMode) {
        const int32_t displayId    = fromHmonitor(hMonitor);

        if (!isDisplayValid(displayId))
            return false;

        int32_t displayCount = 0;
        GLFWmonitor** monitors = glfwGetMonitors(&displayCount);
        GLFWmonitor* monitor = monitors[displayId];

        //TODO: actually implement this properly, currently we just grab the current one
        convertMode(*glfwGetVideoMode(monitor), pMode);

        return true;
    }

}
