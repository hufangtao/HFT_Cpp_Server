# MakeFile Boost Include
ifndef BOOST_1_56_0_INC
	BOOST_1_56_0_INC = true
	ifdef EXT_DIR
		CUR_DIR := $(EXT_DIR)/boost_1_56_0
		INC_DIR += $(CUR_DIR)/
		LIB_DIR += $(CUR_DIR)/stage/lib/
	endif
endif

