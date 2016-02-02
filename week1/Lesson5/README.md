#const
- part1: const pointer, you can't change the object value through const pointer. But the object itself can be changed. you can
  also change the object value the const pointer points.
- part2: const pointer, you can't change const pointer to point a new address (regular point). But the opposite is ok.
- part3: some function requires not const pointer
- part4: const &, you can't change the object value by changing the const &. But the opposite is ok
