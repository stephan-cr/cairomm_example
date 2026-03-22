project('cairo_sample', 'cpp', default_options: ['cpp_std=c++20'])

cairomm_dep = dependency('cairomm-1.16')
cairomm_png_dep = dependency('cairomm-png-1.16')

executable('sample', 'main.cpp', dependencies: [cairomm_dep, cairomm_png_dep])
