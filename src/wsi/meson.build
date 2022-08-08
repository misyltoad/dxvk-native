wsi_win32_src = [
  'win32/wsi_mode_win32.cpp',
  'win32/wsi_monitor_win32.cpp',
  'win32/wsi_presenter_win32.cpp',
  'win32/wsi_window_win32.cpp',
]

wsi_sdl2_src = [
  'sdl2/wsi_mode_sdl2.cpp',
  'sdl2/wsi_monitor_sdl2.cpp',
  'sdl2/wsi_presenter_sdl2.cpp',
  'sdl2/wsi_window_sdl2.cpp',
]

wsi_glfw_src = [
  'glfw/wsi_mode_glfw.cpp',
  'glfw/wsi_monitor_glfw.cpp',
  'glfw/wsi_presenter_glfw.cpp',
  'glfw/wsi_window_glfw.cpp',
]

if dxvk_wsi == 'win32'
  wsi_src  = wsi_win32_src
  wsi_deps = []
elif dxvk_wsi == 'sdl2'
  wsi_src  = wsi_sdl2_src
  wsi_deps = [ lib_sdl2 ]
elif dxvk_wsi == 'glfw'
  wsi_src  = wsi_glfw_src
  wsi_deps = [ lib_glfw ]
else
  error('Unknown wsi')
endif

wsi_lib = static_library('wsi', wsi_src,
  dependencies        : wsi_deps,
  override_options    : ['cpp_std='+dxvk_cpp_std],
  include_directories : [ dxvk_include_path ])

wsi_dep = declare_dependency(
  link_with           : [ wsi_lib ],
  include_directories : [ dxvk_include_path ])
