# 设置cmake版本范围
cmake_minimum_required(VERSION 2.0...3.5)
# 设置工程名
project(LangPack C CXX)
# 输出设置
set(LangPack_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../src/LangPack)
set(LIBRARY_OUTPUT_PATH ${LangPack_SOURCE_DIR}/../../bin/vc141/LangPack)
# 打印基本信息
message(STATUS "source_dir:${LangPack_SOURCE_DIR}")
# 设置预处理
add_definitions(-ECO_NO_PROTOBUF)
# 设置api
set(api_dir ${LangPack_SOURCE_DIR}/../../../api)
set(contrib_dir ${LangPack_SOURCE_DIR}/../../../../../contrib)
set(eco_lib_dir ${api_dir}/lib_vc141/Debug)
set(boost_lib_dir ${contrib_dir}/boost/lib_vc141)
set(proto_lib_dir ${contrib_dir}/google/protobuf/lib_vc141/debug)
# 包含头文件
include_directories(${LangPack_SOURCE_DIR})
include_directories(${api_dir})
include_directories(${contrib_dir})
# 设置链接库头文件
link_directories(${eco_lib_dir})
link_directories(${boost_lib_dir})
link_directories(${proto_lib_dir})
# 添加当前（CMakeSourceDir）目录下所有源文件
aux_source_directory(${LangPack_SOURCE_DIR}/. src_dir)
# 设置文件分组
FILE(GLOB  SRC_SOURCE ${LangPack_SOURCE_DIR}/*.cpp)
FILE(GLOB  INC_HEAD ${LangPack_SOURCE_DIR}/*.h)
FILE(GLOB  LIB_HEAD ${api_dir}/lang/*.h)
source_group("src" FILES ${SRC_SOURCE})
source_group("inc" FILES ${INC_HEAD})
source_group("lib\\lang" FILES ${LIB_HEAD})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 设置生成shared dll
add_library(LangPack SHARED  ${src_dir} ${INC_HEAD} ${LIB_HEAD})
# 链接动态库
target_link_libraries(LangPack eco)

#以下方法生成组可以应付文件过多时
#[[
set(ALLFILES 
	${src_dir}
	${api_dir}/lang/*.h
)

foreach(FILE ${ALL_FILES}) 
  get_filename_component(PARENT_DIR "${FILE}" PATH)
  string(REPLACE "/" "\\" GROUP "${PARENT_DIR}")
  if ("${FILE}" MATCHES ".*\\.cpp")
    set(GROUP "src\\${GROUP}")
  elseif("${FILE}" MATCHES ".*\\.hpp")
    set(GROUP "inc\\${GROUP}")
  endif()
  source_group("${GROUP}" FILES "${FILE}")
endforeach()
]]


#cmake --help
#[[
# 指定输出位置 
cmake  CMakeLists.txt -B  ./sln    在当前文件夹下(CMakeLists.txt 所在的文件夹下，其他路径相对设置)cmd  -> cmake  CMakeLists.txt -B  ./sln  生成工程相关文件即在 sln 下。
#此需求尝试在CMakeLists.txt 中配置暂未寻到方法,无果。
]]
