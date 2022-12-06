# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-src"
  "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-build"
  "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix"
  "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/tmp"
  "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp"
  "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src"
  "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/albc/Desktop/CSE_335/proj2/Project2/Project2Starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp/${subDir}")
endforeach()
