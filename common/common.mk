.PHONY: all hnet hdb

TARGET_SET	:= hnet hdb

all: $(TARGET_SET)

hnet:
	echo -e "$@: $(MAKE)"
	cd hnet; $(MAKE)

hdb:
	echo -e "$@: $(MAKE)"
	cd hdb; $(MAKE)

clean:
	cd $(TARGET_SET); make clean

