find_package(Git
        QUIET
        REQUIRED)

macro(init_git_submodules)
    if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
        option(GIT_SUBMODULE "Check submodules during build" ON)
        if (GIT_SUBMODULE)
            execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --remote
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
            if (NOT GIT_SUBMOD_RESULT EQUAL "0")
                message(FATAL_ERROR "'git submodule update --init --remote' failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
            else ()
                message(STATUS "Enjin: Submodule(s) updated")
            endif ()
        endif ()
    endif ()
endmacro()