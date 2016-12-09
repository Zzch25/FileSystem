#Zachary Job
#Gsyntax MF

#Bits/getAddr.c Bits/isFile.c Bits/markFile.c \

NAME	=		file

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
				Infoseek/fileData.c Infoseek/mapPrint.c \
				\
				\
				Manage/initializeFile.c Manage/killFile.c Manage/freeMap.c \
				\
				\
				../Disk//Infoseek/blockData.c ../Disk//Infoseek/fragmentation.c \
				\
				\
				../Disk//Manage/freeBlocks.c ../Disk//Manage/initializeDisk.c ../Disk//Manage/killDisk.c \
				\
				\
				../Disk//Update/freeDisk.c ../Disk//Update/toDisk.c ../Disk//Update/unifyLeft.c ../Disk//Update/unifyRight.c \
				../Disk//Update/append.c ../Disk//Update/lessen.c ../Disk//Update/split.c ../Disk//Update/insertHole.c
				
RM		=		rm -f

all: fsfile

clean:
	-$(RM) *.o

fclean: clean
	-$(RM) *.exe

re: fclean all

fsfile:
	gcc -std=c99 -Wall -pedantic-errors $(SRC) -o $(NAME)