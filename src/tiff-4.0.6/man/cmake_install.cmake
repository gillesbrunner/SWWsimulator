# Install script for directory: /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/man/man1/bmp2tiff.1;/usr/local/share/man/man1/fax2ps.1;/usr/local/share/man/man1/fax2tiff.1;/usr/local/share/man/man1/gif2tiff.1;/usr/local/share/man/man1/pal2rgb.1;/usr/local/share/man/man1/ppm2tiff.1;/usr/local/share/man/man1/ras2tiff.1;/usr/local/share/man/man1/raw2tiff.1;/usr/local/share/man/man1/rgb2ycbcr.1;/usr/local/share/man/man1/sgi2tiff.1;/usr/local/share/man/man1/thumbnail.1;/usr/local/share/man/man1/tiff2bw.1;/usr/local/share/man/man1/tiff2pdf.1;/usr/local/share/man/man1/tiff2ps.1;/usr/local/share/man/man1/tiff2rgba.1;/usr/local/share/man/man1/tiffcmp.1;/usr/local/share/man/man1/tiffcp.1;/usr/local/share/man/man1/tiffcrop.1;/usr/local/share/man/man1/tiffdither.1;/usr/local/share/man/man1/tiffdump.1;/usr/local/share/man/man1/tiffgt.1;/usr/local/share/man/man1/tiffinfo.1;/usr/local/share/man/man1/tiffmedian.1;/usr/local/share/man/man1/tiffset.1;/usr/local/share/man/man1/tiffsplit.1;/usr/local/share/man/man1/tiffsv.1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/man/man1" TYPE FILE FILES
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/bmp2tiff.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/fax2ps.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/fax2tiff.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/gif2tiff.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/pal2rgb.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/ppm2tiff.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/ras2tiff.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/raw2tiff.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/rgb2ycbcr.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/sgi2tiff.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/thumbnail.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiff2bw.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiff2pdf.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiff2ps.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiff2rgba.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffcmp.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffcp.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffcrop.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffdither.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffdump.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffgt.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffinfo.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffmedian.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffset.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffsplit.1"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/tiffsv.1"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/man/man3/libtiff.3tiff;/usr/local/share/man/man3/TIFFbuffer.3tiff;/usr/local/share/man/man3/TIFFClose.3tiff;/usr/local/share/man/man3/TIFFcodec.3tiff;/usr/local/share/man/man3/TIFFcolor.3tiff;/usr/local/share/man/man3/TIFFDataWidth.3tiff;/usr/local/share/man/man3/TIFFError.3tiff;/usr/local/share/man/man3/TIFFFieldDataType.3tiff;/usr/local/share/man/man3/TIFFFieldName.3tiff;/usr/local/share/man/man3/TIFFFieldPassCount.3tiff;/usr/local/share/man/man3/TIFFFieldReadCount.3tiff;/usr/local/share/man/man3/TIFFFieldTag.3tiff;/usr/local/share/man/man3/TIFFFieldWriteCount.3tiff;/usr/local/share/man/man3/TIFFFlush.3tiff;/usr/local/share/man/man3/TIFFGetField.3tiff;/usr/local/share/man/man3/TIFFmemory.3tiff;/usr/local/share/man/man3/TIFFOpen.3tiff;/usr/local/share/man/man3/TIFFPrintDirectory.3tiff;/usr/local/share/man/man3/TIFFquery.3tiff;/usr/local/share/man/man3/TIFFReadDirectory.3tiff;/usr/local/share/man/man3/TIFFReadEncodedStrip.3tiff;/usr/local/share/man/man3/TIFFReadEncodedTile.3tiff;/usr/local/share/man/man3/TIFFReadRawStrip.3tiff;/usr/local/share/man/man3/TIFFReadRawTile.3tiff;/usr/local/share/man/man3/TIFFReadRGBAImage.3tiff;/usr/local/share/man/man3/TIFFReadRGBAStrip.3tiff;/usr/local/share/man/man3/TIFFReadRGBATile.3tiff;/usr/local/share/man/man3/TIFFReadScanline.3tiff;/usr/local/share/man/man3/TIFFReadTile.3tiff;/usr/local/share/man/man3/TIFFRGBAImage.3tiff;/usr/local/share/man/man3/TIFFSetDirectory.3tiff;/usr/local/share/man/man3/TIFFSetField.3tiff;/usr/local/share/man/man3/TIFFsize.3tiff;/usr/local/share/man/man3/TIFFstrip.3tiff;/usr/local/share/man/man3/TIFFswab.3tiff;/usr/local/share/man/man3/TIFFtile.3tiff;/usr/local/share/man/man3/TIFFWarning.3tiff;/usr/local/share/man/man3/TIFFWriteDirectory.3tiff;/usr/local/share/man/man3/TIFFWriteEncodedStrip.3tiff;/usr/local/share/man/man3/TIFFWriteEncodedTile.3tiff;/usr/local/share/man/man3/TIFFWriteRawStrip.3tiff;/usr/local/share/man/man3/TIFFWriteRawTile.3tiff;/usr/local/share/man/man3/TIFFWriteScanline.3tiff;/usr/local/share/man/man3/TIFFWriteTile.3tiff")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/man/man3" TYPE FILE FILES
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/libtiff.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFbuffer.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFClose.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFcodec.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFcolor.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFDataWidth.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFError.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFFieldDataType.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFFieldName.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFFieldPassCount.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFFieldReadCount.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFFieldTag.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFFieldWriteCount.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFFlush.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFGetField.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFmemory.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFOpen.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFPrintDirectory.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFquery.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadDirectory.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadEncodedStrip.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadEncodedTile.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadRawStrip.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadRawTile.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadRGBAImage.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadRGBAStrip.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadRGBATile.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadScanline.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFReadTile.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFRGBAImage.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFSetDirectory.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFSetField.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFsize.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFstrip.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFswab.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFtile.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWarning.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWriteDirectory.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWriteEncodedStrip.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWriteEncodedTile.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWriteRawStrip.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWriteRawTile.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWriteScanline.3tiff"
    "/home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/man/TIFFWriteTile.3tiff"
    )
endif()

