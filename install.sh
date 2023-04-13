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
rm "$THEOS/lib/libgcuniversal.dylib"
cp GcUniversal/*.tbd "${THEOS}/lib/"
cp GcUniversal/*.tbd "${THEOS}/lib/iphone/rootless/"

# Copy the header files
mkdir -p "${THEOS}/include/GcUniversal"
cp GcUniversal/*.h "${THEOS}/include/GcUniversal/"

# We're done
set +v

echo
echo "Installation successful!"
echo