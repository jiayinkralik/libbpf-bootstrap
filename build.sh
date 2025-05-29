#!/bin/bash
set -e

echo "[*] Building static libbpf..."

cd libbpf/src
make BUILD_STATIC_ONLY=y
make install BUILD_STATIC_ONLY=y LIBDIR=/usr/lib/x86_64-linux-gnu/

echo "[✔] Static libbpf built"

mount -t debugfs none /sys/kernel/debug

echo "[✔] Mounted debugfs"