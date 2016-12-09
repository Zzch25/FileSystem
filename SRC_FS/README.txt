Zachary Job

BEWARE...


A) it is designed to the files included in _tests

B) There is a small leak in the file load. For some reason I cannot find where I may have assigned
   maybe a pointer value to a stack value or anything of the nature. IT is bizzare. Also there really
   isn't time now for me to work on this so I have to call it. However!!!
   
   <<< ..EVERYTHING works.. >>>
   
   Just that is the only issue. It occurs within h_init before the call toFS. The error can be eliminated by
   killing the calls to the file loader.


A NOTE:

The professor gave me the go ahead to build my custom allocator. IT has one issue mentioned below however its not a bug its
a lack of a final step.

ANOTHER NOTE:

It is physically impossible to document the code in a week, nor do I expect anyone to understand it in up to two weeks.
I leave this document alone for these purposes.

TO BUILD
Make: make

TO USE
Followed the specifications



THE ALLOCATOR.

It was supposed to be fully implemented. IT is a hole block system with alignment via sticky bits. It should make second passes to rectify bytes that cannot
move once they are pushed through a wait queue. The file system took away from finishing this however the allocator works. 
Just with some unmoveable fragmentation at the end that could be literally swept away with one pass, again... Stupid file system.

How it works. It aligns memory to block boundaries. If a bit overflows it is locked to a block. The system unifies memory left and right if two pieces
are a whole and block. It then propagates the memory for faster seeks and less memory to store these disk locations. File's overflowed chunk maps and locations are 
enqueued for shifting. This happens after three sticky bits enter the queue pushing one out. I did not get to implement the dequeue re enqueue part hence the end frag.