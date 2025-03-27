cmake_minimum_required(VERSION 3.8)

project(ProjectManager)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(LoginRegister)

target_link_libraries(
    ${PROJECT_NAME}
    LoginRegister 
    -lwfrest -lworkflow -lssl -lcrypto -lcrypt
)

# 确保主项目能找到 LoginRegister 的头文件
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/LoginRegister/include
)