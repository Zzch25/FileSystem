#Zachary Job
#Gsyntax MF

#Bits/getAddr.c Bits/isFile.c Bits/markFile.c \

NAME	=		disk

SRC		=		debug.c \
				\
				\
				../Tree/Manipulate/addChildDir.c ../Tree/Manipulate/addChildFile.c ../Tree/Manipulate/establishRoot.c \
				../Tree/Manipulate/updateParentDir.c ../Tree/Manipulate/updateParentFile.c ../Tree/Manipulate/killChildFile.c \
				../Tree/Manipulate/killChildDir.c ../Tree/Manipulate/freeNodes.c ../Tree/Manipulate/freeFiles.c \
				../Tree/Manipulate/killFS.c \
				\
				\
				../Tree/Traverse/backUp.c ../Tree/Traverse/handleFile.c ../Tree/Traverse/handleDir.c ../Tree/Traverse/seekName.c \
				../Tree/Traverse/printDir.c ../Tree/Traverse/printTree.c \
				\
				\
				../Tree/Stack/createStack.c ../Tree/Stack/dequeue.c ../Tree/Stack/enqueue.c ../Tree/Stack/peek.c ../Tree/Stack/peekVisV.c\
				../Tree/Stack/createStackV.c ../Tree/Stack/dequeueV.c ../Tree/Stack/enqueueV.c ../Tree/Stack/peekV.c ../Tree/Stack/upV.c \
				\
				\
				../File/Infoseek/fileData.c ../File/Infoseek/mapPrint.c \
				\
				\
				../File/Manage/initializeFile.c ../File/Manage/killFile.c ../File/Manage/freeMap.c \
				\
				\
				Infoseek/blockData.c Infoseek/fragmentation.c \
				\
				\
				Manage/freeBlocks.c Manage/initializeDisk.c Manage/killDisk.c \
				\
				\
				Update/freeDisk.c Update/toDisk.c Update/unifyLeft.c Update/unifyRight.c \
				Update/append.c Update/lessen.c Update/split.c Update/insertHole.c
				
RM		=		rm -f

all: fsdisk

clean:
	-$(RM) *.o

fclean: clean
	-$(RM) *.exe

re: fclean all

fsdisk:
	gcc -std=c99 -Wall -pedantic-errors $(SRC) -o $(NAME)