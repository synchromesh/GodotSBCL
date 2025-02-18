# SPDX-License-Identifier: Unlicense
# CMakeLists.txt for GodotSBCL/src.
# File Created: 12 February 2025

target_sources( ${PROJECT_NAME}
    PRIVATE
        GodotSBCL.h
        GodotSBCL.cpp
        RegisterExtension.cpp
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)

# End of CMakeLists.txt
