cmake_minimum_required(VERSION 3.30)
project(ServerManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# set(CMAKE_PREFIX_PATH "D:/QtStructure/6.5.3/mingw_64")
set(SRC_DIR "./src")  # 源文件目录
set(RES_FILES "${CMAKE_SOURCE_DIR}/resources/resources.qrc") # 资源文件

file(GLOB FILES
        "${SRC_DIR}/*.*" # 所有源文件
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network     # 查找网络模块
        SerialPort  # 查找串口模块
        Sql         # 查找数据库模块
        Charts      # 查找图表模块
        REQUIRED
)

qt_add_resources(RESOURCES_SRCS ${RES_FILES})

add_executable(ServerManager
        ${FILES}              # 添加所有源文件
        ${RESOURCES_SRCS}     # 添加资源文件
)

target_link_libraries(ServerManager
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network     # 链接网络模块
        Qt::SerialPort  # 链接串口模块
        Qt::Sql         # 链接数据库模块
        Qt::Charts      # 链接图表模块
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()

    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()

    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()

    foreach (QT_LIB Core Gui Widgets Network SerialPort Sql Charts)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)

    # 手动添加SQL插件目录
    set(QT_PLUGINS_DIR "${QT_INSTALL_PATH}/plugins")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${QT_PLUGINS_DIR}"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins"
    )
endif ()
