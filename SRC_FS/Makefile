#Zachary Job
#Gsyntax MF

#Bits/getAddr.c Bits/isFile.c Bits/markFile.c \

NAME	=		fs
SRC		=		mgr.c \
				\
				\
				CLI/Mains/runHandler.c CLI/Mains/checkInput.c CLI/Mains/getCMD.c CLI/Mains/getARGS.c \
				\
				\
				CLI/Handlers/h_cd.c CLI/Handlers/h_ls.c CLI/Handlers/h_mkdir.c CLI/Handlers/h_create.c \
				CLI/Handlers/h_append.c CLI/Handlers/h_remove.c CLI/Handlers/h_delete.c CLI/Handlers/h_exit.c \
				CLI/Handlers/h_dir.c CLI/Handlers/h_prfiles.c CLI/Handlers/h_prdisk.c CLI/Handlers/h_init.c \
				\
				\
				Tree/Manipulate/addChildDir.c Tree/Manipulate/addChildFile.c Tree/Manipulate/establishRoot.c \
				Tree/Manipulate/updateParentDir.c Tree/Manipulate/updateParentFile.c Tree/Manipulate/killChildFile.c \
				Tree/Manipulate/killChildDir.c Tree/Manipulate/freeNodes.c Tree/Manipulate/freeFiles.c \
				Tree/Manipulate/killFS.c \
				\
				\
				Tree/Traverse/backUp.c Tree/Traverse/handleFile.c Tree/Traverse/handleDir.c Tree/Traverse/seekName.c \
				Tree/Traverse/printDir.c Tree/Traverse/printTree.c Tree/Traverse/printFiles.c \
				\
				\
				Tree/Stack/createStack.c Tree/Stack/dequeue.c Tree/Stack/enqueue.c Tree/Stack/peek.c Tree/Stack/peekVisV.c\
				Tree/Stack/createStackV.c Tree/Stack/dequeueV.c Tree/Stack/enqueueV.c Tree/Stack/peekV.c Tree/Stack/upV.c \
				\
				\
				Disk/Infoseek/blockData.c \
				\
				\
				Disk/Manage/freeBlocks.c Disk/Manage/initializeDisk.c Disk/Manage/killDisk.c \
				\
				\
				Disk/Update/freeDisk.c Disk/Update/toDisk.c Disk/Update/unifyLeft.c Disk/Update/unifyRight.c \
				Disk/Update/append.c Disk/Update/lessen.c Disk/Update/split.c Disk/Update/insertHole.c \
				\
				\
				File/Infoseek/fileData.c File/Infoseek/mapPrint.c \
				\
				\
				File/Manage/initializeFile.c File/Manage/killFile.c File/Manage/freeMap.c \
				\
				\
				Loader/Manage/toMemory.c Loader/Manage/toFS.c Loader/Manage/preProc.c Loader/Manage/getSZ.c Loader/Manage/procFile.c
				
RM		=		rm -f

all: filesystem

clean:
	-$(RM) *.o

fclean: clean
	-$(RM) *.exe

re: fclean all

filesystem:
	gcc -std=c99 -g -Wall -pedantic-errors $(SRC) -o $(NAME)