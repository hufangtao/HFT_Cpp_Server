ifndef BOOST_INC
	BOOST_INC = true

	ifdef EXT_DIR
		CUR_DIR = ${EXT_DIR}/boost
		INC_DIR += ${CUR_DIR}/include
		LIB_DIR += ${CUR_DIR}/lib
	endif
endif
