EXEC     = demo1_pid_ppid_uid demo2_fork demo3_wait demo4_wait demo5_environ demo6_exit demo7_exec demo8_exec demo9_signal demo10_waitpid demo11_waitpid demo12_kill demo13_alarm
CC       = LC_MESSAGES=C gcc

CFLAGS   = -Wall# -Wextra -Wpedantic -Wstrict-aliasing

all: $(EXEC)

$(EXEC): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	@rm -rf $(EXEC)
