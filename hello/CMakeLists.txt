PROJECT (Pocketbook-HelloWorld)

CMAKE_MINIMUM_REQUIRED (VERSION 3.10.1)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1.0)
set(CMAKE_SYSTEM_PROCESSOR armv7a)
set(BUILD_SHARED_LIBS ON)


set(TOOLCHAIN_PATH "/home/senior_kapitoshka/developpement/PBSDK")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_FIND_ROOT_PATH "${TOOLCHAIN_PATH}/arm-obreey-linux-gnueabi/sysroot/")
set(CMAKE_INCLUDE_PATH "/arm-obreey-linux-gnueabi/sysroot/usr/include")


message("CMAKE_FIND_ROOT_PATH=${CMAKE_FIND_ROOT_PATH}")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
include_directories("${TOOLCHAIN_PATH}/arm-obreey-linux-gnueabi/sysroot/usr/include/freetype2")


set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/bin/arm-obreey-linux-gnueabi-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PATH}/bin/arm-obreey-linux-gnueabi-g++")


set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2 -pipe -fomit-frame-pointer -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp " CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE "-DNDEBUG -O2 -pipe -fomit-frame-pointer -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp " CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_DEBUG "-DDEBUG -O0 -g -pipe -fomit-frame-pointer -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp " CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -O0 -g -pipe -fomit-frame-pointer -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp " CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-s" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "-s" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-z,defs" CACHE STRING "" FORCE)

add_definitions(-DPLATFORM_FC)
set(PB_PLATFORM "ARM" CACHE STRING "ARM|PC Readonly!")

set(CMAKE_INSTALL_PREFIX "${TOOLCHAIN_PATH}/arm-obreey-linux-gnueabi/sysroot/usr/local" CACHE PATH "Installation Prefix")
set(CMAKE_BUILD_TYPE Release CACHE STRING "Debug|Release|RelWithDebInfo|MinSizeRel")

set(ENV{PKG_CONFIG_DIR} "")
set(ENV{PKG_CONFIG_LIBDIR} ${CMAKE_FIND_ROOT_PATH}/lib/pkgconfig)
set(ENV{PKG_CONFIG_SYSROOT_DIR} ${CMAKE_FIND_ROOT_PATH})
set(ENV{LD_LIBRARY_PATH} ${TOOLCHAIN_PATH}/lib)

list(APPEND PB_LINK_DIRECTORIES "${TOOLCHAIN_PATH}/arm-obreey-linux-gnueabi/sysroot/usr/lib")
list(APPEND PB_LINK_DIRECTORIES "${TOOLCHAIN_PATH}/arm-obreey-linux-gnueabi/sysroot/usr/local/lib")
list(APPEND PB_INCLUDE_DIRECTORIES "${TOOLCHAIN_PATH}/arm-obreey-linux-gnueabi/sysroot/usr/include")

set(SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp 
			${CMAKE_SOURCE_DIR}/src/app.cpp 	
			${CMAKE_SOURCE_DIR}/src/app.h 		
)

add_executable(HelloWorld.app ${SOURCES})


TARGET_LINK_LIBRARIES (HelloWorld.app PRIVATE inkview freetype)

INSTALL (TARGETS HelloWorld.app)

