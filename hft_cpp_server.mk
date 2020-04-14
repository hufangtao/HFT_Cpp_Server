.PHONY: all common gameserver

TARGET_SET	:= gameserver

all: $(TARGET_SET)

common:
	echo -e "$@: $(MAKE)"
	cd common; $(MAKE)

gameserver:
	echo -e "$@: $(MAKE)"
	cd gameserver; $(MAKE)

clean:
	cd $(TARGET_SET); make clean

