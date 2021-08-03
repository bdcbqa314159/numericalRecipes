#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/Debug/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/Debug/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/Debug/libnumRec.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/Release/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/Release/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/Release/libnumRec.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/MinSizeRel/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/MinSizeRel/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/MinSizeRel/libnumRec.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode
  /usr/local/Cellar/cmake/3.20.5/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/RelWithDebInfo/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/RelWithDebInfo/libnumRec.dylib /Users/bernardocohen/repos/numericalRecipes/cpp/Xcode/RelWithDebInfo/libnumRec.dylib
fi

