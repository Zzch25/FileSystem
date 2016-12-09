#Zachary Job
#Gsyntax MF

#Bits/getAddr.c Bits/isFile.c Bits/markFile.c \

NAME	=		tree
SRC		=		debug.c \
				\
				\
				Manipulate/addChildDir.c Manipulate/addChildFile.c Manipulate/establishRoot.c \
				Manipulate/updateParentDir.c Manipulate/updateParentFile.c Manipulate/killChildFile.c \
				Manipulate/killChildDir.c Manipulate/freeNodes.c Manipulate/freeFiles.c \
				Manipulate/killFS.c \
				\
				\
				Traverse/backUp.c Traverse/handleFile.c Traverse/handleDir.c Traverse/seekName.c \
				Traverse/printDir.c Traverse/printTree.c \
				\
				\
				Stack/createStack.c Stack/dequeue.c Stack/enqueue.c Stack/peek.c Stack/peekVisV.c\
				Stack/createStackV.c Stack/dequeueV.c Stack/enqueueV.c Stack/peekV.c Stack/upV.c \
				\
				\
				../File/Infoseek/fileData.c ../File/Infoseek/mapPrint.c \
				\
				\
				../File/Manage/initializeFile.c ../File/Manage/killFile.c ../File/Manage/freeMap.c \
				\
				\
				../Disk/Infoseek/blockData.c ../Disk/Infoseek/fragmentation.c \
				\
				\
				../Disk/Manage/freeBlocks.c ../Disk/Manage/initializeDisk.c ../Disk/Manage/killDisk.c \
				\
				\
				../Disk/Update/freeDisk.c ../Disk/Update/toDisk.c ../Disk/Update/unifyLeft.c ../Disk/Update/unifyRight.c \
				../Disk/Update/append.c ../Disk/Update/lessen.c ../Disk/Update/split.c ../Disk/Update/insertHole.c
				
RM		=		rm -f

all: fstree

clean:
	-$(RM) *.o

fclean: clean
	-$(RM) *.exe

re: fclean all

fstree:
	gcc -std=c99 -Wall -pedantic-errors $(SRC) -o $(NAME)