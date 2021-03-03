include ./make_inc.mk

.PHONY: gameserver

MK_FILE	:= hft_cpp_server.mk

all:
	@echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@

gameserver:
	@echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@

client:
	@echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@

clean:
	$(MAKE) -f $(MK_FILE) $@

