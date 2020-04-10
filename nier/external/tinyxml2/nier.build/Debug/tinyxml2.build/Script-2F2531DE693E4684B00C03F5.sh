#!/bin/sh
make -C /Users/junho/Desktop/automata/nier/external/tinyxml2 -f /Users/junho/Desktop/automata/nier/external/tinyxml2/CMakeScripts/tinyxml2_postBuildPhase.make$CONFIGURATION OBJDIR=$(basename "$OBJECT_FILE_DIR_normal") all
