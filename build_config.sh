#!/bin/bash

SUBDIR="src/net src/util"
SOURCES=`find $SUBDIR -name "*.cc" | tr "\n" " "`
BUILD_FILE="build_config.mk"

rm $BUILD_FILE -rf

echo "SOURCE=$SOURCES" >> $BUILD_FILE
