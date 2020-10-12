# GameServer MakeFile

CC	:=	gcc
XX	:=	g++

ROOT_DIR	:= ../
EXT_DIR		:= $(ROOT_DIR)/ext/
CUR_DIR		:= ./
SRC_DIR		:= $(CUR_DIR)/code
INC_DIR		:= $(CUR_DIR)/code
LIB_DIR		:= ./

LD_LIBS		+= boost_thread boost_system boost_coroutine boost_context boost_chrono boost_regex pthread

APP_TARGET	:= gameserver

include $(EXT_DIR)/boost/MakeFile.inc
include $(ROOT_DIR)/common/MakeFile.inc

C_FLAGS		:= -g -Wall -Werror -O0 -std=c++17
C_FLAGS		+= $(addprefix -I,$(INC_DIR))
LD_FLAGS	+= $(addprefix -L,$(LIB_DIR)) $(addprefix -l, $(LD_LIBS))
LIB_DIR_SH  += $(shell echo "$(LIB_DIR)"| sed -e "s/ \./:\./g")

SOURCE_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
ALL_PROJECTS := $(SOURCE_FILES:.cpp=.o)

$(APP_TARGET): $(ALL_PROJECTS)
	@echo "C_FLAGS:"$(C_FLAGS)
	@echo "SOURCE_FILES:"$(SOURCE_FILES)
	@echo "ALL_PROJECTS:"$(ALL_PROJECTS)
	@echo -e "\033[36m[$(APP_TARGET) LINK] $@\033[0m"
	$(XX) $(ALL_PROJECTS) $(LD_FLAGS) -o $@
	export LD_LIBRARY_PATH=$(LIB_DIR_SH)

%.o:%.cpp
	$(XX) $(C_FLAGS) -c $< -o $@

lib:
	export LD_LIBRARY_PATH=$(LIB_DIR_SH)

.PHONY: gameserver clean

clean:
	-rm $(ALL_PROJECTS)

