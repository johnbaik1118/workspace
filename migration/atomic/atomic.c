typdef struct {
	volatile int counter;
} atomic_t;

#define atomic_read(v)		((v)->counter)


