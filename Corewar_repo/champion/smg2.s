.name "smg"
.comment "GET THE FUCK OUT OF HERE"

l1:		fork %8

l2:		st r1, 24
		st r1, 30
		and r1, %0, r2
		st r2, 65515

live:	live %1
		fork %0
		zjmp %:live

live2:	live %1
		and r1, %0, r3
		zjmp %:live2

