#!/bin/bash

SUBDIR="src/net src/util"
SOURCES=`find $SUBDIR -name "*test*.cc" -prune -o -name "*.cc" -print | tr "\n" " "`
BUILD_FILE="build_config.mk"

rm $BUILD_FILE -rf

echo "SOURCE=$SOURCES" >> $BUILD_FILE
