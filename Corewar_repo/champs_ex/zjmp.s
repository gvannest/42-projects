.name "Vas y jump!"
.comment "just a basic living prog which jumps like never"

	ld %30,r5
	ld 1,r7
	and 0,r5,r6
	st r5,50
	st r6,80
	zjmp %33277
	st r1,0
	xor r1,33277,r9
	st r9,60
