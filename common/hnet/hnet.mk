.PHONY: all tcp_client tcp_server

TARGET_SET	:= tcp_server

all: $(TARGET_SET)

tcp_client:
	echo -e "$@: $(MAKE)"
	cd tcp_client; $(MAKE)

tcp_server:
	echo -e "$@: $(MAKE)"
	cd tcp_server; $(MAKE)

clean:
	cd $(TARGET_SET); make clean

