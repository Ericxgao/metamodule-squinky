cmake_minimum_required(VERSION 3.24)

if (DEFINED ENV{METAMODULE_SDK_DIR})
    set(METAMODULE_SDK_DIR "$ENV{METAMODULE_SDK_DIR}")
elseif("${METAMODULE_SDK_DIR}" STREQUAL "")
    set(METAMODULE_SDK_DIR "${CMAKE_CURRENT_LIST_DIR}/../metamodule-plugin-sdk")
endif()
include(${METAMODULE_SDK_DIR}/plugin.cmake)

project(SquinkyLabs VERSION 0.1 DESCRIPTION "SquinkyLabs for Rack" LANGUAGES C CXX ASM)

# Add these lines to set C++11 or later
set(CMAKE_CXX_STANDARD 17)  # or 11, 14, etc depending on your needs
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Replace the FetchContent section with:
set(SIMDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/simde")

# Define SOURCE_DIR first
set(SOURCE_DIR ./squinky)

add_library(SquinkyLabs STATIC)

target_compile_definitions(SquinkyLabs PRIVATE 
    __V1x 
    __PLUGIN
)

target_sources(SquinkyLabs PRIVATE
    # ${SOURCE_DIR}/src/third-party/IMWidgets.cpp
    ${SOURCE_DIR}/src/FiltModule.cpp
    # ${SOURCE_DIR}/src/BasicModule.cpp
    # ${SOURCE_DIR}/src/BootyModule.cpp
    # ${SOURCE_DIR}/src/ChaosKittyModule.cpp
    # ${SOURCE_DIR}/src/CHBgModule.cpp
    # ${SOURCE_DIR}/src/CHBModule.cpp
    # ${SOURCE_DIR}/src/CompressorModule.cpp
    # ${SOURCE_DIR}/src/CompressorModule2.cpp
    # ${SOURCE_DIR}/src/DGModule.cpp
    # ${SOURCE_DIR}/src/DividerXModule.cpp
    # ${SOURCE_DIR}/src/DrumTriggerModule.cpp
    ${SOURCE_DIR}/src/EV3Module.cpp
    # ${SOURCE_DIR}/src/TremoloModule.cpp
    ${SOURCE_DIR}/dsp/utils/AudioMath.cpp
    ${SOURCE_DIR}/dsp/utils/ObjectCache.cpp
    ${SOURCE_DIR}/dsp/utils/AsymWaveShaper.cpp
    ${SOURCE_DIR}/dsp/third-party/falco/DspFilter.cpp
    ${SOURCE_DIR}/dsp/generators/minBlepGenerator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/SquinkyLabs.cpp
    ${SOURCE_DIR}/dsp/filters/ButterworthFilterDesigner.cpp
    ${SOURCE_DIR}/dsp/filters/HilbertFilterDesigner.cpp
    ${SOURCE_DIR}/dsp/utils/Cmprsr.cpp
    ${SOURCE_DIR}/src/seq/UIPrefs.cpp
    ${SOURCE_DIR}/dsp/utils/CompCurves.cpp
    ${SOURCE_DIR}/src/seq/SqGfx.cpp
    ${SOURCE_DIR}/dsp/utils/SplineRenderer.cpp
    ${SOURCE_DIR}/dsp/generators/minBlepGenerator.cpp
    ${SOURCE_DIR}/dsp/third-party/src/minblep.cpp
    ${SOURCE_DIR}/sqsrc/clock/ClockMult.cpp
)

# Add SIMDE to include directories
target_include_directories(SquinkyLabs PRIVATE 
    ${SIMDE_DIR}
    ${SOURCE_DIR}/src
    ${SOURCE_DIR}/composites
    ${SOURCE_DIR}/sqsrc/util
    ${SOURCE_DIR}/sqsrc/clock
    ${SOURCE_DIR}/dsp/filters
    ${SOURCE_DIR}/dsp/utils
    ${SOURCE_DIR}/util
    ${SOURCE_DIR}/dsp/third-party/falco
    ${SOURCE_DIR}/dsp
    ${SOURCE_DIR}/dsp/fft
    ${SOURCE_DIR}/dsp/third-party/src
    ${SOURCE_DIR}/src/ctrl
    ${SOURCE_DIR}/dsp/generators
    ${SOURCE_DIR}/src/third-party
    ${SOURCE_DIR}/src/seq
    ${SOURCE_DIR}/midi/model
)

target_compile_options(SquinkyLabs PRIVATE 
    $<$<COMPILE_LANGUAGE:CXX>:-include ${CMAKE_CURRENT_LIST_DIR}/src/mutex-stub.hh>
)

# Call this to link and create the plugin file
create_plugin(
    SOURCE_LIB      SquinkyLabs
    PLUGIN_NAME     squinkylabs-plug1
    PLUGIN_JSON     ${CMAKE_CURRENT_LIST_DIR}/squinky/plugin.json
    SOURCE_ASSETS   ${CMAKE_CURRENT_LIST_DIR}/assets
    DESTINATION     ${CMAKE_CURRENT_LIST_DIR}/metamodule-plugins
)