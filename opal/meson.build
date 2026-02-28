opal_version = '1.0'

opal_headers = [
  'opal.h',
  'opalws.h'
]
opal_source_files = [
  'opal.cpp',
  'opalws.cpp'
]

opal_public_headers = include_directories('.')

opal_project_target = shared_library(
  'opal',
  opal_source_files,
  install : true,
  #cpp_args : build_args,
  #gnu_symbol_visibility : 'hidden',
  include_directories : opal_public_headers
)

project_dep = declare_dependency(
  include_directories: opal_public_headers,
  link_with : opal_project_target
)

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : [opal_project_target],
                version : opal_version,
                name : 'opal',
                filebase : 'opal',
                subdirs : 'osiris',
                description : 'Osiris Platform Abstraction Layer')

testopal_source_files = [
    'testopal.cpp'
]

#testopal_dependencies = [
#  dependency('opal')
#]

testopal_target = executable(
  'testopal',
  testopal_source_files,
  #dependencies: project_dependencies,
  link_with: opal_project_target,
  install : true,
  #c_args : build_args
)
