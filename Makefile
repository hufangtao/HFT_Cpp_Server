include ./make_inc.mk

.PHONY: gameserver

MK_FILE	:= hft_cpp_server.mk
TARGET_SET		:= gameserver

all:
	@echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@

$(TARGET_SET):
	@echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@

clean:
	$(MAKE) -f $(MK_FILE) $@

