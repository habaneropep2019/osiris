# -*- makefile -*-
#
# Main Makefile for building the Qt library, examples and tutorial.
# Read PORTING for instructions how to port Qt to a new platform.


all:  moc src util tutorial examples
	@echo
	@echo "The Qt library is now built in ./lib"
	@echo "The Qt examples are built in the directories in ./examples"
	@echo "The Qt tutorials are built in the directories in ./tutorial"
	@echo
	@echo "Enjoy!   - the Troll Tech team"
	@echo

moc: .buildopts FORCE
	cd src/moc; $(MAKE)
	cp src/moc/moc bin/moc

util: mergetr msg2qm

mergetr: src FORCE
	cd src/util/mergetr; $(MAKE)
	cp src/util/mergetr/mergetr bin/mergetr
	
msg2qm: src FORCE
	cd src/util/msg2qm; $(MAKE)
	cp src/util/msg2qm/msg2qm bin/msg2qm
	
symlinks:
	@cd include; rm -f q*.h; ln -s ../src/*/q*.h .

src: moc .buildopts FORCE
	cd $@; $(MAKE)

tutorial examples: src FORCE
	cd $@; $(MAKE)

clean:
	-rm .buildopts
	cd src/moc; $(MAKE) clean
	cd src; $(MAKE) clean
	cd tutorial; $(MAKE) clean
	cd examples; $(MAKE) clean

depend:
	cd src; $(MAKE) depend
	cd tutorial; $(MAKE) depend
	cd examples; $(MAKE) depend

.buildopts: Makefile
	@echo
	@echo '  You must run the configure script before you can build Qt.'
	@echo
	@echo '  The make process will now abort with an error.'
	@echo
	@exit 1

dep: depend

FORCE:


