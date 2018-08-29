.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, 3, r1
		and r1, %0, r2

live:	live %1
		and r1, %12, r3
		zjmp %:live
