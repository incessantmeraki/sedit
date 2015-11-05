#!/bin/sh
if [ $#  -eq 0 ] ; then
  echo "Incorrect usage"
  exit 1;
fi
gcc `pkg-config --cflags gtk+-2.0` -o $1 $1.c `pkg-config --libs gtk+-2.0`

