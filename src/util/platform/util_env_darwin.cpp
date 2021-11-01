#include "util_env.h"

#include <array>
#include <filesystem>
#include <limits.h>

//Namespace to avoid mixing definitions such as TRUE/FALSE
namespace dyld {
#include <mach-o/dyld.h>
}

namespace dxvk::env {

  std::string getExePath() {
    std::array<char, PATH_MAX> exePath = {};
    uint32_t size = PATH_MAX;

    bool success = dyld::_NSGetExecutablePath(exePath.data(), &size) == 0;

    return std::string(success ? exePath.data() : "");
  }
  
  
  void setThreadName(const std::string& name) {
  }


  bool createDirectory(const std::string& path) {
    return std::filesystem::create_directories(path);
  }

}