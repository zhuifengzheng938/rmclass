# 指定CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称（可自定义，比如CLASS14_OpenCV）
project(CLASS14)

# 设置C++标准为C++11（兼容绝大多数编译器）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 手动指定OpenCV的配置文件路径（防止CMake找不到，可选但推荐加）
set(OpenCV_DIR /usr/local/lib/cmake/opencv4)

# 查找OpenCV库（REQUIRED表示找不到则报错）
find_package(OpenCV REQUIRED)

# 将OpenCV的头文件目录添加到项目中
include_directories(${OpenCV_INCLUDE_DIRS})

# 指定要编译的源文件（你的usb.cpp）
add_executable(usb usb.cpp)

# 将OpenCV库链接到可执行文件usb上
target_link_libraries(usb ${OpenCV_LIBS})