# COMMON MakeFile

CC	:=	gcc
XX	:=	g++

ROOT_DIR	:= ../
EXT_DIR		:=	$(ROOT_DIR)/ext/
CUR_DIR		:= ./
SRC_DIR		:= $(CUR_DIR)/code
INC_DIR		:= $(CUR_DIR)/code
LIB_DIR		:= ./

LD_LIBS		+= boost_thread boost_system boost_coroutine boost_context boost_chrono boost_regex

APP_TARGET	:= gameserver

include $(EXT_DIR)/boost_1_56_0/MakeFile.inc

C_FLAGS		:= -g -Wall -Werror -O0 -std=c++0x
C_FLAGS		+= $(addprefix -I,$(INC_DIR))
LD_FLAGS	+= $(addprefix -L,$(LIB_DIR)) $(addprefix -l, $(LD_LIBS))
LIB_DIR_SH  += $(shell echo "$(LIB_DIR)"| sed -e "s/ \./:\./g")

$(APP_TARGET): main.o player.o
	@echo -e "\033[36m[$(APP_TARGET) LINK] $@\033[0m"
	@$(XX) $(LD_FLAGS) -o $@ $^
	export LD_LIBRARY_PATH=$(LIB_DIR_SH)

main.o: code/main.cpp
	$(XX) $(C_FLAGS) -c code/main.cpp

player.o: code/player.h code/player.cpp
	$(XX) $(C_FLAGS) -c code/player.cpp

lib:
	export LD_LIBRARY_PATH=$(LIB_DIR_SH)

.PHONY: clean

clean:
	-rm *.o

