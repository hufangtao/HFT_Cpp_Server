.PHONY: all common gameserver

TARGET_SET	:= common gameserver client

all: $(TARGET_SET)

common:
	echo -e "$@: $(MAKE)"
	cd common; $(MAKE)

gameserver:
	echo -e "$@: $(MAKE)"
	cd gameserver; $(MAKE)

client:
	echo -e "$@: $(MAKE)"
	cd client; $(MAKE)

clean:
	cd $(TARGET_SET); make clean

