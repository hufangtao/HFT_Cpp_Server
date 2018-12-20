SHELL := /bin/bash
CC := g++
OBJECTS = main.o

HFT_Server : $(OBJECTS)
	cc -o HFT_Server $(OBJECTS)

$(OBJECTS):

help:
	@echo "帮助："
	@echo " make data "
	@echo $(OBJECTS)
	@echo "		DATATYPE=type - 表示仅仅生成指定类型的数据 "
	@echo ""
.PHONY : clean
clean:
	-rm HFT_Server $(OBJECTS)
