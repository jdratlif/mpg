# $Id: Makefile.am,v 1.6 2008/12/17 00:13:31 jdratlif Exp $

SUBDIRS = source
EXTRA_DIST = apidocs docs/*.txt Doxyfile \
	vstudio/mpg/mpg.sln vstudio/mpg/mpg.vcproj

.PHONY: allclean apidocs bundle touch

allclean: clean
	-rm -rf source/mpg.app
	-rm -rf apidocs
	-rm -f *.bz2
	-find -iname "*~" -exec rm -f {} \;

apidocs: Doxyfile
	@doxygen

bundle:
	-cd source && make mpg.app

touch:
	-find -iname "*.cc" -exec touch {} \;
	-find -iname "*.hh" -exec touch {} \;
	-find -iname "*.xrc" -exec touch {} \;

