cmake_minimum_required (VERSION 3.0)

PROJECT(WebcamFaceRec)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()



set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})

SET(SRC
        main.cpp
        detectObject.cpp
        preprocessFace.cpp
        recognition.cpp
        #ImageUtils_0.7.cpp
        )

ADD_EXECUTABLE( ${PROJECT_NAME} ${SRC} )
#TARGET_LINK_LIBRARIES( ${PROJECT_NAME}  ${CONAN_LIBS} )

#ADD_EXECUTABLE( dnn_face_detector resnet_ssd_face.cpp )
#TARGET_LINK_LIBRARIES( dnn_face_detector  ${CONAN_LIBS} )

# opencv
set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda-10.0")
if(CMAKE_BUILD_TYPE MATCHES "Release")
    set(OpenCV_DIR "/home/afterburner/clones/opencv/build-release")
    message(STATUS "using opencv-release")
else()
    set(OpenCV_DIR "/home/afterburner/clones/opencv/build-debug")
    message(STATUS "using opencv-debug")
endif()
find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

# fmt
find_package(fmt REQUIRED CONFIG)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

# tbb
#set(TBB_ROOT /home/afterburner/clones/tbb-cmake)
#add_subdirectory(${TBB_ROOT} ${TBB_ROOT}/build-debug)
#target_include_directories(main PRIVATE ${TBB_INSTALL_INCLUDE_DIR} )
#target_link_libraries(main PRIVATE tbb tbbmalloc tbbmalloc_proxy)
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -ltbb -ltbbmalloc -ltbbmalloc_proxy)

# boost
# set(BOOST_ROOT "/home/afterburner/clones/boost")
#find_package(Boost REQUIRED)
#target_link_libraries(main PRIVATE ${Boost_LIBRARIES})
#target_include_directories(main PRIVATE ${Boost_INCLUDE_DIR})



# static analysis
#set(CMAKE_LINK_WHAT_YOU_USE TRUE)
#find_program(TIDY "clang-tidy-7")
#set(CMAKE_CXX_CLANG_TIDY ${TIDY} "-checks=*")
#find_program(CPPCHECK cppcheck "--std=c++14")
#set(CMAKE_CXX_CPPCHECK ${CPPCHECK})
#find_program(IWYU include-what-you-use)
#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE  ${IWYU})


