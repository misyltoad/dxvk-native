#pragma once

#include <GLFW/glfw3.h>

#include "../wsi_monitor.h"

namespace dxvk {

    inline bool isDisplayValid(int32_t displayId) {
        int32_t displayCount = 0;
        glfwGetMonitors(&displayCount);
        
        return displayId < displayCount && displayId >= 0;
    }

}