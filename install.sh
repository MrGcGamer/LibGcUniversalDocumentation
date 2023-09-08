#!/usr/bin/env bash

# Make sure the THEOS environment variable is set
if [ -z "${THEOS}" ]; then
	echo "THEOS environment variable is missing."
	exit 1
fi

# Exit on error
set -e

# Be verbose
set -v

# Copy the dynamic libraries
rm -f "$THEOS/lib/libgcuniversal.dylib"
mkdir -p "${THEOS}/lib/iphone/rootless"
cp GcUniversal/libgcuniversal.tbd "${THEOS}/lib/"
cp GcUniversal/libgcuniversalrootless.tbd "${THEOS}/lib/iphone/rootless/libgcuniversal.tbd"

# Copy the header files
mkdir -p "${THEOS}/include/GcUniversal"
cp GcUniversal/*.h "${THEOS}/include/GcUniversal/"

# Copy the module map
cp GcUniversal/module.modulemap "${THEOS}/include/GcUniversal/"

# We're done
set +v

echo
echo "Installation successful!"
echo