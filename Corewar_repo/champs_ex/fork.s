.name "Vas y fork!"
.comment "just a basic living prog which jumps like never"

	ld %50,r5
	ld 65531,r7
	fork %5
	live %1
	ld %2,r2
	and r1,1,r6
	fork %65531
	sti r2,r5,%500
	live %-1
	ldi %6,%8,r10
	sti r7,15,r5
	live %1
	sti r10,65531,%4
	sti r5,r6,r7
