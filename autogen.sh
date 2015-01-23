#!/bin/sh

echo "Generating build scripts..."
aclocal
autoconf
automake --add-missing --copy

top_srcdir=`pwd`

if [ -d ${top_srcdir}/plugins/G722.1/libg722_1 ] ; then
  cd ${top_srcdir}/plugins/G722.1/libg722_1/ && ./autogen.sh
fi
