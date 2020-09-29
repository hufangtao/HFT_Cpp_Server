#	MakeFile

#
#	路径定义
#
CUR_DIR		:= ./
ROOT_DIR	:= ../../../
EXT_DIR		:= ROOT_DIR/ext
TARGET_LIB_DIR	:= $(CUR_DIR)/lib/
INC_DIR		:= $(CUR_DIR)/code
INC_DIR		+= $(CUR_DIR)
SRC_DIR		:= $(CUR_DIR)/code

#
#	依赖模块
#
include $(EXT_DIR)/boost_1_56_0/MakeFile.inc


#
#	所需编译的源文件
#
ALL_DIRS	:= $(shell find $(SRC_DIR) -maxdepth 3 -type d)
SRC_FILES	:= $(foreach dir,$(ALL_DIRS),$(wildcard $(dir)/*.cpp))
OBJ_FILES	:= $(SRC_FILES:.cpp=.o)
DEP_FILES	:= $(foreach obj, $(OBJ_FILES), $(obj).dep)

#
#	目标模块
#
LIB_NAME	:= tcp_server
SO_TARGET	:= $(TARGET_LIB_DIR)/lib$(LIB_NAME).a

#
#	编译配置
#
C_FLAGS		:= -g -pipe -W -Wall -Werror -fPIC -O -rdynamic -std=c++0x
C_FLAGS		+= $(addprefix -I, $(INC_DIR))
LD_FLAGS	:= $(addprefix -L, $(LIB_DIR)) $(addprefix -l, $(LD_LIBS))
LIB_DIR_SH	:= $(shell echo "$(LIB_DIR)"| sed -e "s/ \./:\./g")

all: $(SO_TARGET)
	@echo -e "\033[36m======== build $(LIB_NAME) succ ========\033[0m"

$(SO_TARGET): $(ALL_BUILD_OBJ)
	ar -r $@ $^

$(ALL_BUILD_OBJ): 
