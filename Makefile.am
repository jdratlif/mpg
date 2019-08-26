SUBDIRS = source
EXTRA_DIST = apidocs docs/*.txt DialogBlocks/mpg.pjd Doxyfile TODO Info.plist

allclean: clean
	-rm -rf apidocs
	-rm -f *.bz2 *.gz
	-find -iname "*~" -exec rm -f {} \;

.PHONY: apidocs
apidocs: Doxyfile
	@doxygen

