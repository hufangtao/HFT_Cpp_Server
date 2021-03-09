ifndef CURL_INC
	CURL_INC = true

	ifdef EXT_DIR
		CUR_DIR = ${EXT_DIR}/curl
		INC_DIR += ${CUR_DIR}/include
		LIB_DIR += ${CUR_DIR}/lib
	endif
	
	ifdef LD_LIBS
		LD_LIBS += curl
	endif
endif
