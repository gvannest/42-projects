.name "load and store for test"
.comment "just a basic living prog which loads and stores"

	ld %30,r5
	ld 1,r7
	st r1,6
	live %1
	st r5,r6
	st r5,40
	st r6,50
	st r7,60
