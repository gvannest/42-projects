.name "load and store for test"
.comment "just a basic living prog which loads and stores"

	lld 4096,r5
	ld %49,r7
	ld %351,r8
	st r1,30
	st r5,r6
	st r5,40
	st r7,50
	st r8,60
	aff r7
	aff r8
