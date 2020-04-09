MK_FILE	:= hft_cpp_server.mk

JOBS_NUM		:= 12
MAKE			:= make
PARALLEL_PARAM	:= -j $(JOBS_NUM)

all:
	echo -e "$@: $(MAKE) $(PARALLEL_PARAM)"
	$(MAKE) $(PARALLEL_PARAM) -f $(MK_FILE) $@