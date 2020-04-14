include ../../make_inc.mk

MK_FILE	:= hnet.mk
TARGET_SET		:= tcp_client tcp_server

all:
	@echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@

$(TARGET_SET):
	@echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@

clean:
	$(MAKE) -f $(MK_FILE) $@

