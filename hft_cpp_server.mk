all: common gameserver

common:
	echo -e "$@: $(MAKE)"
	cd common; $(MAKE)

gameserver:
	echo -e "$@: $(MAKE)"
	cd gameserver; $(MAKE)
