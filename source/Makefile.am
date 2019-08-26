AUTOMAKE_OPTIONS = subdir-objects
EXTRA_DIST = res/icon32x32.ico res/icon32x32.xpm \
	res/alphabet.xpm res/mpg.xrc
CLEANFILES = res/mpg.cc

bin_PROGRAMS = mpg

mpg_SOURCES = AppConstants.hh \
	MPGApp.cc MPGApp.hh \
	exceptions/InvalidPasswordException.cc \
	exceptions/InvalidPasswordException.hh \
	model/Password.cc model/Password.hh \
	view/MPGFrame.cc view/MPGFrame.hh \
	view/PasswordPanel.cc view/PasswordPanel.hh \
    view/PasswordTextCtrl.cc view/PasswordTextCtrl.hh

nodist_mpg_SOURCES = res/mpg.cc

if WINDOWS
mpg_SOURCES += res/windows.rc
endif

.rc.o:
	windres @WX_INCLUDES@ -o $@ $<

.xrc.cc:
	wxrc -c -o $@ $<

