#include "util_env.h"

namespace dxvk::env {

#ifndef DXVK_NATIVE
  constexpr char dirSlash = '\\';
#else
  constexpr char dirSlash = '/';
#endif


  std::string getEnvVar(const char* name) {
#ifdef DXVK_NATIVE
    char* result = std::getenv(name);
    return (result)
      ? result
      : "";
#else
    std::vector<WCHAR> result;
    result.resize(MAX_PATH + 1);

    DWORD len = ::GetEnvironmentVariableW(str::tows(name).c_str(), result.data(), MAX_PATH);
    result.resize(len);

    return str::fromws(result.data());
#endif
  }
  
  
  std::string getExeName() {
    std::string fullPath = getExePath();
    auto n = fullPath.find_last_of(dirSlash);
    
    return (n != std::string::npos)
      ? fullPath.substr(n + 1)
      : fullPath;
  }
  
}
