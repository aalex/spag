#!/bin/bash
libtoolize --force
aclocal -I m4
#aclocal      # create aclocal.m4 - only needed once 
autoheader
automake -a -f --add-missing
#automake -a  # create Makefile.in - only needed once 
#autoconf     # create configure - only needed once 
autoconf -f

