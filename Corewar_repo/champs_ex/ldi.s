.name "Vas y jump!"
.comment "just a basic living prog which jumps like never"

	ld %5,r5
	ld 65531,r7
	ld %3,r2
	and r1,r5,r6
	ldi r2,r5,r8
	ldi %5,r2,r9
	live %1
	ldi %6,%8,r10
	ldi 6,r9,r11
	st r8,50
	st r9,60
	st r10,70
	st r11,80
