# GameServer MakeFile

CC	:=	gcc
XX	:=	g++

ROOT_DIR	:= ../
EXT_DIR		:=	$(ROOT_DIR)/ext/
CUR_DIR		:= ./
SRC_DIR		:= $(CUR_DIR)/code
INC_DIR		:= $(CUR_DIR)/code
INC_DIR		+= $(EXT_DIR)/boost_1_56_0/
LIB_DIR		:= ./

LD_LIBS		+= boost_thread boost_system boost_coroutine boost_context boost_chrono boost_regex

APP_TARGET	:= gameserver

C_FLAGS		:= -g
C_FLAGS		+= $(addprefix -I,$(INC_DIR))
LD_FLAGS	+= $(addprefix -L,$(LD_LIBS))

$(APP_TARGET): main.o
	$(XX) $(LD_FLAGS) -o $@ $^

main.o: code/main.cpp
	$(XX) $(C_FLAGS) -c code/main.cpp


.PHONY: clean

clean:
	-rm main.o

