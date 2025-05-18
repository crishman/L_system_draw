cmake_minimum_required(VERSION 3.15)

# Project name
project(L_system_draw VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
option(BUILD_TESTING "Build the testing tree" ON)
if(BUILD_TESTING)
    enable_testing()
    
    # Include the GoogleTest module
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

# Organize source files
set(SOURCE_FILES
    Source/AddFunctions.cpp
    Source/BaseLine.cpp
    Source/DragonLine.cpp
    Source/HilbertLine.cpp
    Source/HosperLine.cpp
    Source/KochLine.cpp
    Source/L_system_draw.cpp
    Source/L_system_drawDlg.cpp
    Source/LeviLine.cpp
    Source/MFCPaintPrimitive.cpp
    Source/MinkovskiyLine.cpp
    Source/PifagorTreeLine.cpp
    Source/SierpinskiLine.cpp
    stdafx.cpp
)

set(HEADER_FILES
    Headers/AddFunctions.h
    Headers/BaseLine.h
    Headers/DragonLine.h
    Headers/HilbertLine.h
    Headers/HosperLine.h
    Headers/InterfacePaintPrimitive.h
    Headers/KochLine.h
    Headers/L_system_draw.h
    Headers/L_system_drawDlg.h
    Headers/LeviLine.h
    Headers/MFCPaintPrimitive.h
    Headers/MakeFractal.h
    Headers/MinkovskiyLine.h
    Headers/PifagorTreeLine.h
    Headers/SierpinskiLine.h
    Headers/resource.h
    stdafx.h
    targetver.h
)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Headers)

# Define platform-specific settings
if(WIN32)
    # Set MFC options for Windows build
    set(CMAKE_MFC_FLAG 2) # Use MFC in shared DLL
    add_definitions(-D_UNICODE -DUNICODE -D_AFXDLL)
    
    # Add resource files for Windows
    set(RESOURCE_FILES
        res/L_system_draw.rc
        res/L_system_draw.rc2
        res/L_system_draw.ico
    )
    
    # Define precompiled header
    set_source_files_properties(
        ${SOURCE_FILES}
        PROPERTIES
        COMPILE_FLAGS "/Yu\"stdafx.h\""
    )
    
    set_source_files_properties(
        stdafx.cpp
        PROPERTIES
        COMPILE_FLAGS "/Yc\"stdafx.h\""
    )
    
    # Create Windows executable with resource files
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES})
    
    # Link Windows libraries
    target_link_libraries(${PROJECT_NAME} PRIVATE)
    
else()
    # For future cross-platform support (placeholder)
    message(STATUS "Non-Windows platform detected. MFC-based UI will not be available.")
    
    # For future cross-platform support, we could add alternative implementation:
    # add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
    # target_link_libraries(${PROJECT_NAME} PRIVATE <future-cross-platform-libs>)
endif()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Installation rules
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
# Add tests subdirectory if testing is enabled
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
