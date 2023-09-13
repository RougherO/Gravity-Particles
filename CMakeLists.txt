cmake_minimum_required(VERSION 3.21.0)
project(GravSim VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# include(FetchContent)
# FetchContent_Declare(
#     SFML
#     GIT_REPOSITORY https://github.com/SFML/SFML.git
#     GIT_TAG 2.6.x
# )

# FetchContent_MakeAvailable(SFML)

add_executable(GravSim "src/main.cpp" "src/App/App.cpp" "src/Particle/Particle.cpp")
target_link_libraries(GravSim PRIVATE sfml-graphics sfml-window sfml-system)

if (WIN32) 
    add_custom_command(
        TARGET GravSim
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<BOOL:${ARCH_64BITS}>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:GravSim>
        VERBATIM
    )

    add_custom_command(
        TARGET GravSim
        COMMENT "Copy SFML DLL"
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_BUILD_DIR}/lib/*.dll $<TARGET_FILE_DIR:GravSim>
        VERBATIM
    )
endif()