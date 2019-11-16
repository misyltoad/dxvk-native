#include "util_env.h"

namespace dxvk::env {

  std::string getEnvVar(const char* name) {
    std::vector<WCHAR> result;
    result.resize(MAX_PATH + 1);

    DWORD len = ::GetEnvironmentVariableW(str::tows(name).c_str(), result.data(), MAX_PATH);
    result.resize(len);

    return str::fromws(result.data());
  }
  
  
  std::string getExeName() {
    std::string fullPath = getExePath();
    auto n = fullPath.find_last_of('\\');
    
    return (n != std::string::npos)
      ? fullPath.substr(n + 1)
      : fullPath;
  }
  
}
