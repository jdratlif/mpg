SUBDIRS = source
EXTRA_DIST = apidocs docs/*.txt Doxyfile \
	vstudio/mpg.sln vstudio/mpg.vcxproj \
	vstudio/mpg.vcxproj.filters vstudio/mpg.vcxproj.user

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
