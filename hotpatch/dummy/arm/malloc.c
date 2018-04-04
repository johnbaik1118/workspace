#define SET_REGS(r, reg, d) ((r).unregs[reg] = (d))

unsigned long syscall_ins = 0xef000000;

SET_REGS(regs, r0, key);
SET_REGS(regs, r1, size);
SET_REGS(regs, r2, flag);
SET_REGS(regs, r3, pid);
SET_REGS(regs, r7,
