// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright (c) 2020 Facebook */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "Dual BSD/GPL";

int my_pid = 0;

SEC("tp/syscalls/sys_enter_write")
int handle_tp(void *ctx)
{
	// int pid = bpf_get_current_pid_tgid() >> 32;

	// if (pid != my_pid)
	// 	return 0;

	// bpf_printk("BPF triggered from PID %d.\n", pid);

	// return 0;

	// a simple ALU64 operation
	volatile __u64 a = 100;
    volatile __u64 b = 200;
    __u64 sum = a + b;

	// triggering arsh
	volatile __s64 val = -1024;  // signed 64-bit integer
    val = val >> 3;             // this triggers ARSH

    return sum; 
}
