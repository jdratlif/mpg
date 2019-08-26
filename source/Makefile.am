# $Id: Makefile.am,v 1.9 2008/12/17 00:13:31 jdratlif Exp $

AUTOMAKE_OPTIONS = subdir-objects
CLEANFILES = res/mpg.cc
EXTRA_DIST = res/alphabet.xpm res/icon32x32.ico res/icon32x32.xpm \
	res/mpg.icns res/mpg.xrc res/Info.plist res/windows.rc

bin_PROGRAMS = mpg

mpg_SOURCES = AppConstants.hh \
	MPGApp.cc MPGApp.hh \
	exceptions/InvalidPasswordException.cc \
	exceptions/InvalidPasswordException.hh \
	model/Password.cc model/Password.hh \
	res/mpg.cc \
	view/MPGFrame.cc view/MPGFrame.hh \
	view/PasswordPanel.cc view/PasswordPanel.hh \
	view/PasswordTextCtrl.cc view/PasswordTextCtrl.hh

if WINDOWS
mpg_SOURCES += res/windows.rc
endif

.rc.o:
	windres @WX_INCLUDES@ -o $@ $<

.xrc.cc:
	wxrc -c -o $@ $<

mpg.app: mpg res/mpg.icns res/Info.plist
	-mkdir mpg.app
	-mkdir mpg.app/Contents
	-mkdir mpg.app/Contents/MacOS
	-mkdir mpg.app/Contents/Resources
	cp mpg mpg.app/Contents/MacOS
	cp res/Info.plist mpg.app/Contents
	cp res/mpg.icns mpg.app/Contents/Resources
	echo -n 'APPL????' > mpg.app/Contents/PkgInfo

