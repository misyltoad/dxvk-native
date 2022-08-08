#include "../wsi_presenter.h"

#include <GLFW/glfw3.h>

#include <wsi/native_wsi.h>

namespace dxvk::wsi {

    VkResult createSurface(
            HWND                hWindow,
            const Rc<vk::InstanceFn>& vki,
            VkSurfaceKHR*       pSurface) {
        GLFWwindow* window = fromHwnd(hWindow);

        return glfwCreateWindowSurface(vki->instance(), window, nullptr, pSurface);
    }

}