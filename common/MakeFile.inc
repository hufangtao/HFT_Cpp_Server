ifndef COMMON_INC
	COMMON_INC = true

	CUR_DIR = ${ROOT_DIR}/common
	INC_DIR += ${CUR_DIR}/code
	LIB_DIR += ${CUR_DIR}/lib

	ifdef LD_LIBS
		LD_LIBS += common
	endif
endif
