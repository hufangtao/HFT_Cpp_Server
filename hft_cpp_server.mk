.PHONY: all common gameserver

TARGET_SET	:= common gameserver client

all: $(TARGET_SET)

common:
	@echo -e "$@: $(MAKE)"
	cd common; $(MAKE)

gameserver: common
	@echo -e "$@: $(MAKE)"
	cd gameserver; $(MAKE)

client: common
	@echo -e "$@: $(MAKE)"
	cd client; $(MAKE)

clean:
	cd common; make clean
	cd gameserver; make clean
	cd client; make clean

