#
# Makefile for the MPEG4 audio Codec
#
# Copyright (C) 2012 Vox Lucida Pty. Ltd., All Rights Reserved
#
# The contents of this file are subject to the Mozilla Public License
# Version 1.0 (the "License"); you may not use this file except in
# compliance with the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
# the License for the specific language governing rights and limitations
# under the License.
#
# The Original Code is Open H323 library.
#
# The Initial Developer of the Original Code is Vox Lucida Pty. Ltd.
#
# Contributor(s): ______________________________________.
#
# $Revision$
# $Author$
# $Date$
#

VC_PLUGIN_DIR=codecs/audio
prefix=/opt/openmcu-ru/lib/ptlib
exec_prefix=${prefix}
target_os=linux-gnu

DL_LIBS =

SHAREDDIR	= shared
PLUGINDIR	= opal
OBJDIR		= obj
WIN32		= no

BASENAME	= ffmpeg
SONAME		= $(BASENAME)

CC	 	=gcc
CXX	 	=g++
LDSO	 	=-shared -Wl,-soname,$(SONAME)
PLUGINEXT	=so
CFLAGS	       +=-g -O2 
STDCCFLAGS	=-fPIC -D__STDC_CONSTANT_MACROS
LDFLAGS	       +=-L/usr/local/ffmpeg-2014/lib -lavcodec -lavutil 
CPPFLAGS       +=-I/usr/local/ffmpeg-2014/include
#LDFLAGS	   +=-L/opt/openmcu-ru/lib -lavcodec -lavutil -pthread
#CPPFLAGS      +=-I/opt/openmcu-ru/include
OPTCCFLAGS     =$(CPPFLAGS)

LIBAVCODEC_CFLAGS=-I${prefix}/include -I.
EXTRACCFLAGS    =  $(LIBAVCODEC_CFLAGS) -I$(PLUGINDIR) -DLIB_DIR='"$(prefix)"' -DVC_PLUGIN_DIR='"$(VC_PLUGIN_DIR)"' -DLICENCE_MPL -D__STDC_CONSTANT_MACROS

vpath	%.cxx $(SHAREDDIR):../common
vpath	%.o   $(OBJDIR)

SRCS    = ffmpeg-audio.cxx 

$(OBJDIR)/%.o : %.cxx
	@mkdir -p $(OBJDIR) >/dev/null 2>&1
	$(CXX) $(EXTRACCFLAGS) $(STDCCFLAGS) $(OPTCCFLAGS) $(CFLAGS) -c $< -o $@

PLUGIN	= ./$(BASENAME)_audio_pwplugin.$(PLUGINEXT)
STATIC	= ./lib$(BASENAME)_audio_s.a

OBJECTS = $(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(patsubst %.cxx,%.o,$(notdir $(SRCS)))))


$(PLUGIN): $(OBJECTS)
	@set -e; $(foreach dir,$(SUBDIRS),if test -d ${dir} ; then $(MAKE) -C $(dir); fi ; )
ifeq (,$(findstring solaris,$(target_os)))
	$(CXX) $(LDSO) $(DL_LIBS) -o $@ $^ $(LDFLAGS)
else
	$(CXX) $(LDSO) $(DL_LIBS) $@ -o $@ $^ $(LDFLAGS)
endif


install:
	@set -e; $(foreach dir,$(SUBDIRS),if test -d ${dir} ; then $(MAKE) -C $(dir) install; fi ; )
	mkdir -p $(DESTDIR)$(prefix)/$(VC_PLUGIN_DIR)
	install $(PLUGIN) $(DESTDIR)$(prefix)/$(VC_PLUGIN_DIR)

uninstall:
	@set -e; $(foreach dir,$(SUBDIRS),if test -d ${dir} ; then $(MAKE) -C $(dir) uninstall; fi ; )
	rm -f $(DESTDIR)$(prefix)/$(VC_PLUGIN_DIR)/$(PLUGIN)

clean:
	rm -f $(OBJECTS) $(PLUGIN)
	@set -e; $(foreach dir,$(SUBDIRS),if test -d ${dir} ; then $(MAKE) -C $(dir) clean; fi ; )

###########################################

